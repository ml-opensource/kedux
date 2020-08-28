import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.newSingleThreadContext
import kotlinx.coroutines.test.resetMain
import kotlinx.coroutines.test.setMain

private val mainThreadSurrogate = newSingleThreadContext("UI thread")

actual fun applyTestSchedulers() {
    Dispatchers.setMain(mainThreadSurrogate)
}

actual fun teardownSchedulers() {
    Dispatchers.resetMain()
}