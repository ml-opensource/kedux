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
interface Action<T : Any, P : Any?> {

    val type: T

    val payload: P
}

abstract class ActionCreator<T : Any, A : Any?, P : Any?> {

    abstract fun create(arguments: A): Action<T, P>

    operator fun invoke(arguments: A) = create(arguments)
}

class TypedActionCreator<T : Any, A : Any?, P : Any?>(
        private val ofType: T,
        private val payloadCreator: (arguments: A) -> P) : ActionCreator<T, A, P>() {
    override fun create(arguments: A): Action<T, P> = object : Action<T, P> {
        override val type: T = ofType
        override val payload: P = payloadCreator(arguments)
    }
}

class SingleAction<T : Any>(override val type: T) : Action<T, Unit> {
    override val payload: Unit = Unit
}

/**
 * Creates an [ActionCreator] based on [type] and supplied [payloadCreator].
 */
fun <T : Any, A : Any, P : Any?> createAction(
        type: T,
        payloadCreator: (arguments: A) -> P
): ActionCreator<T, A, P> = TypedActionCreator(type, payloadCreator)

/**
 * Creates an [Action] based on [type] without any payload or arguments.
 */
fun <T : Any> createAction(type: T): Action<T, Unit> = SingleAction(type)
