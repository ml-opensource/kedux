import kotlinx.coroutines.Job

fun applyTestSchedulers() {
}

fun Job.use(fn: () -> Unit) {
    fn()
    cancel()
}
