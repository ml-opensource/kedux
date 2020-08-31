import app.cash.turbine.test
import com.fuzz.kedux.Store
import com.fuzz.kedux.combineReducers
import com.fuzz.kedux.createStore
import kotlin.test.BeforeTest
import kotlin.test.Test
import logAssertEquals as assertEquals


class TypedActionTest : BaseTest() {

    private lateinit var store: Store<GlobalState>

    @BeforeTest
    fun constructStore() {
        Store.loggingEnabled = true
        store = createStore(combineReducers(sampleTypedReducer), initialState)
    }

    @Test
    fun testTypedReducer() = runBlocking {
        store.select(getNameSelector()).test {
            // initial state
            assertEquals("", expectItem())

            store.dispatch(nameChange("NEW NAME"))
            assertEquals("NEW NAME", expectItem())
        }
    }

    @Test
    fun testLocationChangeReducer() = runBlocking {
        store.select(getLocationSelector()).test {
            // initial state
            assertEquals(null, expectItem())

            val updatedLocation = Location(5, "Other")
            store.dispatch(locationChange(updatedLocation))
            assertEquals(updatedLocation, expectItem())
        }
    }

    @Test
    fun testResetActionType() = runBlocking {
        store.select(getLocationSelector())
                .test {
                    // initial state
                    assertEquals(null, expectItem())

                    val updatedLocation = Location(5, "Other")
                    store.dispatch(locationChange(updatedLocation))
                    assertEquals(updatedLocation, expectItem())

                    store.dispatch(resetAction)
                    assertEquals(initialState.location, expectItem())
                }
    }
}
