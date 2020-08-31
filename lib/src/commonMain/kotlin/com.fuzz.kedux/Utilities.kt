package com.fuzz.kedux

import kotlinx.coroutines.CoroutineDispatcher
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.Job
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.filter
import kotlinx.coroutines.flow.map


internal sealed class Optional<T> {
    data class Some<T>(val value: T) : Optional<T>()
    class None<T> : Optional<T>()
}

internal fun <R> Flow<Optional<R>>.safeUnwrap() = filter {
    it is Optional.Some
}.map { (it as Optional.Some).value }

inline fun <reified R> Flow<Any?>.ofType(): Flow<R> = filter {
    it is R
}.map { it as R }

/**
 * On Native targets, this is main dispatcher, since we want to avoid freezing.
 */
expect fun getBackgroundDispatch(): CoroutineDispatcher


internal fun backgroundScope(): CoroutineScope = CoroutineScope(Job() + getBackgroundDispatch())

internal fun foregroundScope(): CoroutineScope = CoroutineScope(Job() + Dispatchers.Main)

