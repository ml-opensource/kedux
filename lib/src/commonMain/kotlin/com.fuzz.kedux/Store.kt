@file:Suppress("EXPERIMENTAL_API_USAGE")

package com.fuzz.kedux

import kotlinx.atomicfu.atomic
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.flow.MutableStateFlow
import kotlin.js.JsName
import kotlin.jvm.JvmName
import kotlin.native.concurrent.ThreadLocal


interface Dispatcher {
    /**
     * [dispatch] overload to be more targeted.
     */
    @JsName("dispatchPair")
    fun dispatch(pair: Pair<Any, Any>) {
        dispatchActual(pair.first)
        dispatchActual(pair.second)
    }

    /**
     * [dispatch] overload to be more targeted.
     */
    @JsName("dispatchTriple")
    fun dispatch(triple: Triple<Any, Any, Any>) {
        dispatchActual(triple.first)
        dispatchActual(triple.second)
        dispatchActual(triple.third)
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
    fun dispatch(typedAction: Action<*, *>) {
        dispatchActual(typedAction)
    }

    /**
     * [dispatch] overload to be more targeted.
     */
    @JsName("dispatchNoAction")
    @Suppress("UNUSED_PARAMETER")
    fun dispatch(noAction: NoAction) {
        Store.logIfEnabled { "STORE: NoAction received. Ignoring dispatch." }
    }

    /**
     * Dispatches an Action on the store. The action gets passed to a [Reducer] and [EffectFn] for data processing.
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

    fun dispatchActual(action: Any)
}

@Suppress("UNCHECKED_CAST")
fun <S : Any> createStore(
        reducer: Reducer<S>,
        initialState: S,
        enhancer: Enhancer<S> = emptyEnhancer()
) =
        Store(reducer, initialState, enhancer)

@ThreadLocal
private var internalLoggingEnabled = atomic(false)

open class Store<S : Any>(
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
) : Dispatcher {
    private val _state = MutableStateFlow(initialState)
    private val _actions: MutableStateFlow<Optional<Any>> = MutableStateFlow(Optional.None())

    val state: CFlow<S>
        get() = _state.wrap()

    val actions: CFlow<Any>
        get() = _actions.safeUnwrap().wrap()

    // required for Kotlin Native, does not support default arguments.
    constructor(reducer: Reducer<S>, initialState: S) : this(reducer, initialState, emptyEnhancer())

    override fun dispatchActual(action: Any) {
        logIfEnabled { "dispatch -> $action" }
        val dispatcher = { enhancedAction: Any ->
            if (enhancedAction is NoAction) {
                logIfEnabled { "STORE: NoAction received. Ignoring dispatch." }
            } else {
                val state = _state.value;
                val value = reducer.reduce(state, enhancedAction)
                logIfEnabled { "state -> $value" }
                _state.value = value
                _actions.value = Optional.Some(enhancedAction)
            }
        }
        enhancer(this@Store)(dispatcher)(action)
    }

    fun replaceReducer(reducer: Reducer<S>) {
        this.reducer = reducer
    }

    @JsName("selectWithScope")
    fun <R : Any?> select(
            selector: Selector<S, R>,
            scope: CoroutineScope = backgroundScope()): CFlow<R> = selector(scope, state).wrap()

    /**
     * Used mostly for Objective C compatibility
     */
    fun <R : Any?> select(selector: Selector<S, R>) = selector(backgroundScope(), state).wrap()


    @JvmName("selectList")
    fun <I, R : List<I>> select(
            listSelector: Selector<S, R>): CFlow<R> = listSelector(backgroundScope(), state).wrap()

    @JvmName("selectListWithScope")
    @JsName("selectListWithScope")
    fun <I, R : List<I>> select(
            listSelector: Selector<S, R>,
            scope: CoroutineScope = backgroundScope()): CFlow<R> = listSelector(scope, state).wrap()

    /**
     * Constructs a new effect to perform asynchronous action on the store.
     */
    fun <A : Any> effect(effect: EffectFn<A>): CFlow<A> = effect(actions).wrap()

    companion object {
        /**
         * If true, everything is logged to the native console.
         */

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
