@file:Suppress("UNCHECKED_CAST")

package com.fuzz.kedux

import kotlin.reflect.KClass

interface FracturedState {
    fun getState(valueClass: KClass<Any>): Any

    fun <R : Any> fromReducer(reducer: Reducer<R>): R
}

/**
 * Represents a fractured state map, allowing different reducers on difference pieces of state.
 */
data class FracturedStateImpl(internal val map: Map<KClass<out Any>, Any>) : FracturedState {
    override fun <R : Any> fromReducer(reducer: Reducer<R>): R =
            map.getValue(reducer.stateClass) as R

    override fun getState(valueClass: KClass<Any>): Any = map.getValue(valueClass)
}

@Suppress("UNCHECKED_CAST")
internal fun createFracturedState(
        vararg pairs: Pair<KClass<out Any>, Any>
) = FracturedStateImpl(mapOf(*pairs))

class ReducerMap(
        reducers: List<Reducer<Any>>
) : Reducer<FracturedState>() {

    override val stateClass: KClass<FracturedState> = FracturedState::class

    private val reducerMap: Map<KClass<Any>, Reducer<Any>> =
            reducers.map { it.stateClass to it }.toMap()

    override fun reduce(state: FracturedState, action: Any): FracturedState {
        val map: MutableMap<KClass<out Any>, Any> = mutableMapOf()
        reducerMap.forEach { (valueClass, value) ->
            map[valueClass] = value.reduce(state.getState(valueClass), action)
        }
        return FracturedStateImpl(map)
    }
}

fun fracturedReducer(vararg reducers: Reducer<out Any>) =
        ReducerMap(reducers.toList() as List<Reducer<Any>>)

/**
 * Used to provide typesafety between reducer and state it consumes.
 */
infix fun <R : Any> Reducer<R>.reduce(data: R) = Pair(this, data)

class FracturedStore(
        map: Map<out Reducer<out Any>, Any>,
        enhancer: Enhancer<FracturedState>
) : Store<FracturedState>(fracturedReducer(*map.keys.toTypedArray()),
        createFracturedState(*map.map { (key, value) -> key.stateClass to value }.toTypedArray()),
        enhancer) {
    constructor(map: Map<out Reducer<out Any>, Any>) : this(map, emptyEnhancer())
}


/**
 * Creates a Fractured store using the passed reducer to state pairings.
 */
fun createFracturedStore(
        vararg pairs: Pair<Reducer<out Any>, Any>,
        enhancer: Enhancer<FracturedState> = emptyEnhancer()
) = FracturedStore(
        pairs.toMap(),
        enhancer
)

/**
 * Constructs a fractured selector on a piece of state.
 */
fun <R : Any> fracturedSelector(reducer: Reducer<R>): Selector<FracturedState, R> =
        createSelector { it.fromReducer(reducer) }
