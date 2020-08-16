import com.fuzz.kedux.Store
import com.fuzz.kedux.combineReducers
import com.fuzz.kedux.createStore
import kotlinx.coroutines.flow.launchIn
import kotlinx.coroutines.flow.onEach
import kotlin.test.BeforeTest
import kotlin.test.Test
import kotlin.test.assertEquals


class TypedActionTest {

    private lateinit var store: Store<GlobalState>

    @BeforeTest
    fun constructStore() {
        applyTestSchedulers()
        Store.loggingEnabled = true
        store = createStore(combineReducers(sampleTypedReducer), initialState)
    }

    @Test
    fun testTypedReducer() = runBlocking {
        var name: String? = null
        store.select(nameSelector)
                .onEach {
                    name = it
                }.launchIn(this).use {
                    store.dispatch(nameChange("NEW NAME"))
                    assertEquals("NEW NAME", name)
                }
    }

    @Test
    fun testLocationChangeReducer() = runBlocking {
        var location: Location? = null
        store.select(locationSelector)
                .onEach {
                    location = it
                }.launchIn(this).use {
                    val updatedLocation = Location(5, "Other")
                    store.dispatch(locationChange(updatedLocation))
                    assertEquals(updatedLocation, location)
                }
    }

    @Test
    fun testResetActionType() = runBlocking {
        var location: Location? = null
        store.select(locationSelector)
                .onEach {
                    location = it
                }.launchIn(this).use {
                    val updatedLocation = Location(5, "Other")
                    store.dispatch(locationChange(updatedLocation))
                    assertEquals(updatedLocation, location)

                    store.dispatch(resetAction)
                    assertEquals(initialState.location, location)
                }
    }
}
