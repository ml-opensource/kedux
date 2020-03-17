@file:Suppress("EXPERIMENTAL_API_USAGE")

package com.fuzz.kedux

import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.Job
import kotlinx.coroutines.channels.ConflatedBroadcastChannel
import kotlinx.coroutines.channels.ReceiveChannel
import kotlinx.coroutines.launch
import kotlin.coroutines.CoroutineContext

typealias StoreCreator<S> = (reducer: Reducer<S>, initialState: S) -> Store<S>

@Suppress("UNCHECKED_CAST")
fun <S> createStore(
    reducer: Reducer<S>,
    initialState: S,
    enhancer: Enhancer<S> = emptyEnhancer(),
    loggingEnabled: Boolean = false
) =
    Store(reducer, initialState, enhancer, loggingEnabled)

class Store<S> internal constructor(
    /**
     * The main reducer on this store. See Reducers.kt
     */
    private var reducer: Reducer<S>,

    /**
     * Provide a default state for the application store.
     */
    initialState: S,

    /**
     * Used to enhance
     */
    private val enhancer: Enhancer<S> = emptyEnhancer(),

    /**
     * If true, everything is logged to the native console.
     */
    val loggingEnabled: Boolean = false,
    /**
     * Specify a [coroutineContext] to run dispatches, selectors, and reducers within.
     * By default this is the [Dispatchers.Default]
     */
    coroutineContext: CoroutineContext = Dispatchers.Default
) : CoroutineScope by CoroutineScope(coroutineContext) {
    private var _state: ConflatedBroadcastChannel<S> = ConflatedBroadcastChannel(initialState)

    val state: ReceiveChannel<S>
        get() = _state.openSubscription()

    fun closeState() {
        _state.close()
    }

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
        val dispatcher = { enhancedAction: Any ->
            val value = reducer.reduce(_state.value, enhancedAction)
            logIfEnabled { "state -> $value" }
            _state.offer(value)
        }
        enhancer(this@Store)(dispatcher)(action)
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
