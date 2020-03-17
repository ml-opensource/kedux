package com.fuzz.kedux

import kotlinx.atomicfu.atomic
import kotlinx.coroutines.CancellationException
import kotlinx.coroutines.ExperimentalCoroutinesApi
import kotlinx.coroutines.InternalCoroutinesApi
import kotlinx.coroutines.ObsoleteCoroutinesApi
import kotlinx.coroutines.channels.*
import kotlinx.coroutines.selects.SelectClause1

typealias Selector<S, R> = (state: S) -> R

@ExperimentalCoroutinesApi
class SelectorClass<S, R> internal constructor(
    private val store: Store<S>,
    private val selector: Selector<S, R>
) : ReceiveChannel<R> {
    private val previousValue = atomic<S?>(null)
    private val previousSelectorValue = atomic<R?>(null)

    private val receiveChannel: ReceiveChannel<R>

    init {
        receiveChannel = store.produce(
            context = store.coroutineContext,
            capacity = Channel.CONFLATED
        ) {
            store.state.consumeEach { latest ->
                store.logIfEnabled { "selector -> previous ${previousValue.value} : latest ${latest}" }
                store.logIfEnabled { "selector -> previous == latest ${previousValue.value == latest}" }
                if (latest != previousValue.getAndSet(latest)) {
                    val value = selector(latest)
                    previousSelectorValue.value = value
                    store.logIfEnabled { "selector -> RECOMPUTE $value" }
                    this.send(value)
                } else {
                    store.logIfEnabled { "selector -> UNCHANGED ${previousSelectorValue.value}" }
                    previousSelectorValue.value?.let { this.send(it) }
                }
            }
            store.logIfEnabled { "selector -> DONE" }
        }
    }

    override val isClosedForReceive: Boolean = receiveChannel.isClosedForReceive
    override val isEmpty: Boolean = receiveChannel.isEmpty
    override val onReceive: SelectClause1<R> = receiveChannel.onReceive

    @InternalCoroutinesApi
    override val onReceiveOrClosed: SelectClause1<ValueOrClosed<R>> = receiveChannel.onReceiveOrClosed

    @ObsoleteCoroutinesApi
    override val onReceiveOrNull: SelectClause1<R?> = receiveChannel.onReceiveOrNull
    override fun cancel(cause: CancellationException?) = receiveChannel.cancel(cause)
    override fun iterator(): ChannelIterator<R> = receiveChannel.iterator()
    override fun poll(): R? = receiveChannel.poll()
    override suspend fun receive(): R = receiveChannel.receive()

    @InternalCoroutinesApi
    override suspend fun receiveOrClosed(): ValueOrClosed<R> = receiveChannel.receiveOrClosed()

    @ObsoleteCoroutinesApi
    override suspend fun receiveOrNull(): R? = receiveChannel.receiveOrNull()
    override fun cancel(cause: Throwable?): Boolean {
        TODO("not implemented")
    }
}

@ExperimentalCoroutinesApi
fun <S, R> Store<S>.createSelector(selector: Selector<S, R>) = SelectorClass(this, selector)
