package com.fuzz.kedux

import com.badoo.reaktive.disposable.CompositeDisposable
import com.badoo.reaktive.disposable.addTo
import com.badoo.reaktive.observable.Observable
import com.badoo.reaktive.observable.ObservableWrapper
import com.badoo.reaktive.observable.map
import com.badoo.reaktive.observable.ofType
import com.badoo.reaktive.observable.wrap

/**
 * Typealias to a function that takes in an [ObservableWrapper] representing the streams of actions from the [Store] and
 * returns a new [ObservableWrapper] stream with the return type [R] specified.
 *
 * Effects are side-effects to actions dispatched onto the [Store]. They usually return a new Action, [Pair] of Actions,
 * [Triple] of Actions, [MultiAction], or [].
 */
typealias Effect<R> = (actions: ObservableWrapper<Any>) -> ObservableWrapper<R>

/**
 * Creates an [Effect], an [Observable] chain that returns an Action or set of [MultiAction] objects that get dispatched back
 * to the store.
 *
 * Usage:
 * ```kotlin
 * val effect = createEffect<LoadUsers, UsersReceived> { actionObservable ->
 *     actionObservable.flatMap { (userId) -> userService.getUsers(userId) }
 *      .map { users -> UsersReceived(users) }
 * }
 * ```
 */
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
 * Creates an [Effect], an [Observable] chain that returns an Action or set of [MultiAction] objects that get dispatched back
 * to the store.
 *
 * Usage:
 * ```kotlin
 * val effect = createActionTypeEffect<Action<LoadUsers, List<User>>, Action<LoadUsersReceived, List<User>> { actionObservable ->
 *     actionObservable.flatMap { (userId) -> userService.getUsers(userId) }
 *      .map { users -> usersReceived(users) }
 * }
 * ```
 */
inline fun <T: Any, P, R: Any, RP> createActionTypeEffect(crossinline mapper: (ObservableWrapper<Action<T, P>>) -> Observable<Action<R, RP>>): Effect<Action<R, RP>> =
        { actions: ObservableWrapper<Any> -> mapper(actions.ofType<Action<T, P>>().wrap()).wrap() }

/**
 * Groups a set of [Effect] into a singular scoped unit. Handles registration to the [Store].
 *
 * Scope Effects groupings globally when at Store creation time:
 * ```kotlin
 *
 * store = createStore(...)
 *  .also { effects.bindTo(it) }
 *
 * ```
 *
 * Or Scope Effect groupings at a smaller level, such as within a particular flow in your application:
 *
 * Usage:
 * ```kotlin
 *
 * val userEffect = Effects(effect1, effect2, effectN)
 *
 * // bind to store when object in scope
 * userEffect.bindTo(store)
 *
 * // remove subscriptions to Store when out of scope.
 * userEffect.clearBindings()
 *
 * ```
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
     * Clears out bindings to this [Effects] object. Useful for when Effects are scoped to a smaller subset of your application.
     */
    fun clearBindings() {
        compositeDisposable.clear(dispose = false)
    }
}
