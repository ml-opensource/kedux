@file:Suppress("UNCHECKED_CAST")

package com.fuzz.kedux

import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Job
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.filter
import kotlinx.coroutines.flow.launchIn
import kotlinx.coroutines.flow.map
import kotlinx.coroutines.flow.onEach
import kotlin.js.JsName
import kotlin.reflect.KClass

/**
 * Typealias to a function that takes in an [ObservableWrapper] representing the streams of actions from the [Store] and
 * returns a new [ObservableWrapper] stream with the return type [R] specified.
 *
 * Effects are side-effects to actions dispatched onto the [Store]. They usually return a new Action, [Pair] of Actions,
 * [Triple] of Actions, [MultiAction], or [].
 */
abstract class EffectFn<R : Any> {
    abstract operator fun invoke(actions: CFlow<Any>): Flow<R>
}

expect class Effect<A : Any, R : Any> : EffectFn<R>
expect class SilentEffect<A : Any> : EffectFn<NoAction>
expect class ActionTypeEffect<T : Any, P, R : Any, RP> : EffectFn<Action<R, RP>>

class EffectClass<A : Any, R : Any>(
        private val actionClass: KClass<A>,
        private val mapper: (CFlow<A>) -> Flow<R>
) : EffectFn<R>() {
    override fun invoke(actions: CFlow<Any>): Flow<R> =
            mapper(actions.filter { actionClass.isInstance(it) }.map { it as A }.wrap())
}

class SilentEffectClass<A : Any>(
        private val actionClass: KClass<A>,
        private val mapper: (CFlow<A>) -> Flow<Unit>
) : EffectFn<NoAction>() {
    override fun invoke(actions: CFlow<Any>): Flow<NoAction> =
            mapper(actions.filter { actionClass.isInstance(it) }.map { it as A }.wrap()).map { NoAction }
}

class ActionTypeEffectClass<T : Any, P, R : Any, RP>(
        private val mapper: (CFlow<Action<T, P>>) -> Flow<Action<R, RP>>
) : EffectFn<Action<R, RP>>() {
    override fun invoke(actions: CFlow<Any>): Flow<Action<R, RP>> =
            mapper(actions.ofType<Action<T, P>>().wrap())
}

/**
 * Creates an [EffectFn], an [ObservingDef] chain that returns an Action or set of [MultiAction] objects that get dispatched back
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
inline fun <reified A : Any, R : Any> createEffect(noinline mapper: (Flow<A>) -> Flow<R>): EffectFn<R> =
        EffectClass(A::class, mapper)

/**
 * Creates an [EffectFn] that does not dispatch back to the [Store]. These kind of [EffectFn] are useful for pure side effects
 * such as logging, or one-shot calls to other dependencies.
 *
 * Usage:
 * ```kotlin
 * val effect = createSilentEffect<InputAction, OutputAction> { actionObservable ->
 *     actionObservable.flatMap { (userId) -> userService.getUsers(userId) }
 * }
 * ```
 */
inline fun <reified A : Any> createSilentEffect(noinline mapper: (Flow<A>) -> Flow<Unit>): EffectFn<NoAction> =
        SilentEffectClass(A::class, mapper)

/**
 * Creates an [EffectFn], an [ObservingDef] chain that returns an Action or set of [MultiAction] objects that get dispatched back
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
fun <T : Any, P, R : Any, RP> createActionTypeEffect(mapper: (Flow<Action<T, P>>) -> Flow<Action<R, RP>>): EffectFn<Action<R, RP>> =
        ActionTypeEffectClass(mapper)

/**
 * Groups a set of [EffectFn] into a singular scoped unit. Handles registration to the [Store].
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
class Effects(vararg effectArgs: EffectFn<out Any>) {

    private val effects = effectArgs

    private val jobList = mutableListOf<Job>()

    private fun dispatch(store: Store<*>, action: Any) {
        Store.logIfEnabled { "dispatch (effects) -> $action" }
        store.dispatch(action)
    }

    fun bindTo(store: Store<*>) {
        effects.forEach { effect ->
            jobList += effect(store.actions)
                    .onEach { action -> dispatch(store, action) }
                    .launchIn(backgroundScope())
        }
    }

    /**
     * Binds all [EffectFn] to the specified store. Will ignore [createSilentEffect] classes or [EffectFn] that return
     * [NoAction].
     */
    @JsName("bindToWithScope")
    fun bindTo(store: Store<*>,
               scope: CoroutineScope = backgroundScope()) {
        effects.forEach { effect ->
            jobList += effect(store.actions)
                    .onEach { action -> dispatch(store, action) }
                    .launchIn(scope)
        }
    }

    /**
     * Clears out bindings to this [Effects] object. Useful for when Effects are scoped to a smaller subset of your application.
     */
    fun clearBindings() {
        jobList.forEach { it.cancel() }
        jobList.clear()
    }
}
