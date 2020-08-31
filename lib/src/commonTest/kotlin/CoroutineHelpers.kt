import kotlinx.coroutines.CoroutineScope

/**
 * Workaround to use suspending functions in unit tests
 */
expect fun  runBlocking(block: suspend CoroutineScope.() -> Unit)
