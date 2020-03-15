package com.fuzz.kedux

interface Reducer<S> {
    fun reduce(state: S, action: Any): S
}

inline fun <S> reducer(crossinline fn: (state: S, action: Any) -> S) = object : Reducer<S> {
    override fun reduce(state: S, action: Any): S = fn(state, action)
}

/**
 * Combines a set of reducers into smaller pieces.
 */
fun <S> combineReducers(vararg reducers: Reducer<S>): Reducer<S> =
    reducer { state: S, action: Any ->
        reducers.foldRight(state) { reducer, localState -> reducer.reduce(localState, action) }
    }
