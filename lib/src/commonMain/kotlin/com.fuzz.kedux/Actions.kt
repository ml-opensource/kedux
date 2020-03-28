package com.fuzz.kedux

/**
 * Supports multiple actions dispatches in order provided through this object.
 *
 * MultiAction(ExampleAction(), AnotherAction("Name")).
 */
data class MultiAction(val actions: List<Any>)

/**
 * Constructs an object that contains multiple, sequential objects. See [MultiAction]
 */
fun multipleActionOf(vararg actions: Any) = MultiAction(*actions.toList())
