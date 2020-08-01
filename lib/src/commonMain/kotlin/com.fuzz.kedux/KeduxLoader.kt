package com.fuzz.kedux

import com.badoo.reaktive.observable.Observable
import com.badoo.reaktive.observable.filter
import com.badoo.reaktive.observable.flatMap
import com.badoo.reaktive.observable.map
import com.badoo.reaktive.observable.onErrorReturn
import com.badoo.reaktive.utils.printStack

/**
 * Data representation of a loading state. Useful for network requests.
 *
 * Do not construct this object directly. Use one of the helper methods [LoadingModel.success],
 * [LoadingModel.error], [LoadingModel.empty], or [loading]
 */
data class LoadingModel<T>
internal constructor(
        val isLoading: Boolean,
        val isError: Boolean,
        val isSuccess: Boolean,
        val optionalSuccess: T? = null,
        val optionalError: Throwable? = null
) {
    /**
     * This object is considered empty if it has no success, error, or is not loading.
     */
    val isEmpty = !isSuccess && !isError && !isLoading

    /**
     * Returns the non-null [T], using force unwrapping.
     */
    val success: T
        get() = optionalSuccess!!

    /**
     * Returns the non-null [Throwable], using force unwrapping.
     */
    val error: Throwable
        get() = optionalError!!

    /**
     * Returns a new [LoadingModel] instance that is set to trigger loading.
     *
     * This wipes out any errors and keeps the previous [optionalSuccess]. If you wish to clear it,
     * call loading(null). This is useful when using a pull to refresh callback, or reloading newer
     * information in the UI.
     */
    fun loading(success: T? = optionalSuccess) =
            LoadingModel(
                    isLoading = true,
                    isError = false,
                    isSuccess = this.isSuccess,
                    optionalSuccess = success
            )

    companion object {

        /**
         * Constructs a new [LoadingModel] with a success value. May pass null here.
         */
        fun <T> success(success: T?) = LoadingModel(
                isLoading = false,
                isError = false,
                isSuccess = true,
                optionalSuccess = success
        )

        /**
         * Constructs a new [LoadingModel] with an error value. May pass null here. Also,
         * can supply an [optionalSuccess] if you wish to preserve the last successful data, or provide
         * fallback data in the case something uses this object to display its success criteria.
         */
        fun <T> error(error: Throwable?, optionalSuccess: T? = null) = LoadingModel<T>(
                isLoading = false,
                isError = true,
                isSuccess = false,
                optionalError = error,
                optionalSuccess = optionalSuccess
        )

        /**
         * Constructs a new, default empty version of the model with no success or error information.
         * This is useful for default redux state, or to signify data has not tried to load yet.
         *
         * Empty also represents the state when data gets cleared.
         */
        fun <T> empty() = LoadingModel<T>(
                isLoading = false,
                isSuccess = false,
                isError = false
        )

    }
}

/**
 * The set of loading action types that [KeduxLoader] generate.
 */
sealed class LoadingActionTypes {

    /**
     * Represents the action type for when a [KeduxLoader] requests data, to trigger a [LoadingModel.loading]
     * state.
     *
     * @param name - The unique ID of the [KeduxLoader] action.
     */
    data class Request(val name: String) : LoadingActionTypes()

    /**
     * A successful response type.
     *
     * @param name - The unique ID of the [KeduxLoader] action.
     */
    data class Success(val name: String) : LoadingActionTypes()

    /**
     * An error occurred.
     * @param name - The unique ID of the [KeduxLoader] action.
     */
    data class Error(val name: String) : LoadingActionTypes()

    /**
     * Represents the action type for when a [KeduxLoader] requests to clear data.
     * Triggers a [LoadingModel.empty].
     * @param name - The unique ID of the [KeduxLoader] action.
     */
    data class Clear(val name: String) : LoadingActionTypes()
}

/**
 * Represents an action type that uses the [LoadingActionTypes] with a specified payload. The data
 * in redux is backed by a [LoadingModel].
 */
data class LoadingAction<AT : LoadingActionTypes, P : Any?>(
        override val type: AT,
        override val payload: P) : Action<AT, P>

/**
 * Creates a new action generator that allows the specified [A] payload argument type.
 */
internal fun <T : LoadingActionTypes, A : Any?> createLoadingAction(type: T): ActionCreator<T, A, A> = object : ActionCreator<T, A, A>() {
    override fun create(arguments: A): Action<T, A> = LoadingAction(type, payload = arguments)
}

/**
 * Creates a new action generator that allows the specified [A] payload argument type that generates
 * the payload with the specified [payloadCreator].
 */
internal fun <T : LoadingActionTypes, A : Any?, P : Any?> createLoadingAction(
        type: T,
        payloadCreator: (arguments: A) -> P): ActionCreator<T, A, P> = object : ActionCreator<T, A, P>() {
    override fun create(arguments: A): Action<T, P> = LoadingAction(type, payload = payloadCreator(arguments))
}

/**
 * Creates an object that contains an [EffectFn], [Reducer], and set of actions that represent loading
 * state in a structured way.
 *
 * Usage:
 * ```kotlin
 * val userLoadingState = KeduxLoader<Int, User>("user") { id -> userService.getUser(id) }
 *
 * store.dispatch(userLoadingState.request(5))
 *
 * val userLoadingStateSelector = createSelector { state: State -> state.user }
 *
 * // convenience extensions on selectors
 * store.select(userLoadingStateSelector)
 *  .success()
 *  .subscribe { success ->
 *   // only returns if there's a success value
 *  }
 *  .addTo(disposable)
 * ```
 */
class KeduxLoader<TRequest : Any, TSuccess : Any>(
        private val name: String,
        private val requester: (args: TRequest) -> Observable<TSuccess>) {

    /**
     * Request action creator. Use it to dispatch on the store.
     *
     * Usage:
     *
     * request(TRequest) returns Action<LoadingActionTypes.Request, TRequest>
     *
     * store.dispatch(loader.request(requestPayload))
     */
    val request = createLoadingAction<LoadingActionTypes.Request, TRequest>(LoadingActionTypes.Request(name))

    /**
     * Request success creator. Use it to dispatch on the store.
     *
     * Usage:
     *
     * success(TSuccess) returns Action<LoadingActionTypes.Success, TSuccess>
     *
     * store.dispatch(loader.success(successPayload))
     */
    val success = createLoadingAction<LoadingActionTypes.Success, TSuccess>(LoadingActionTypes.Success(name))


    /**
     * Request error creator. Use it to dispatch on the store.
     *
     * Usage:
     *
     * error(Throwable) returns Action<LoadingActionTypes.Error, Throwable>
     *
     * store.dispatch(loader.error(e))
     */
    val error = createLoadingAction<LoadingActionTypes.Error, Throwable>(LoadingActionTypes.Error(name))

    /**
     * Clear action. Use it to dispatch on the store. Only one is necessary as it takes no arguments
     * on clearing data. Clearing is a complete wipe of the [KeduxLoader] data.
     *
     * Usage:
     *
     * store.dispatch(loader.clear)
     */
    val clear = LoadingAction(LoadingActionTypes.Clear(name), Unit)

    /**
     * The generated reducer that does all of the work for you. Place this reducer as part of a [FracturedState]
     * or as part of another reducer to automate data handling.
     *
     * Usage:
     * ```kotlin
     * val reducer = anyReducer { state: State, action: Any ->
     *   when(action) {
     *     // catch all Loading action types here and modify state.
     *     is LoadingAction<*, *> -> {
     *       state.copy(
     *          product = loader.reducer.reduce(state.product, action),
     *          otherLoading = otherLoader.reducer.reduce(state.otherLoading, action),
     *       )
     *     }
     *   }
     * }
     * ```
     */
    @Suppress("UNCHECKED_CAST")
    val reducer = actionTypeReducer { s: LoadingModel<TSuccess>, action: Action<LoadingActionTypes, *> ->
        when (action.type) {
            LoadingActionTypes.Request(name) -> s.loading()
            LoadingActionTypes.Success(name) -> LoadingModel.success(action.payload as TSuccess?)
            LoadingActionTypes.Clear(name) -> LoadingModel.empty()
            LoadingActionTypes.Error(name) -> LoadingModel.error(action.payload as Throwable?,
                    s.optionalSuccess)
            else -> s
        }
    }

    /**
     * Apply this generated effect into the application [Effects] class. This will coordinate request,
     * success, and errors using the [requester] supplied in the loader.
     */
    @Suppress("UNCHECKED_CAST")
    val effect = createActionTypeEffect<LoadingActionTypes, TRequest, LoadingActionTypes, Any> { action ->
        action.filter { it.type == LoadingActionTypes.Request(name) }
                .flatMap { request -> requester(request.payload) }
                .map { success(it) }
                .onErrorReturn {
                    it.printStack()
                    this.error(it)
                } as Observable<Action<LoadingActionTypes, Any>>
    }

}

/**
 * Compose selector that only emits a computation if there's a [LoadingModel.success] state.
 */
fun <S : Any, T> Selector<S, LoadingModel<T>>.success() = compose({ filter { it.optionalSuccess != null } }) { state -> state.success }

/**
 * Compose selector that returns the [LoadingModel.optionalSuccess] state.
 */
fun <S : Any, T> Selector<S, LoadingModel<T>>.optionalSuccess() = compose { state -> state.optionalSuccess }

/**
 * Compose selector that only emits a computation if theres a [LoadingModel.error] state.
 */
fun <S : Any, T> Selector<S, LoadingModel<T>>.error() = compose({ filter { it.optionalError != null } }) { state -> state.error }

/**
 * Compose selector that returns the [LoadingModel.optionalError] state.
 */
fun <S : Any, T> Selector<S, LoadingModel<T>>.optionalError() = compose { state -> state.optionalError }

/**
 * Compose selector that returns the [LoadingModel.isLoading] value.
 */
fun <S : Any, T> Selector<S, LoadingModel<T>>.loading() = compose { state -> state.isLoading }
