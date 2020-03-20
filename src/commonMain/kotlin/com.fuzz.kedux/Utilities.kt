package com.fuzz.kedux

import com.badoo.reaktive.observable.Observable
import com.badoo.reaktive.observable.filter
import com.badoo.reaktive.observable.map


internal sealed class Optional<T> {
    data class Some<T>(val value: T) : Optional<T>()
    class None<T> : Optional<T>()
}

internal fun <R> Observable<Optional<R>>.safeUnwrap() = filter {
    it is Optional.Some
}.map { (it as Optional.Some).value }
