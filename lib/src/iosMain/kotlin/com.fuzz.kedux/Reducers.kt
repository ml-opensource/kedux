@file:Suppress("UNCHECKED_CAST")

package com.fuzz.kedux

import kotlin.reflect.KClass

/**
 * Description:
 */

open class KonanReducer<S : Any>(private val ofType: ObjCClass,
                                 private val fn: (state: S, action: Any) -> S) : Reducer<S>() {
    override fun reduce(state: S, action: Any): S = fn(state, action)

    @Suppress("UNCHECKED_CAST")
    override val stateClass: KClass<S>
        get() = getOriginalKotlinClass(ofType) as KClass<S>
}

class TypedKonanReducer<S : Any, A : Any>(private val ofType: ObjCClass, private val onAction: ObjCClass,
                                          fn: (state: S, action: A) -> S) : KonanReducer<S>(ofType, { state, action ->
    when (action::class.isInstance(getOriginalKotlinClass(onAction))) {
        true -> fn(state, action as A)
        else -> state
    }
})

class ActionTypeKonanReducer<S : Any, T : Any>(
        private val ofType: ObjCClass,
        private val onAction: ObjCClass,
        fn: (state: S, action: Action<T, out Any>) -> S
) : KonanReducer<S>(ofType, { state, action ->
    when (action is Action<*, *> && action.type::class.isInstance(onAction)) {
        true -> fn(state, action as Action<T, out Any>)
        false -> state
    }
})
