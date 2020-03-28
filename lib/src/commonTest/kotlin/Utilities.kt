import com.badoo.reaktive.disposable.Disposable
import com.badoo.reaktive.scheduler.overrideSchedulers
import com.badoo.reaktive.test.scheduler.TestScheduler

fun Disposable.use(fn: () -> Unit) {
    fn()
    dispose()
}

fun applyTestSchedulers() {
    overrideSchedulers(
            main = { TestScheduler() },
            computation = { TestScheduler() },
            io = { TestScheduler() },
            trampoline = { TestScheduler() },
            single = { TestScheduler() },
            newThread = { TestScheduler() }
    )
}
