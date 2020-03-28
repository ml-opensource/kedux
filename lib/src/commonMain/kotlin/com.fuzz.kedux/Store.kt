@file:Suppress("EXPERIMENTAL_API_USAGE")

package com.fuzz.kedux

import com.badoo.reaktive.observable.ObservableWrapper
import com.badoo.reaktive.observable.observeOn
import com.badoo.reaktive.observable.subscribe
import com.badoo.reaktive.observable.take
import com.badoo.reaktive.observable.wrap
import com.badoo.reaktive.scheduler.computationScheduler
import com.badoo.reaktive.scheduler.mainScheduler
import com.badoo.reaktive.subject.behavior.BehaviorSubject
import com.badoo.reaktive.utils.atomic.AtomicBoolean
import kotlin.js.JsName

@Suppress("UNCHECKED_CAST")
fun <S : Any> createStore(
        reducer: Reducer<S>,
        initialState: S,
        enhancer: Enhancer<S> = emptyEnhancer()
) =
        Store(reducer, initialState, enhancer)

class Store<S : Any> internal constructor(
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
        private val enhancer: Enhancer<S> = emptyEnhancer()
) {
    private val _state = BehaviorSubject(initialState)
    private val _actions: BehaviorSubject<Optional<Any>> = BehaviorSubject(Optional.None())

    val state: ObservableWrapper<S>
        get() = _state.observeOn(mainScheduler).wrap()

    val actions: ObservableWrapper<Any>
        get() = _actions.observeOn(mainScheduler).safeUnwrap().wrap()

    /**
     * [dispatch] overload to be more targeted.
     */
    @JsName("dispatchPair")
    fun dispatch(action: Pair<Any, Any>) {
        dispatchActual(action.first)
        dispatchActual(action.second)
    }

    /**
     * [dispatch] overload to be more targeted.
     */
    @JsName("dispatchTriple")
    fun dispatch(action: Triple<Any, Any, Any>) {
        dispatchActual(action.first)
        dispatchActual(action.second)
        dispatchActual(action.third)
    }

    /**
     * [dispatch] overload to be more targeted.
     */
    @JsName("dispatchMultiAction")
    fun dispatch(multiAction: MultiAction) {
        multiAction.actions.forEach { a -> dispatchActual(a) }
    }

    /**
     * [dispatch] overload to be more targeted.
     */
    @JsName("dispatchTypedAction")
    fun dispatch(action: Action<*>) {
        dispatchActual(action)
    }

    /**
     * Launches a new coroutine to call the specified reducers. It will emit a
     * [state] result to selectors and subscribers on the store.
     */
    fun dispatch(action: Any) {
        // handle different action types just in case.
        when (action) {
            is Pair<*, *> -> {
                dispatchActual(action.first!!)
                dispatchActual(action.second!!)
            }
            is Triple<*, *, *> -> {
                dispatchActual(action.first!!)
                dispatchActual(action.second!!)
                dispatchActual(action.third!!)
            }
            is MultiAction -> {
                action.actions.forEach { a -> dispatchActual(a) }
            }
            else -> dispatchActual(action)
        }
    }

    private fun dispatchActual(action: Any) {
        logIfEnabled { "dispatch -> $action" }
        val dispatcher = { enhancedAction: Any ->
            if (enhancedAction is NoAction) {
                logIfEnabled { "STORE: NoAction received. Ignoring dispatch." }
            } else {
                _state.take(1)
                        .observeOn(computationScheduler)
                        .subscribe { state ->
                            val value = reducer.reduce(state, enhancedAction)
                            logIfEnabled { "state -> $value" }
                            _state.onNext(value)
                            _actions.onNext(Optional.Some(enhancedAction))
                        }
            }
        }
        enhancer(this@Store)(dispatcher)(action)
    }

    fun replaceReducer(reducer: Reducer<S>) {
        this.reducer = reducer
    }

    fun <R : Any?> select(selector: Selector<S, R>): ObservableWrapper<R> = selector(state)

    /**
     * Constructs a new effect to perform asynchronous action on the store.
     */
    fun <A : Any> effect(effect: Effect<A>): ObservableWrapper<A> = effect(actions)

    companion object {
        /**
         * If true, everything is logged to the native console.
         */
        private var internalLoggingEnabled: AtomicBoolean = AtomicBoolean(false)

        var loggingEnabled: Boolean
            get() = internalLoggingEnabled.value
            set(value) {
                internalLoggingEnabled.value = value
            }

        inline fun logIfEnabled(messageBuilder: () -> String) {
            if (loggingEnabled) {
                println("STORE: ${messageBuilder()}")
            }
        }
    }
}
