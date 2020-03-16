package com.fuzz.kedux

import kotlinx.coroutines.ExperimentalCoroutinesApi
import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.Job
import kotlinx.coroutines.channels.ConflatedBroadcastChannel
import kotlinx.coroutines.channels.ReceiveChannel
import kotlinx.coroutines.launch

typealias StoreCreator<S> = (reducer: Reducer<S>, initialState: S) -> Store<S>
typealias ChangeListener<S> = (state: S) -> Unit

@Suppress("UNCHECKED_CAST")
fun <S> createStore(
    reducer: Reducer<S>,
    initialState: S,
    enhancer: Enhancer<S>? = null
) =
    Store(reducer, initialState, enhancer)

@ExperimentalCoroutinesApi
class Store<S>(
    private var reducer: Reducer<S>,
    initialState: S,
    private val enhancer: Enhancer<S>? = null
) {
    private var _state: ConflatedBroadcastChannel<S> = ConflatedBroadcastChannel(initialState)
    private val changeListenerSet = mutableSetOf<ChangeListener<S>>()

    val state: ReceiveChannel<S>
        get() = _state.openSubscription()

    suspend fun awaitDispatch(action: Any) = dispatch(action).join()

    fun dispatch(action: Any): Job = GlobalScope.launch {
        _state.send(reducer.reduce(_state.value, action))
        changeListenerSet.forEach { it(_state.value) }
    }

    fun replaceReducer(reducer: Reducer<S>) {
        this.reducer = reducer
    }
}
