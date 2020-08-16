import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.launch
import kotlin.test.fail

actual fun runBlocking(block: suspend CoroutineScope.() -> Unit) {
    GlobalScope.launch {
        try {
            block.invoke(this)
        } catch (e: Exception) {
            fail(e.message)
        }
    }
}
