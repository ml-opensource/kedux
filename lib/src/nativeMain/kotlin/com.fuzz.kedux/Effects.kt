package com.fuzz.kedux

import kotlinx.cinterop.ObjCClass
import kotlinx.cinterop.getOriginalKotlinClass
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.filter
import kotlinx.coroutines.flow.map

@Suppress("UNCHECKED_CAST")
fun <T : Any> CFlow<Any>.filterInstance(kClass: ObjCClass): Flow<T> =
        filter { it::class.isInstance(getOriginalKotlinClass(kClass)) }
                .map { it as T }

actual class Effect<A : Any, R : Any>(
        private val ofType: ObjCClass,
        private val mapper: (CFlow<A>) -> Flow<R>
) : EffectFn<R>() {
    override fun invoke(actions: CFlow<Any>): CFlow<R> =
            mapper(actions.filterInstance<A>(ofType).wrap()).wrap()
}

actual class SilentEffect<A : Any>(
        private val ofType: ObjCClass,
        private val mapper: (CFlow<A>) -> Flow<Unit>
) : EffectFn<NoAction>() {
    override fun invoke(actions: CFlow<Any>) =
            mapper(actions.filterInstance<A>(ofType).wrap()).map { NoAction }.wrap()
}

actual typealias ActionTypeEffect<T, P, R, RP> = ActionTypeEffectClass<T, P, R, RP>
