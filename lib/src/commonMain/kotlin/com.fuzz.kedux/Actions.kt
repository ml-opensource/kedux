package com.fuzz.kedux

/**
 * Supports multiple actions dispatches in order provided through this object.
 *
 * ```kotlin
 * MultiAction(ExampleAction(), AnotherAction("Name")).
 * ```
 */
data class MultiAction(val actions: List<Any>)

/**
 * Type marker explicity stating that this action should not dispatch when received.
 */
object NoAction

/**
 * Constructs an object that contains multiple, sequential objects. See [MultiAction]
 */
fun multipleActionOf(vararg actions: Any) = MultiAction(actions.toList())

/**
 * This is used to provide actions that are not purely class types. This is for classic use, but
 * preferably use data class objects.
 */
interface Action<T: Any, P : Any?> {

    val type: T

    val payload: P
}

typealias ActionCreator<T, A, P> = (arguments: A) -> Action<T, P>

/**
 * Creates an [ActionCreator] based on [type] and supplied [payloadCreator].
 */
inline fun <T: Any, A, P> createAction(type: T, crossinline payloadCreator: (arguments: A) -> P): ActionCreator<T, A, P> = { arguments: A ->
    object : Action<T, P> {
        override val type: T = type
        override val payload: P = payloadCreator(arguments)
    }
}

/**
 * Creates an [ActionCreator] based on [type] and no argument [payloadCreator].
 */
inline fun <T: Any, P> createAction(type: T, crossinline payloadCreator: () -> P): ActionCreator<T, Unit, P> = createAction<T, Unit, P>(type) { payloadCreator() }

/**
 * Creates an [Action] based on [type] without any payload or arguments.
 */
fun <T: Any> createAction(type: T): Action<T, Unit> = createAction<T, Unit, Unit>(type) {}(Unit)
