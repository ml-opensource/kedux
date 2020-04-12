package com.fuzz.kedux

import com.badoo.reaktive.observable.Observable
import com.badoo.reaktive.observable.ObservableWrapper
import com.badoo.reaktive.observable.filter
import com.badoo.reaktive.observable.map
import com.badoo.reaktive.observable.ofType
import com.badoo.reaktive.observable.wrap
import kotlinx.cinterop.ObjCClass
import kotlinx.cinterop.getOriginalKotlinClass

@Suppress("UNCHECKED_CAST")
fun <T : Any> ObservableWrapper<Any>.filterInstance(kClass: ObjCClass): Observable<T> =
        filter { it::class.isInstance(getOriginalKotlinClass(kClass)) }
                .map { it as T }

/**
 * Description: Used to enclose
 */
class EffectCreator<A : Any>(private val ofType: ObjCClass) {

    fun <R : Any> createEffect(
            mapper: (ObservableWrapper<A>) -> Observable<R>
    ): Effect<R> =
            { actions: ObservableWrapper<Any> ->
                mapper(actions.filterInstance<A>(ofType).wrap()).wrap()
            }

    fun createSilentEffect(
            mapper: (ObservableWrapper<A>) -> Observable<Unit>
    ): Effect<NoAction> =
            { actions: ObservableWrapper<Any> -> mapper(actions.filterInstance<A>(ofType).wrap()).map { NoAction }.wrap() }

}

class ActionTypeGrouping<T : Any, P, R : Any, RP> {
    fun createActionTypeEffect(
            mapper: (ObservableWrapper<Action<T, P>>) -> Observable<Action<R, RP>>
    ): Effect<Action<R, RP>> =
            { actions: ObservableWrapper<Any> -> mapper(actions.ofType<Action<T, P>>().wrap()).wrap() }

}
