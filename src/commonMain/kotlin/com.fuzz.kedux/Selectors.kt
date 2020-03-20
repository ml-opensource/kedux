@file:Suppress("UNCHECKED_CAST")

package com.fuzz.kedux

import com.badoo.reaktive.disposable.CompositeDisposable
import com.badoo.reaktive.disposable.addTo
import com.badoo.reaktive.observable.*
import com.badoo.reaktive.scheduler.computationScheduler
import com.badoo.reaktive.scheduler.mainScheduler
import com.badoo.reaktive.subject.Subject
import com.badoo.reaktive.subject.behavior.BehaviorSubject
import kotlinx.atomicfu.atomic

typealias SelectorFunction<S, R> = (state: S) -> R
typealias StoreLogger = (() -> String) -> Unit

class SelectorConsumer<S, R : Any?> internal constructor(
    private val storeLogger: StoreLogger,
    private val selectorFunction: SelectorFunction<S, R>
) {
    private val previousValue = atomic<S?>(null)
    private val previousSelectorValue = atomic<R?>(null)

    fun consumeState(latest: S): R {
        storeLogger { "selector -> previous ${previousValue.value} : latest $latest" }
        storeLogger { "selector -> previous == latest ${previousValue.value == latest}" }
        if (latest != previousValue.getAndSet(latest)) {
            val value = selectorFunction(latest)
            previousSelectorValue.value = value
            storeLogger { "selector -> RECOMPUTE $value" }
            return value
        } else {
            val value = previousSelectorValue.value
            storeLogger { "selector -> UNCHANGED $value" }
            // unsafe cast as kotlin has no way to know that R is optional from the class.
            // let's not force unwrap, as we expect callers to know nullability.
            @Suppress("UNCHECKED_CAST")
            return value as R
        }
    }
}

class SelectorSubject<S : Any, R : Any?> internal constructor(
    private val store: Store<S>,
    private val channelSelectors: List<SelectorConsumer<Any?, Any?>>,
    private val _stateSubject: Subject<Optional<R>> = BehaviorSubject(Optional.None())
) : Subject<Optional<R>> by _stateSubject {

    private val compositeDisposable: CompositeDisposable = CompositeDisposable()

    init {

        // subscribe happens indefinitely.
        stateChange()
            .subscribe { value -> _stateSubject.onNext(value) }
            .addTo(compositeDisposable)
    }

    /**
     * Disposes of the subscription to the [Store]. Use this when you don't want the selector running anymore.
     */
    fun dispose() {
        compositeDisposable.dispose()
    }

    private fun <T, U> propagateStates(state: S): R =
        channelSelectors.fold(state) { foldState: Any?, channelSelector ->
            channelSelector.consumeState(foldState)
        } as R

    private fun stateChange(): Observable<Optional<R>> = store.state
        .subscribeOn(computationScheduler)
        .map { state ->
            store.logIfEnabled { "CONSUMING STATE $state" }
            val value = propagateStates<S, R>(state)
            store.logIfEnabled { "PROPAGATING STATES $value" }
            return@map Optional.Some(value)
        }.observeOn(mainScheduler)
        .threadLocal()
}

fun <S : Any, R : Any?> Store<S>.createSelector(selectorFunction: SelectorFunction<S, R>): Observable<R> {
    val channelSelectors = listOf(
        SelectorConsumer(this@createSelector::logIfEnabled, selectorFunction as SelectorFunction<Any?, Any?>)
    )
    return SelectorSubject<S, R>(this@createSelector, channelSelectors)
        .safeUnwrap()
        .threadLocal()
}

fun <S : Any, R1 : Any?, R2 : Any?> Store<S>.createSelector(
    selectorFunction1: SelectorFunction<S, R1>,
    selectorFunction2: SelectorFunction<R1, R2>
): Observable<R2> {
    val channelSelectors = listOf(
        SelectorConsumer(this@createSelector::logIfEnabled, selectorFunction1 as SelectorFunction<Any?, Any?>),
        SelectorConsumer(this@createSelector::logIfEnabled, selectorFunction2 as SelectorFunction<Any?, Any?>)
    )
    return SelectorSubject<S, R2>(this@createSelector, channelSelectors).safeUnwrap().threadLocal()
}

fun <S : Any, R1 : Any?, R2 : Any?, R3 : Any?> Store<S>.createSelector(
    selectorFunction1: SelectorFunction<S, R1>,
    selectorFunction2: SelectorFunction<R1, R2>,
    selectorFunction3: SelectorFunction<R2, R3>
): Observable<R3> {
    val channelSelectors = listOf(
        SelectorConsumer(this@createSelector::logIfEnabled, selectorFunction1 as SelectorFunction<Any?, Any?>),
        SelectorConsumer(this@createSelector::logIfEnabled, selectorFunction2 as SelectorFunction<Any?, Any?>),
        SelectorConsumer(this@createSelector::logIfEnabled, selectorFunction3 as SelectorFunction<Any?, Any?>)
    )
    return SelectorSubject<S, R3>(this@createSelector, channelSelectors).safeUnwrap().threadLocal()
}

