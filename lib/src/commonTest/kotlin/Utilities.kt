import kotlinx.coroutines.CoroutineName
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.Job

expect fun applyTestSchedulers()
expect fun teardownSchedulers()

val testScope: CoroutineScope by lazy { CoroutineScope(Dispatchers.Main + CoroutineName("TEST SCOPE")) }

suspend fun Job.use(fn: suspend () -> Unit) {
    fn()
    cancel()
}
