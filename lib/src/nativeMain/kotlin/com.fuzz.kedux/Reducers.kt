@file:Suppress("UNCHECKED_CAST")

package com.fuzz.kedux

import kotlin.reflect.KClass

/**
 * Description:
 */
actual class TypedReducer<S : Any, A : Any>(
        private val ofType: ObjCClass,
        private val onAction: ObjCClass,
        private val fn: (state: S, action: A) -> S
) : Reducer<S>() {
    @Suppress("UNCHECKED_CAST")
    override val stateClass: KClass<S>
        get() = getOriginalKotlinClass(ofType) as KClass<S>

    override fun reduce(state: S, action: Any): S =
            when (action::class.isInstance(getOriginalKotlinClass(onAction))) {
                true -> fn(state, action as A)
                else -> state
            }
}

actual class AnyReducer<S : Any>(private val ofType: ObjCClass,
                                 private val fn: (state: S, action: Any) -> S) : Reducer<S>() {
    override fun reduce(state: S, action: Any): S = fn(state, action)

    @Suppress("UNCHECKED_CAST")
    override val stateClass: KClass<S>
        get() = getOriginalKotlinClass(ofType) as KClass<S>
}

actual class ActionTypeReducer<S : Any, T : Any>(
        private val ofType: ObjCClass,
        private val onAction: ObjCClass,
        private val fn: (state: S, action: Action<T, out Any>) -> S
) : Reducer<S>() {

    override fun reduce(state: S, action: Any): S =
            when (action is Action<*, *> && action.type::class.isInstance(onAction)) {
                true -> fn(state, action as Action<T, out Any>)
                false -> state
            }

    @Suppress("UNCHECKED_CAST")
    override val stateClass: KClass<S>
        get() = getOriginalKotlinClass(ofType) as KClass<S>
}
