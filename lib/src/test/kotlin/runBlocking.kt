import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.ExperimentalCoroutinesApi
import kotlinx.coroutines.test.runBlocking

@ExperimentalCoroutinesApi
actual fun runBlocking(block: suspend CoroutineScope.() -> Unit) = runBlockingTest(testBody = block)
