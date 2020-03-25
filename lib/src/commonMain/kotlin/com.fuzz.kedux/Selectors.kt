@file:Suppress("UNCHECKED_CAST")

package com.fuzz.kedux

import com.badoo.reaktive.disposable.CompositeDisposable
import com.badoo.reaktive.disposable.addTo
import com.badoo.reaktive.observable.Observable
import com.badoo.reaktive.observable.ObservableWrapper
import com.badoo.reaktive.observable.distinctUntilChanged
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

class SelectorSubject<S : Any?, R : Any?> internal constructor(
        private val state: Observable<S>,
        vararg channelSelectors: SelectorFunction<Any?, Any?>,
        private val _stateSubject: Subject<Optional<R>> = BehaviorSubject(Optional.None())
) : Observable<R> by _stateSubject.safeUnwrap().threadLocal() {

    private val channelSelectors: List<SelectorConsumer<Any?, Any?>> =
            channelSelectors.map { SelectorConsumer(Store.Companion::logIfEnabled, it) }
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

    private fun stateChange(): Observable<Optional<R>> = state
            .subscribeOn(computationScheduler)
            .threadLocal()
            .map { state ->
                Store.logIfEnabled { "CONSUMING STATE $state" }
                val value = propagateStates<S, R>(state)
                Store.logIfEnabled { "PROPAGATING STATES $value" }
                return@map Optional.Some(value)
            }
            .distinctUntilChanged()
            .observeOn(mainScheduler)
}

typealias Selector<S, R> = (ObservableWrapper<S>) -> ObservableWrapper<R>

fun <S : Any, R : Any?> Store<S>.select(selector: Selector<S, R>): ObservableWrapper<R> = selector(state)

fun <S : Any?, R : Any?> createSelector(selectorFunction: SelectorFunction<S, R>): Selector<S, R> =
        { observable -> SelectorSubject<S, R>(observable, selectorFunction as SelectorFunction<Any?, Any?>).wrap() }

fun <S : Any, R1 : Any?, R2 : Any?> Selector<S, R1>.compose(selectorFunction: SelectorFunction<R1, R2>): Selector<S, R2> =
        { observable -> createSelector(selectorFunction)(this(observable)).wrap() }
