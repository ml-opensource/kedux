@file:Suppress("UNCHECKED_CAST")

package com.fuzz.kedux

import kotlinx.coroutines.ExperimentalCoroutinesApi
import kotlinx.coroutines.cancel
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.distinctUntilChanged
import kotlinx.coroutines.flow.launchIn
import kotlinx.coroutines.flow.map
import kotlinx.coroutines.flow.onEach

typealias SelectorFunction<S, R> = suspend (state: S) -> R

abstract class Selector<S : Any, R : Any?> {

    abstract operator fun invoke(state: CFlow<S>): Flow<R>

    fun <R2 : Any?> compose(composeFunction: SelectorFunction<R, R2>): ComposeSelectorCreator<S, R, R, R2> =
            ComposeSelectorCreator(this, composeFunction) { this }

    fun <T : Any?, R2 : Any?> compose(
            selectorTransform: Flow<R>.() -> Flow<T>,
            composeFunction: SelectorFunction<T, R2>): ComposeSelectorCreator<S, R, T, R2> =
            ComposeSelectorCreator(this, composeFunction, selectorTransform)
}

@ExperimentalCoroutinesApi
class SelectorSubject<S : Any?, R : Any?> internal constructor(
        private val state: Flow<S>,
        private val selectorFunction: SelectorFunction<S, R>,
        private val _stateSubject: MutableStateFlow<Optional<R>> = MutableStateFlow(Optional.None())
) : Flow<R> by _stateSubject.safeUnwrap() {

    private val scope = backgroundScope()

    init {

        // subscribe happens indefinitely.
        stateChange()
                .onEach { value -> _stateSubject.value = value }
                .launchIn(scope)
    }

    /**
     * Disposes of the subscription to the [Store]. Use this when you don't want the selector running anymore.
     */
    fun dispose() {
        scope.cancel()
    }

    private fun stateChange(): Flow<Optional<R>> = state
            .distinctUntilChanged()
            .map { state ->
                Store.logIfEnabled { "CONSUMING STATE $state" }
                val value = selectorFunction(state)
                Store.logIfEnabled { "PROPAGATING STATES $value" }
                return@map Optional.Some(value)
            }
            .distinctUntilChanged()
}

class SelectorCreator<S : Any, R : Any?>(
        private val selectorFunction: SelectorFunction<S, R>) : Selector<S, R>() {
    @ExperimentalCoroutinesApi
    override fun invoke(state: CFlow<S>): Flow<R> =
            SelectorSubject(state, selectorFunction)
}

class ComposeSelectorCreator<S : Any, T : Any?, R1 : Any?, R2 : Any?>
internal constructor(
        private val selectorCreator: Selector<S, T>,
        private val selectorFunction: SelectorFunction<R1, R2>,
        private val selectorTransform: Flow<T>.() -> Flow<R1>
) : Selector<S, R2>() {
    override fun invoke(state: CFlow<S>): Flow<R2> {
        return selectorCreator.invoke(state).selectorTransform().map(selectorFunction)
    }
}

fun <S : Any, R : Any?> createSelector(selectorFunction: SelectorFunction<S, R>): SelectorCreator<S, R> =
        SelectorCreator(selectorFunction)
