package com.fuzz.kedux

import kotlin.reflect.KClass

/**
 * Description:
 */

data class KonanFracturedState(internal val map: Map<ObjCClass, Any>) : FracturedState {
    override fun <R : Any> fromReducer(reducer: Reducer<R>): R =
            map.findByKClass(reducer.stateClass) as R

    override fun getState(valueClass: KClass<Any>): Any = map.findByKClass(valueClass)
}