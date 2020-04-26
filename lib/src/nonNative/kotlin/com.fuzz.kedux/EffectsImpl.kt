package com.fuzz.kedux

actual typealias Effect<A, R> = EffectClass<A, R>
actual typealias SilentEffect<A> = SilentEffectClass<A>
actual typealias ActionTypeEffect<T, P, R, RP> = ActionTypeEffectClass<T, P, R, RP>
