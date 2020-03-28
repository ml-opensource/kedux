package com.fuzz.kedux

import com.badoo.reaktive.disposable.CompositeDisposable
import com.badoo.reaktive.disposable.addTo
import com.badoo.reaktive.observable.Observable
import com.badoo.reaktive.observable.ObservableWrapper
import com.badoo.reaktive.observable.map
import com.badoo.reaktive.observable.ofType
import com.badoo.reaktive.observable.wrap

typealias Effect<R> = (actions: ObservableWrapper<Any>) -> ObservableWrapper<R>

inline fun <reified A : Any, R : Any> createEffect(crossinline mapper: (ObservableWrapper<A>) -> Observable<R>): Effect<R> =
        { actions: ObservableWrapper<Any> -> mapper(actions.ofType<A>().wrap()).wrap() }

/**
 * Creates an [Effect] that does not dispatch back to the [Store]. These kind of [Effect] are useful for pure side effects
 * such as logging, or one-shot calls to other dependencies.
 *
 * Usage:
 * ```kotlin
 * val effect = createSilentEffect<InputAction, OutputAction> { actionObservable ->
 *     actionObservable.flatMap { (userId) -> userService.getUsers(userId) }
 * }
 * ```
 */
inline fun <reified A : Any> createSilentEffect(crossinline mapper: (ObservableWrapper<A>) -> Observable<Unit>): Effect<NoAction> =
        { actions: ObservableWrapper<Any> -> mapper(actions.ofType<A>().wrap()).map { NoAction }.wrap() }

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

    /**
     * Binds all [Effect] to the specified store. Will ignore [createSilentEffect] classes or [Effect] that return
     * [NoAction].
     */
    fun bindTo(store: Store<*>) {
        effects.forEach { effect ->
            effect(store.actions)
                    .subscribe { action -> dispatch(store, action) }
                    .addTo(compositeDisposable)
        }
    }

    /**
     * Clears out bindings to this [Effects] object. Useful for scoping effects.
     */
    fun clearBindings() {
        compositeDisposable.clear(dispose = false)
    }
}
