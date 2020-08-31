import kotlinx.atomicfu.atomic
import kotlinx.coroutines.CoroutineDispatcher
import kotlin.test.AfterTest
import kotlin.test.BeforeTest

/**
 * Description:
 */

open class BaseTest {

    var dispatcher = atomic<CoroutineDispatcher?>(null)

    @BeforeTest
    fun setupScheduler() {
        dispatcher.value = applyTestSchedulers()
    }

    @AfterTest
    fun teardownScheduler() {
        teardownSchedulers(dispatcher.value)
        dispatcher.value = null
    }
}