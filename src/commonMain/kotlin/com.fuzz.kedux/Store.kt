@file:Suppress("EXPERIMENTAL_API_USAGE")

package com.fuzz.kedux

import com.badoo.reaktive.observable.Observable
import com.badoo.reaktive.observable.subscribe
import com.badoo.reaktive.observable.take
import com.badoo.reaktive.subject.behavior.BehaviorSubject

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
    val loggingEnabled: Boolean = false
) {
    private val _state = BehaviorSubject(initialState)

    val state: Observable<S>
        get() = _state

    /**
     * Launches a new coroutine to call the specified reducers. It will emit a
     * [state] result to selectors and subscribers on the store.
     */
    fun dispatch(action: Any) {
        logIfEnabled { "dispatch -> $action" }
        val dispatcher = { enhancedAction: Any ->
            _state.take(1)
                .subscribe { state ->
                    val value = reducer.reduce(state, enhancedAction)
                    logIfEnabled { "state -> $value" }
                    _state.onNext(value)
                }
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
