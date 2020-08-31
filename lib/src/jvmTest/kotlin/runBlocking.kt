import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.ExperimentalCoroutinesApi
import kotlinx.coroutines.test.runBlockingTest

/**
 * Workaround to use suspending functions in unit tests
 */
@ExperimentalCoroutinesApi
actual fun runBlocking(block: suspend CoroutineScope.() -> Unit) = runBlockingTest(testBody = block)
