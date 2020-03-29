package com.fuzz.kedux

import com.badoo.reaktive.observable.Observable
import com.badoo.reaktive.observable.filter
import com.badoo.reaktive.observable.flatMap
import com.badoo.reaktive.observable.map
import com.badoo.reaktive.observable.onErrorReturn

data class LoadingModel<T>(
        val isLoading: Boolean,
        private val hasError: Boolean,
        private val hasSuccess: Boolean,
        private val internalSuccess: T? = null,
        private val internalError: Error? = null
) {
    val isSuccess = hasSuccess

    val isError = hasError

    val isEmpty = !isSuccess && !isError

    val optionalSuccess: T? = internalSuccess

    val success: T
        get() = internalSuccess!!

    val optionalError: Error? = internalError

    val error: Error
        get() = internalError!!

    fun loading(success: T? = internalSuccess) =
            LoadingModel(
                    isLoading = true,
                    hasError = false,
                    hasSuccess = this.hasSuccess,
                    internalSuccess = success
            )

    companion object {

        fun <T> success(success: T?) = LoadingModel(
                isLoading = false,
                hasError = false,
                hasSuccess = true,
                internalSuccess = success
        )

        fun <T> error(error: Error?, optionalSuccess: T? = null) = LoadingModel<T>(
                isLoading = false,
                hasError = true,
                hasSuccess = false,
                internalError = error,
                internalSuccess = optionalSuccess
        )

        fun <T> empty() = LoadingModel<T>(
                isLoading = false,
                hasSuccess = false,
                hasError = false
        )

    }
}

sealed class LoadingActionTypes {
    data class Request(val name: String) : LoadingActionTypes()
    data class Success(val name: String) : LoadingActionTypes()
    data class Error(val name: String) : LoadingActionTypes()
    data class Clear(val name: String) : LoadingActionTypes()
}

data class LoadingAction<AT : LoadingActionTypes, P>(
        override val type: AT,
        override val payload: P) : Action<AT, P>

internal fun <T : LoadingActionTypes, A> createLoadingAction(type: T): ActionCreator<T, A, A> = { arguments: A ->
    LoadingAction(type, payload = arguments)
}

/**
 * Creates an object that contains an [Effect], [Reducer], and set of actions that represent loading
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
class KeduxLoader<TRequest, TSuccess>(private val name: String, private val requester: (args: TRequest) -> Observable<TSuccess>) {

    val request = createLoadingAction<LoadingActionTypes.Request, TRequest>(LoadingActionTypes.Request(name))

    val success = createLoadingAction<LoadingActionTypes.Success, TSuccess>(LoadingActionTypes.Success(name))

    val error = createLoadingAction<LoadingActionTypes.Error, Error>(LoadingActionTypes.Error(name))

    val clear = LoadingAction(LoadingActionTypes.Clear(name), Unit)

    @Suppress("UNCHECKED_CAST")
    val reducer = actionTypeReducer { s: LoadingModel<TSuccess>, action: Action<LoadingActionTypes, *> ->
        when (action.type) {
            LoadingActionTypes.Request(name) -> s.loading()
            LoadingActionTypes.Success(name) -> LoadingModel.success(action.payload as TSuccess?)
            LoadingActionTypes.Clear(name) -> LoadingModel.empty()
            LoadingActionTypes.Error(name) -> LoadingModel.error(action.payload as Error?,
                    s.optionalSuccess)
            else -> s
        }
    }

    val effect = createActionTypeEffect<LoadingActionTypes.Request, TRequest, LoadingActionTypes.Success, TSuccess> { action ->
        action.filter { it.type == LoadingActionTypes.Request(name) }.flatMap { requester(it.payload) }
                .onErrorReturn { error(it) }
                .map { success(it) }
    }

}

/**
 * Compose selector that only emits a computation if theres a [LoadingModel.success] state.
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
