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

actual class Effect<A : Any, R : Any>(
        private val ofType: ObjCClass,
        private val mapper: (ObservableWrapper<A>) -> Observable<R>
) : EffectFn<R>() {
    override fun invoke(actions: ObservableWrapper<Any>): ObservableWrapper<R> =
            mapper(actions.filterInstance<A>(ofType).wrap()).wrap()
}

actual class SilentEffect<A : Any>(
        private val ofType: ObjCClass,
        private val mapper: (ObservableWrapper<A>) -> Observable<Unit>
) : EffectFn<NoAction>() {
    override fun invoke(actions: ObservableWrapper<Any>) =
            mapper(actions.filterInstance<A>(ofType).wrap()).map { NoAction }.wrap()
}

actual typealias ActionTypeEffect<T, P, R, RP> = ActionTypeEffectClass<T, P, R, RP>
