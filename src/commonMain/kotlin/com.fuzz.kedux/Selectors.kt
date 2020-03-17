package com.fuzz.kedux

import kotlinx.atomicfu.atomic
import kotlinx.coroutines.ExperimentalCoroutinesApi
import kotlinx.coroutines.channels.*
import kotlinx.coroutines.launch
import kotlin.experimental.ExperimentalTypeInference

typealias Selector<S, R> = (state: S) -> R

typealias StoreLogger = (() -> String) -> Unit

@ExperimentalCoroutinesApi
class SelectorClass<S, R> internal constructor(
    private val storeLogger: StoreLogger,
    private val selector: Selector<S, R>
) {
    private val previousValue = atomic<S?>(null)
    private val previousSelectorValue = atomic<R?>(null)

    fun consumeState(latest: S): R {
        storeLogger { "selector -> previous ${previousValue.value} : latest $latest" }
        storeLogger { "selector -> previous == latest ${previousValue.value == latest}" }
        if (latest != previousValue.getAndSet(latest)) {
            val value = selector(latest)
            previousSelectorValue.value = value
            storeLogger { "selector -> RECOMPUTE $value" }
            return value
        } else {
            storeLogger { "selector -> UNCHANGED ${previousSelectorValue.value}" }
            return previousSelectorValue.value!!
        }
    }
}

@ExperimentalCoroutinesApi
@OptIn(ExperimentalTypeInference::class)
private fun <S, R> Store<S>.createSelectorProducer(@BuilderInference block: suspend ProducerScope<R>.() -> Unit): ReceiveChannel<R> =
    produce(
        context = coroutineContext,
        capacity = Channel.CONFLATED,
        block = block
    )

@ExperimentalCoroutinesApi
fun <S, R> Store<S>.createSelector(selector: Selector<S, R>): ReceiveChannel<R> = createSelectorProducer {
    val selectorClass = SelectorClass(this@createSelector::logIfEnabled, selector)
    state.consumeEach { latest -> this.send(selectorClass.consumeState(latest)) }
    logIfEnabled { "selector -> DONE" }
    close()
}

@ExperimentalCoroutinesApi
fun <S, R1, R2> Store<S>.createSelector(
    selector1: Selector<S, R1>,
    selector2: Selector<R1, R2>
): ReceiveChannel<R2> = createSelectorProducer {
    val selectorClass = SelectorClass(this@createSelector::logIfEnabled, selector1)
    val selector2Class = SelectorClass(this@createSelector::logIfEnabled, selector2)
    val channel = Channel<R1>(Channel.CONFLATED)
    state.consumeEach { latest ->
        channel.send(selectorClass.consumeState(latest))
        launch {
            channel.consumeEach { latest -> this@createSelectorProducer.send(selector2Class.consumeState(latest)) }
        }
    }
    logIfEnabled { "selector -> DONE" }
    channel.close()
    close()
}
