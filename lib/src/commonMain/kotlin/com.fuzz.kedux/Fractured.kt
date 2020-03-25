@file:Suppress("UNCHECKED_CAST")

package com.fuzz.kedux

import kotlin.reflect.KClass

/**
 * Represents a fractured state map, allowing different reducers on difference pieces of state.
 */
data class FracturedState(internal val map: Map<KClass<out Any>, Any>) {
    fun <R : Any> fromReducer(reducer: Reducer<R>): R =
            map.getValue(reducer.stateClass) as R
}

@Suppress("UNCHECKED_CAST")
internal fun createFracturedState(
        vararg pairs: Pair<KClass<out Any>, Any>
) = FracturedState(mapOf(*pairs))

class ReducerMap(
        vararg reducers: Reducer<Any>,
        override val stateClass: KClass<FracturedState> = FracturedState::class
) : Reducer<FracturedState>() {
    private val reducerMap: Map<KClass<Any>, Reducer<Any>> =
            reducers.map { it.stateClass to it }.toMap()

    override fun reduce(state: FracturedState, action: Any): FracturedState {
        val map: MutableMap<KClass<out Any>, Any> = mutableMapOf()
        reducerMap.forEach { (valueClass, value) ->
            map[valueClass] = value.reduce(state.map.getValue(valueClass), action)
        }
        return FracturedState(map)
    }
}

fun fracturedReducer(vararg reducers: Reducer<out Any>) =
        ReducerMap(*reducers as Array<out Reducer<Any>>)

/**
 * Used to provide typesafety between reducer and state it consumes.
 */
infix fun <R : Any> Reducer<R>.reduce(data: R) = Pair(this, data)

/**
 * Creates a Fractured store using the passed reducer to state pairings.
 */
fun createFracturedStore(
        vararg pairs: Pair<Reducer<out Any>, Any>,
        enhancer: Enhancer<FracturedState> = emptyEnhancer()
) = createStore(
        fracturedReducer(*pairs.map { it.first }.toTypedArray()),
        createFracturedState(*pairs.map { it.first.stateClass to it.second }.toTypedArray()),
        enhancer
)

/**
 * Constructs a fractured selector on a piece of state.
 */
fun <R : Any> fracturedSelector(reducer: Reducer<R>): Selector<FracturedState, R> =
        createSelector { it.fromReducer(reducer) }
