import kotlin.test.AfterTest
import kotlin.test.BeforeTest

/**
 * Description:
 */

open class BaseTest {

    @BeforeTest
    fun setupScheduler() {
        applyTestSchedulers()
    }

    @AfterTest
    fun teardownScheduler() {
        teardownSchedulers()
    }
}