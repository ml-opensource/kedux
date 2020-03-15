package com.fuzz.kedux

interface Reducer<S> {
    fun reduce(state: S, action: Any): S
}

inline fun <S> reducer(crossinline fn: (state: S, action: Any) -> S) = object : Reducer<S> {
    override fun reduce(state: S, action: Any): S = fn(state, action)
}

/**
 * Constructs a typesafe action that only accepts the type argument [A] as an action. Useful for sealed classes.
 */
inline fun <S, reified A> typedReducer(crossinline fn: (state: S, action: A) -> S) = reducer<S> { state, action ->
    when (action is A) {
        true -> fn(state, action)
        else -> state
    }
}

/**
 * Combines a set of reducers into smaller pieces.
 */
fun <S> combineReducers(vararg reducers: Reducer<S>): Reducer<S> =
    reducer { state: S, action: Any ->
        reducers.foldRight(state) { reducer, localState -> reducer.reduce(localState, action) }
    }
