@file:Suppress("UNCHECKED_CAST")

package com.fuzz.kedux

import kotlin.reflect.KClass

/**
 * Represents a fractured state map, allowing different reducers on difference pieces of state.
 */
data class FracturedState(internal val map: Map<KClass<out Reducer<Any>>, Any>) {
    fun <R : Any> fromReducer(reducer: Reducer<R>): R =
        map.getValue(reducer::class as KClass<out Reducer<Any>>) as R
}

@Suppress("UNCHECKED_CAST")
fun createFracturedState(
    vararg pairs: Pair<KClass<out Reducer<out Any>>, Any>
) = FracturedState(mapOf(*pairs as Array<out Pair<KClass<out Reducer<Any>>, Any>>))

class ReducerMap(
    vararg reducers: Reducer<Any>,
    override val stateClass: KClass<FracturedState> = FracturedState::class
) : Reducer<FracturedState>() {
    private val reducerMap: Map<KClass<Any>, Reducer<Any>> =
        reducers.map { it.stateClass to it }.toMap()

    override fun reduce(state: FracturedState, action: Any): FracturedState {
        val map: MutableMap<KClass<out Reducer<Any>>, Any> = mutableMapOf()
        reducerMap.forEach { (_, value) ->
            map[value::class] = value.reduce(state.map.getValue(value::class), action)
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
fun <R : Any> Store<FracturedState>.fracturedSelector(reducer: Reducer<R>) =
    createSelector { it.fromReducer(reducer) }

/**
 * See [fracturedSelector]
 */
fun <R1 : Any, R2 : Any> Store<FracturedState>.fracturedSelector(
    reducer: Reducer<R1>,
    selector: SelectorFunction<R1, R2>
) = createSelector({ it.fromReducer(reducer) }, selector)

/**
 * See [fracturedSelector]
 */
fun <R1 : Any, R2 : Any, R3 : Any> Store<FracturedState>.fracturedSelector(
    reducer: Reducer<R1>,
    selector: SelectorFunction<R1, R2>,
    selector2: SelectorFunction<R2, R3>
) = createSelector({ it.fromReducer(reducer) }, selector, selector2)

/**
 * See [fracturedSelector]
 */
fun <R1 : Any, R2 : Any, R3 : Any, R4 : Any> Store<FracturedState>.fracturedSelector(
    reducer: Reducer<R1>,
    selector: SelectorFunction<R1, R2>,
    selector2: SelectorFunction<R2, R3>,
    selector3: SelectorFunction<R3, R4>
) = createSelector({ it.fromReducer(reducer) }, selector, selector2, selector3)

/**
 * See [fracturedSelector]
 */
fun <R1 : Any, R2 : Any, R3 : Any, R4 : Any, R5 : Any> Store<FracturedState>.fracturedSelector(
    reducer: Reducer<R1>,
    selector: SelectorFunction<R1, R2>,
    selector2: SelectorFunction<R2, R3>,
    selector3: SelectorFunction<R3, R4>,
    selector4: SelectorFunction<R4, R5>
) = createSelector({ it.fromReducer(reducer) }, selector, selector2, selector3, selector4)

/**
 * See [fracturedSelector]
 */
fun <R1 : Any, R2 : Any, R3 : Any, R4 : Any, R5 : Any, R6 : Any> Store<FracturedState>.fracturedSelector(
    reducer: Reducer<R1>,
    selector: SelectorFunction<R1, R2>,
    selector2: SelectorFunction<R2, R3>,
    selector3: SelectorFunction<R3, R4>,
    selector4: SelectorFunction<R4, R5>,
    selector5: SelectorFunction<R5, R6>
) = createSelector(
    { it.fromReducer(reducer) },
    selector,
    selector2,
    selector3,
    selector4,
    selector5
)
