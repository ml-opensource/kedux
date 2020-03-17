@file:Suppress("EXPERIMENTAL_API_USAGE")

package com.fuzz.kedux

import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.Job
import kotlinx.coroutines.channels.ConflatedBroadcastChannel
import kotlinx.coroutines.channels.ReceiveChannel
import kotlinx.coroutines.launch

typealias StoreCreator<S> = (reducer: Reducer<S>, initialState: S) -> Store<S>

@Suppress("UNCHECKED_CAST")
fun <S> createStore(
    reducer: Reducer<S>,
    initialState: S,
    enhancer: Enhancer<S>? = null,
    loggingEnabled: Boolean = false
) =
    Store(reducer, initialState, enhancer, loggingEnabled)

class Store<S> internal constructor(
    private var reducer: Reducer<S>,
    initialState: S,
    private val enhancer: Enhancer<S>? = null,
    val loggingEnabled: Boolean = false
) : CoroutineScope by CoroutineScope(Dispatchers.Default) {
    private var _state: ConflatedBroadcastChannel<S> = ConflatedBroadcastChannel(initialState)

    val state: ReceiveChannel<S>
        get() = _state.openSubscription()

    /**
     * Used to await dispatch result before continuing. This is useful to ensure dispatch parity within a coroutine.
     */
    suspend fun awaitDispatch(action: Any) = dispatch(action).join()

    /**
     * Launches a new coroutine to call the specified reducers. It will emit a
     * [state] result to selectors and subscribers on the store.
     */
    fun dispatch(action: Any): Job = launch {
        logIfEnabled { "dispatch -> $action" }
        val value = reducer.reduce(_state.value, action)
        logIfEnabled { "state -> $value" }
        _state.send(value)
    }

    fun replaceReducer(reducer: Reducer<S>) {
        this.reducer = reducer
    }

    inline fun logIfEnabled(messageBuilder: () -> String) {
        if (loggingEnabled) {
            println("STORE: ${messageBuilder()}")
        }
    }
}
