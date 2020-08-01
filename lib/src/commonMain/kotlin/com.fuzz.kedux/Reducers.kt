@file:Suppress("UNCHECKED_CAST")

package com.fuzz.kedux

import kotlin.reflect.KClass

/**
 * The main function of state. This class represents a function off [S] to change state.
 */
abstract class Reducer<S : Any> {
    abstract val stateClass: KClass<S>
    abstract fun reduce(state: S, action: Any): S
}

/**
 * Expect declaration so that Native targets to point to class with constructor that takes in non-KClass
 * arguments, for better Swift / ObjC APIs.
 */
expect class TypedReducer<S : Any, A : Any> : Reducer<S>

/**
 * Expect declaration so that Native targets to point to class with constructor that takes in non-KClass
 * arguments, for better Swift / ObjC APIs.
 */
expect class AnyReducer<S : Any> : Reducer<S>

/**
 * Expect declaration so that Native targets to point to class with constructor that takes in non-KClass
 * arguments, for better Swift / ObjC APIs.
 */
expect class ActionTypeReducer<S : Any, T : Any> : Reducer<S>

class TypedReducerClass<S : Any, A : Any>(
        override val stateClass: KClass<S>,
        private val actionClass: KClass<A>,
        private val fn: (state: S, action: A) -> S) : Reducer<S>() {

    override fun reduce(state: S, action: Any): S = when (actionClass.isInstance(action)) {
        true -> fn(state, action as A)
        else -> state
    }
}

class AnyReducerClass<S : Any>(
        override val stateClass: KClass<S>,
        private val fn: (state: S, action: Any) -> S
) : Reducer<S>() {
    override fun reduce(state: S, action: Any): S = fn(state, action)
}

inline fun <reified S : Any> anyReducer(noinline fn: (state: S, action: Any) -> S): Reducer<S> =
        AnyReducerClass(S::class, fn)

/**
 * Constructs a typesafe action that only accepts the type argument [A] as an action. Useful for sealed classes.
 */
inline fun <reified S : Any, reified A : Any> typedReducer(noinline fn: (state: S, action: A) -> S): Reducer<S> =
        TypedReducerClass(S::class, A::class, fn)

class ActionTypeReducerClass<S : Any, T : Any>(
        override val stateClass: KClass<S>,
        private val typeClass: KClass<T>,
        private val fn: (state: S, action: Action<T, out Any>) -> S
) : Reducer<S>() {

    override fun reduce(state: S, action: Any): S =
            when (action is Action<*, *> && typeClass.isInstance(action.type)) {
                true -> fn(state, action as Action<T, out Any>)
                false -> state
            }
}

/**
 * Constructs a typed action that expects a key type passed into the reducer to distinguish actions by their type.
 */
@Suppress("UNCHECKED_CAST")
inline fun <reified S : Any, reified T : Any> actionTypeReducer(
        noinline fn: (state: S, action: Action<T, out Any>) -> S): Reducer<S> =
        ActionTypeReducerClass(S::class, T::class, fn)

class CombineReducers<S : Any>(
        override val stateClass: KClass<S>,
        private vararg val reducers: Reducer<S>) : Reducer<S>() {

    override fun reduce(state: S, action: Any): S =
            reducers.foldRight(state) { reducer, localState -> reducer.reduce(localState, action) }
}

/**
 * Combines a set of reducers into smaller pieces.
 */
inline fun <reified S : Any> combineReducers(vararg reducers: Reducer<S>): Reducer<S> =
        CombineReducers(S::class, *reducers)
