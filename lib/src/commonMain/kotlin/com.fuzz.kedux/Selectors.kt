@file:Suppress("UNCHECKED_CAST")

package com.fuzz.kedux

import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.ExperimentalCoroutinesApi
import kotlinx.coroutines.cancel
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.distinctUntilChanged
import kotlinx.coroutines.flow.launchIn
import kotlinx.coroutines.flow.map
import kotlinx.coroutines.flow.onEach
import kotlin.js.JsName

typealias SelectorFunction<S, R> = (state: S) -> R

abstract class Selector<S : Any, R : Any?> {

    abstract operator fun invoke(state: CFlow<S>): Flow<R>

    fun <R2 : Any?> compose(composeFunction: SelectorFunction<R, R2>): Selector<S, R2> =
            ComposeSelectorCreator(this, composeFunction) { this }

    fun <T : Any?, R2 : Any?> compose(
            selectorTransform: CFlow<R>.() -> Flow<T>,
            composeFunction: SelectorFunction<T, R2>): Selector<S, R2> =
            ComposeSelectorCreator(this, composeFunction, selectorTransform)
}

@ExperimentalCoroutinesApi
class SelectorSubject<S : Any?, R : Any?> internal constructor(
        private val state: Flow<S>,
        private val selectorFunction: SelectorFunction<S, R>,
        private val scope: CoroutineScope,
        private val _stateSubject: MutableStateFlow<Optional<R>> = MutableStateFlow(Optional.None()),
) : Flow<R> by _stateSubject.safeUnwrap() {

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
        private val selectorFunction: SelectorFunction<S, R>,
        private val scope: CoroutineScope) : Selector<S, R>() {
    @ExperimentalCoroutinesApi
    override fun invoke(state: CFlow<S>): Flow<R> =
            SelectorSubject(state, selectorFunction, scope)
}

class ComposeSelectorCreator<S : Any, T : Any?, R1 : Any?, R2 : Any?>
internal constructor(
        private val selectorCreator: Selector<S, T>,
        private val selectorFunction: SelectorFunction<R1, R2>,
        private val selectorTransform: CFlow<T>.() -> Flow<R1>
) : Selector<S, R2>() {
    override fun invoke(state: CFlow<S>): Flow<R2> {
        return selectorCreator.invoke(state).wrap().selectorTransform().map { selectorFunction(it) }
    }
}

@JsName("createSelectorWithScope")
fun <S : Any, R : Any?> createSelector(
        scope: CoroutineScope = backgroundScope(),
        selectorFunction: SelectorFunction<S, R>): SelectorCreator<S, R> =
        SelectorCreator(selectorFunction, scope)

fun <S : Any, R : Any?> createSelector(
        selectorFunction: SelectorFunction<S, R>): SelectorCreator<S, R> =
        SelectorCreator(selectorFunction, backgroundScope())
