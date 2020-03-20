import com.badoo.reaktive.disposable.Disposable

fun Disposable.use(fn: () -> Unit) {
    fn()
    dispose()
}
