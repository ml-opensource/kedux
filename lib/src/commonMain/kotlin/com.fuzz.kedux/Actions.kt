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
 * A class Action class, this is used to provide actions that are not purely class types. This is for class use, but
 * preferably use data class objects.
 */
interface Action<T> {

    val type: T
}
