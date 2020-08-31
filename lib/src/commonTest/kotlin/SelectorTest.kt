import app.cash.turbine.test
import com.fuzz.kedux.Store
import com.fuzz.kedux.createStore
import kotlin.test.BeforeTest
import kotlin.test.Test
import logAssertEquals as assertEquals

class SelectorTest : BaseTest() {

    private lateinit var store: Store<GlobalState>

    @BeforeTest
    fun constructStore() {
        Store.loggingEnabled = true
        store = createStore(sampleReducer, initialState)
    }

    @Test
    fun selectorEmitsAllValues() = runBlocking {
        store.select(nameSelector).test {
            // initial state
            assertEquals("", expectItem())

            repeat(3) {
                store.dispatch(StoreTestAction.NameChange("Name$it"))
                assertEquals("Name$it", expectItem())
                store.dispatch(StoreTestAction.NameChange("Name2-$it"))
                assertEquals("Name2-$it", expectItem())
            }
        }
    }

    @Test
    fun selectorSelectivelyEmitsValues() = runBlocking {
        store.select(nameSelector).test {
            // initial state
            assertEquals("", expectItem())

            repeat(3) {
                store.dispatch(StoreTestAction.NameChange("Name$it"))
                store.dispatch(StoreTestAction.NameChange("Name$it"))
                assertEquals("Name$it", expectItem())
            }
            expectNoEvents()
        }
    }

    @Test
    fun composeSelectors() = runBlocking {
        store.select(locationIdSelector).test {
            // initial state
            assertEquals(null, expectItem())

            repeat(3) {
                store.dispatch(StoreTestAction.LocationChange(Location(5, "1")))
                store.dispatch(StoreTestAction.LocationChange(Location(5, "1")))
                store.dispatch(StoreTestAction.NameChange("New Name"))
            }
            assertEquals(5, expectItem())
            expectNoEvents()
        }
    }

    @Test
    fun composeSelectors3() = runBlocking {
        store.select(locationProductIdSelector).test {
            // initial state
            assertEquals(null, expectItem())

            repeat(3) {
                store.dispatch(
                        StoreTestAction.LocationChange(
                                Location(
                                        5,
                                        "1",
                                        product = Product(5, "Burger")
                                )
                        )
                )
                store.dispatch(
                        StoreTestAction.LocationChange(
                                Location(
                                        5,
                                        "1",
                                        product = Product(5, "Burger")
                                )
                        )
                )
                store.dispatch(StoreTestAction.NameChange("New Name"))
            }

            assertEquals(5, expectItem())
            expectNoEvents()
        }
    }
}

