import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.launch

actual fun runBlocking(block: suspend CoroutineScope.() -> Unit) {
    GlobalScope.launch {
        block.invoke(this)
    }
}
