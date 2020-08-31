@file:Suppress("UNCHECKED_CAST")

package com.fuzz.kedux

import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.ExperimentalCoroutinesApi
import kotlinx.coroutines.cancelAndJoin
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.distinctUntilChanged
import kotlinx.coroutines.flow.launchIn
import kotlinx.coroutines.flow.map
import kotlinx.coroutines.flow.onCompletion
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

class SelectorCreator<S : Any, R : Any?>(
        private val selectorFunction: SelectorFunction<S, R>,
        private val scope: CoroutineScope) : Selector<S, R>() {
    @ExperimentalCoroutinesApi
    override fun invoke(state: CFlow<S>): Flow<R> {
        val stateSubject: MutableStateFlow<Optional<R>> = MutableStateFlow(Optional.None())
        val job = state
                .distinctUntilChanged()
                .map { newState ->
                    Store.logIfEnabled { "CONSUMING STATE $newState" }
                    val value = selectorFunction(newState)
                    Store.logIfEnabled { "PROPAGATING STATES $value" }
                    return@map Optional.Some(value)
                }
                .distinctUntilChanged()
                .onEach { value -> stateSubject.value = value }
                .launchIn(scope)
        // when listening stops, cancel referenced state update job as well.
        return stateSubject.safeUnwrap().onCompletion { job.cancelAndJoin() };
    }
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
