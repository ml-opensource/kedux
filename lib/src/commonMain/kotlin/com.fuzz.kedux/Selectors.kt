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

typealias SelectorFunction<S, R> = (state: S) -> R
typealias Selector<S, R> = SelectorFunction<ObservableWrapper<S>, ObservableWrapper<R>>

class SelectorSubject<S : Any?, R : Any?> internal constructor(
        private val state: Observable<S>,
        private val selectorFunction: SelectorFunction<S, R>,
        private val _stateSubject: Subject<Optional<R>> = BehaviorSubject(Optional.None())
) : Observable<R> by _stateSubject.safeUnwrap() {

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

    private fun stateChange(): Observable<Optional<R>> = state
            .subscribeOn(computationScheduler)
            .distinctUntilChanged()
            .map { state ->
                Store.logIfEnabled { "CONSUMING STATE $state" }
                val value = selectorFunction(state)
                Store.logIfEnabled { "PROPAGATING STATES $value" }
                return@map Optional.Some(value)
            }
            .distinctUntilChanged()
            .observeOn(mainScheduler)
}

fun <S : Any?, R : Any?> createSelector(selectorFunction: SelectorFunction<S, R>): Selector<S, R> =
        { observable -> SelectorSubject(observable, selectorFunction).wrap() }

fun <S : Any, R1 : Any?, R2 : Any?> Selector<S, R1>.compose(selectorFunction: SelectorFunction<R1, R2>): Selector<S, R2> =
        { observable -> createSelector(selectorFunction)(this(observable)).wrap() }
