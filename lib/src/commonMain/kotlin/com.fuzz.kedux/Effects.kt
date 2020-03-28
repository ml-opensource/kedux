package com.fuzz.kedux

import com.badoo.reaktive.disposable.CompositeDisposable
import com.badoo.reaktive.disposable.addTo
import com.badoo.reaktive.observable.Observable
import com.badoo.reaktive.observable.ObservableWrapper
import com.badoo.reaktive.observable.ofType
import com.badoo.reaktive.observable.wrap

typealias Effect<R> = (actions: ObservableWrapper<Any>) -> ObservableWrapper<R>

inline fun <reified A : Any, R : Any> createEffect(crossinline mapper: (ObservableWrapper<A>) -> Observable<R>): Effect<R> =
        { actions: ObservableWrapper<Any> -> mapper(actions.ofType<A>().wrap()).wrap() }

/**
 * Groups a set of [Effect] into a singular scoped unit. Handles registration to the [Store].
 */
class Effects(vararg effectArgs: Effect<out Any>) {

    private val effects = effectArgs

    private val compositeDisposable = CompositeDisposable()

    private fun dispatch(store: Store<*>, action: Any) {
        store.dispatch(action)
        Store.logIfEnabled { "EFFECTS: Dispatching New Action $action" }
    }

    fun bindTo(store: Store<*>) {
        effects.forEach { effect ->
            effect(store.actions).subscribe { action -> dispatch(store, action) }
                    .addTo(compositeDisposable)
        }
    }

    fun dispose() {
        compositeDisposable.dispose()
    }
}
