package com.fuzz.kedux

import kotlinx.cinterop.ObjCClass
import kotlinx.cinterop.getOriginalKotlinClass
import kotlin.reflect.KClass

/**
 * Description:
 */

class ReducerCreator<S : Any>(private val ofType: ObjCClass) {

    fun anyReducer(fn: (state: S, action: Any) -> S) =
            object : Reducer<S>() {
                override fun reduce(state: S, action: Any): S = fn(state, action)
                override val stateClass: KClass<S>
                    get() = getOriginalKotlinClass(ofType) as KClass<S>
            }

}

class TypedReducerCreator<S : Any, A : Any>(private val ofType: ObjCClass, private val onAction: ObjCClass) {

    private val reducerCreator = ReducerCreator<S>(ofType)

    fun typedReducer(fn: (state: S, action: A) -> S) =
            reducerCreator.anyReducer { state, action ->
                when (action::class.isInstance(getOriginalKotlinClass(onAction))) {
                    true -> fn(state, action as A)
                    else -> state
                }
            }
}

class ActionTypeReducerCreator<S : Any, T : Any>(private val ofType: ObjCClass, private val onAction: ObjCClass) {

    private val reducerCreator = ReducerCreator<S>(ofType)

    /**
     * Constructs a typed action that expects a key type passed into the reducer to distinguish actions by their type.
     */
    @Suppress("UNCHECKED_CAST")
    fun actionTypeReducer(fn: (state: S, action: Action<T, out Any>) -> S) =
            reducerCreator.anyReducer { state, action ->
                when (action is Action<*, *> && action.type::class.isInstance(onAction)) {
                    true -> fn(state, action as Action<T, out Any>)
                    false -> state
                }
            }
}