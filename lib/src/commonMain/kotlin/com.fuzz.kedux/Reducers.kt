package com.fuzz.kedux

import kotlin.reflect.KClass

interface Reducer<S : Any> {
    val stateClass: KClass<S>
    fun reduce(state: S, action: Any): S
}

inline fun <reified S : Any> anyReducer(crossinline fn: (state: S, action: Any) -> S) = object : Reducer<S> {
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
 * Combines a set of reducers into smaller pieces.
 */
inline fun <reified S : Any> combineReducers(vararg reducers: Reducer<S>): Reducer<S> =
    anyReducer { state: S, action: Any ->
        reducers.foldRight(state) { reducer, localState -> reducer.reduce(localState, action) }
    }
