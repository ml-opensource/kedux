package com.fuzz.kedux

import kotlinx.atomicfu.atomic
import kotlinx.coroutines.ExperimentalCoroutinesApi
import kotlinx.coroutines.channels.*
import kotlinx.coroutines.launch
import kotlin.experimental.ExperimentalTypeInference

typealias Selector<S, R> = (state: S) -> R

typealias StoreLogger = (() -> String) -> Unit

@ExperimentalCoroutinesApi
class SelectorClass<S, R : Any?> internal constructor(
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
            val value = previousSelectorValue.value
            storeLogger { "selector -> UNCHANGED $value" }
            // unsafe cast as kotlin has no way to know that R is optional from the class.
            // let's not force unwrap, as we expect callers to know nullability.
            @Suppress("UNCHECKED_CAST")
            return value as R
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
fun <S : Any, R1 : Any?, R2 : Any?> Store<S>.createSelector(
    selector1: Selector<S, R1>,
    selector2: Selector<R1, R2>
): ReceiveChannel<R2> = createSelectorProducer {
    val channelSelectors = listOf(
        SelectorClass(this@createSelector::logIfEnabled, selector1 as Selector<Any?, Any?>),
        SelectorClass(this@createSelector::logIfEnabled, selector2 as Selector<Any?, Any?>)
    )
    val channel = Channel<R2>(Channel.CONFLATED)
    state.consumeEach { state ->
        launch {
            channel.consumeEach { this@createSelectorProducer.send(it) }
        }
        @Suppress("UNCHECKED_CAST")
        channel.send(propagateStates<S, R2>(state, channelSelectors))
    }
    logIfEnabled { "selector -> DONE" }
    close()
}

@ExperimentalCoroutinesApi
fun <S : Any, R1 : Any?, R2 : Any?, R3 : Any?> Store<S>.createSelector(
    selector1: Selector<S, R1>,
    selector2: Selector<R1, R2>,
    selector3: Selector<R2, R3>
): ReceiveChannel<R3> = createSelectorProducer {
    val channelSelectors = listOf(
        SelectorClass(this@createSelector::logIfEnabled, selector1 as Selector<Any?, Any?>),
        SelectorClass(this@createSelector::logIfEnabled, selector2 as Selector<Any?, Any?>),
        SelectorClass(this@createSelector::logIfEnabled, selector3 as Selector<Any?, Any?>)
    )
    val channel = Channel<R3>(Channel.RENDEZVOUS)
    state.consumeEach { state ->
        launch {
            channel.consumeEach { this@createSelectorProducer.send(it) }
        }
        @Suppress("UNCHECKED_CAST")
        channel.send(propagateStates<S, R3>(state, channelSelectors))
    }
    logIfEnabled { "selector -> DONE" }
    close()
}

@ExperimentalCoroutinesApi
fun <S : Any?, R : Any?> propagateStates(state: S, channelSelectors: List<SelectorClass<Any?, Any?>>): R {
    return channelSelectors.fold(state) { state: Any?, channelSelector ->
        channelSelector.consumeState(
            state
        )
    } as R
}
