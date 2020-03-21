@file:Suppress("UNCHECKED_CAST")

package com.fuzz.kedux

import com.badoo.reaktive.disposable.CompositeDisposable
import com.badoo.reaktive.disposable.addTo
import com.badoo.reaktive.observable.Observable
import com.badoo.reaktive.observable.ObservableWrapper
import com.badoo.reaktive.observable.map
import com.badoo.reaktive.observable.observeOn
import com.badoo.reaktive.observable.subscribe
import com.badoo.reaktive.observable.subscribeOn
import com.badoo.reaktive.observable.threadLocal
import com.badoo.reaktive.observable.wrap
import com.badoo.reaktive.scheduler.computationScheduler
import com.badoo.reaktive.scheduler.mainScheduler
import com.badoo.reaktive.subject.Subject
import com.badoo.reaktive.subject.behavior.BehaviorSubject
import com.badoo.reaktive.utils.atomic.AtomicReference
import com.badoo.reaktive.utils.atomic.getAndSet

typealias SelectorFunction<S, R> = (state: S) -> R
typealias StoreLogger = (() -> String) -> Unit

class SelectorConsumer<S, R : Any?> internal constructor(
        private val storeLogger: StoreLogger,
        private val selectorFunction: SelectorFunction<S, R>
) {
    private var previousValue: AtomicReference<S?> = AtomicReference(null)
    private var previousSelectorValue: AtomicReference<R?> = AtomicReference(null)

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
        vararg channelSelectors: SelectorFunction<Any?, Any?>,
        private val _stateSubject: Subject<Optional<R>> = BehaviorSubject(Optional.None())
) : Subject<Optional<R>> by _stateSubject {

    private val channelSelectors: List<SelectorConsumer<Any?, Any?>> =
            channelSelectors.map { SelectorConsumer(store::logIfEnabled, it) }
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
            .threadLocal()
            .map { state ->
                store.logIfEnabled { "CONSUMING STATE $state" }
                val value = propagateStates<S, R>(state)
                store.logIfEnabled { "PROPAGATING STATES $value" }
                return@map Optional.Some(value)
            }.observeOn(mainScheduler)
}

fun <S : Any, R : Any?> Store<S>.createSelector(selectorFunction: SelectorFunction<S, R>): ObservableWrapper<R> =
        SelectorSubject<S, R>(this@createSelector, selectorFunction as SelectorFunction<Any?, Any?>)
                .safeUnwrap().threadLocal().wrap()

fun <S : Any, R1 : Any?, R2 : Any?> Store<S>.createSelector(
        selectorFunction1: SelectorFunction<S, R1>,
        selectorFunction2: SelectorFunction<R1, R2>
): ObservableWrapper<R2> =
        SelectorSubject<S, R2>(
                this@createSelector,
                selectorFunction1 as SelectorFunction<Any?, Any?>,
                selectorFunction2 as SelectorFunction<Any?, Any?>
        ).safeUnwrap().threadLocal().wrap()

fun <S : Any, R1 : Any?, R2 : Any?, R3 : Any?> Store<S>.createSelector(
        selectorFunction1: SelectorFunction<S, R1>,
        selectorFunction2: SelectorFunction<R1, R2>,
        selectorFunction3: SelectorFunction<R2, R3>
): ObservableWrapper<R3> =
        SelectorSubject<S, R3>(
                this@createSelector,
                selectorFunction1 as SelectorFunction<Any?, Any?>,
                selectorFunction2 as SelectorFunction<Any?, Any?>,
                selectorFunction3 as SelectorFunction<Any?, Any?>
        ).safeUnwrap().threadLocal().wrap()

fun <S : Any, R1 : Any?, R2 : Any?, R3 : Any?, R4 : Any?> Store<S>.createSelector(
        selectorFunction1: SelectorFunction<S, R1>,
        selectorFunction2: SelectorFunction<R1, R2>,
        selectorFunction3: SelectorFunction<R2, R3>,
        selectorFunction4: SelectorFunction<R3, R4>
): ObservableWrapper<R4> =
        SelectorSubject<S, R4>(
                this@createSelector,
                selectorFunction1 as SelectorFunction<Any?, Any?>,
                selectorFunction2 as SelectorFunction<Any?, Any?>,
                selectorFunction3 as SelectorFunction<Any?, Any?>,
                selectorFunction4 as SelectorFunction<Any?, Any?>
        ).safeUnwrap().threadLocal().wrap()

fun <S : Any, R1 : Any?, R2 : Any?, R3 : Any?, R4 : Any?, R5 : Any?> Store<S>.createSelector(
        selectorFunction1: SelectorFunction<S, R1>,
        selectorFunction2: SelectorFunction<R1, R2>,
        selectorFunction3: SelectorFunction<R2, R3>,
        selectorFunction4: SelectorFunction<R3, R4>,
        selectorFunction5: SelectorFunction<R4, R5>
): ObservableWrapper<R5> =
        SelectorSubject<S, R5>(
                this@createSelector,
                selectorFunction1 as SelectorFunction<Any?, Any?>,
                selectorFunction2 as SelectorFunction<Any?, Any?>,
                selectorFunction3 as SelectorFunction<Any?, Any?>,
                selectorFunction4 as SelectorFunction<Any?, Any?>,
                selectorFunction5 as SelectorFunction<Any?, Any?>
        ).safeUnwrap().threadLocal().wrap()

fun <S : Any, R1 : Any?, R2 : Any?, R3 : Any?, R4 : Any?, R5 : Any?, R6 : Any?> Store<S>.createSelector(
        selectorFunction1: SelectorFunction<S, R1>,
        selectorFunction2: SelectorFunction<R1, R2>,
        selectorFunction3: SelectorFunction<R2, R3>,
        selectorFunction4: SelectorFunction<R3, R4>,
        selectorFunction5: SelectorFunction<R4, R5>,
        selectorFunction6: SelectorFunction<R5, R6>
): ObservableWrapper<R6> =
        SelectorSubject<S, R6>(
                this@createSelector,
                selectorFunction1 as SelectorFunction<Any?, Any?>,
                selectorFunction2 as SelectorFunction<Any?, Any?>,
                selectorFunction3 as SelectorFunction<Any?, Any?>,
                selectorFunction4 as SelectorFunction<Any?, Any?>,
                selectorFunction5 as SelectorFunction<Any?, Any?>,
                selectorFunction6 as SelectorFunction<Any?, Any?>
        ).safeUnwrap().threadLocal().wrap()
