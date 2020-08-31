import kotlinx.coroutines.CoroutineDispatcher
import kotlinx.coroutines.CoroutineName
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.Job

expect fun applyTestSchedulers(): CoroutineDispatcher?
expect fun teardownSchedulers(dispatcher: CoroutineDispatcher?)

fun getTestScope(): CoroutineScope = CoroutineScope(Dispatchers.Main + CoroutineName("TEST SCOPE"))

suspend fun Job.use(fn: suspend () -> Unit) {
    fn()
    cancel()
}
