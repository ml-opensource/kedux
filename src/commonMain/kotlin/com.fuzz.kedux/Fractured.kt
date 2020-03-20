@file:Suppress("UNCHECKED_CAST")

package com.fuzz.kedux

import kotlin.reflect.KClass

/**
 * Represents a fractured state map, allowing different reducers on difference pieces of state.
 */
data class FracturedState(internal val map: Map<KClass<out Reducer<Any>>, Any>) {
    fun <R : Any> fromReducer(reducer: Reducer<R>): R = map.getValue(reducer::class as KClass<out Reducer<Any>>) as R
}

@Suppress("UNCHECKED_CAST")
fun createFracturedState(
    vararg pairs: Pair<KClass<out Reducer<out Any>>, Any>
) = FracturedState(mapOf(*pairs as Array<out Pair<KClass<out Reducer<Any>>, Any>>))

class ReducerMap(
    vararg reducers: Reducer<Any>,
    override val stateClass: KClass<FracturedState> = FracturedState::class
) : Reducer<FracturedState> {
    private val reducerMap: Map<KClass<Any>, Reducer<Any>> = reducers.map { it.stateClass to it }.toMap()
    override fun reduce(state: FracturedState, action: Any): FracturedState {
        val map: MutableMap<KClass<out Reducer<Any>>, Any> = mutableMapOf()
        reducerMap.forEach { (_, value) ->
            map[value::class] = value.reduce(state.map.getValue(value::class), action)
        }
        return FracturedState(map)
    }
}

fun fracturedReducer(vararg reducers: Reducer<out Any>) = ReducerMap(*reducers as Array<out Reducer<Any>>)

/**
 * Creates a Fractured store using the passed reducer to state pairings.
 */
fun createFracturedStore(
    vararg pairs: Pair<Reducer<out Any>, Any>,
    enhancer: Enhancer<FracturedState> = emptyEnhancer(),
    loggingEnabled: Boolean = false
) = createStore(
    fracturedReducer(*pairs.map { it.first }.toTypedArray()),
    createFracturedState(*pairs.map { it.first::class to it.second }.toTypedArray()),
    enhancer,
    loggingEnabled
)

/**
 * Constructs a fractured selector on a piece of state.
 */
fun <R : Any> Store<FracturedState>.fracturedSelector(reducer: Reducer<R>) = createSelector { it.fromReducer(reducer) }
