import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.launch

/**
 * Workaround to use suspending functions in unit tests
 */
actual fun runBlocking(block: suspend CoroutineScope.() -> Unit) {
    GlobalScope.launch { block(this) }
}
