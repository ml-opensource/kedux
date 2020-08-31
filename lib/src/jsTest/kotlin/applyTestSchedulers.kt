import kotlinx.coroutines.CoroutineDispatcher

actual fun applyTestSchedulers(): CoroutineDispatcher? = null

actual fun teardownSchedulers(dispatcher: CoroutineDispatcher?) {
}