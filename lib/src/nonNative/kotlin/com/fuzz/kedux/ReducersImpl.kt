package com.fuzz.kedux

/**
 * Description:
 */
actual typealias TypedReducer<S, A> = TypedReducerClass<S, A>
actual typealias AnyReducer<S> = AnyReducerClass<S>
actual typealias ActionTypeReducer<S, T> = ActionTypeReducerClass<S, T>
