package com.fuzz.kedux

import kotlin.reflect.KClass

abstract class Reducer<S : Any> {
    abstract val stateClass: KClass<S>
    abstract fun reduce(state: S, action: Any): S
}

inline fun <reified S : Any> anyReducer(crossinline fn: (state: S, action: Any) -> S) =
        object : Reducer<S>() {
            override fun reduce(state: S, action: Any): S = fn(state, action)
            override val stateClass: KClass<S>
                get() = S::class
        }

/**
 * Constructs a typesafe action that only accepts the type argument [A] as an action. Useful for sealed classes.
 */
inline fun <reified S : Any, reified A> typedReducer(crossinline fn: (state: S, action: A) -> S) =
        anyReducer<S> { state, action ->
            when (action is A) {
                true -> fn(state, action)
                else -> state
            }
        }

/**
 * Constructs a typed action that expects a key type passed into the reducer to distinguish actions by their type.
 */
@Suppress("UNCHECKED_CAST")
inline fun <reified S : Any, reified T : Any> actionTypeReducer(crossinline fn: (state: S, action: Action<T, out Any>) -> S) =
        anyReducer<S> { state, action ->
            when (action is Action<*, *> && action.type is T) {
                true -> fn(state, action as Action<T, out Any>)
                false -> state
            }
        }

/**
 * Combines a set of reducers into smaller pieces.
 */
inline fun <reified S : Any> combineReducers(vararg reducers: Reducer<S>): Reducer<S> =
        anyReducer { state: S, action: Any ->
            reducers.foldRight(state) { reducer, localState -> reducer.reduce(localState, action) }
        }
