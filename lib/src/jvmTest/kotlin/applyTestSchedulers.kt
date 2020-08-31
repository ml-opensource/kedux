import kotlinx.coroutines.CoroutineDispatcher
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.test.TestCoroutineDispatcher
import kotlinx.coroutines.test.resetMain
import kotlinx.coroutines.test.setMain

actual fun applyTestSchedulers(): CoroutineDispatcher? {
    return TestCoroutineDispatcher().also { Dispatchers.setMain(it) }
}

actual fun teardownSchedulers(dispatcher: CoroutineDispatcher?) {
    (dispatcher as TestCoroutineDispatcher?)?.cleanupTestCoroutines()
    Dispatchers.resetMain()
}

