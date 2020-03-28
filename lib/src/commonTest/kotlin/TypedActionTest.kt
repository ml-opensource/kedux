import com.fuzz.kedux.Store
import com.fuzz.kedux.combineReducers
import com.fuzz.kedux.createStore
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
    fun testTypedReducer() {
        var name: String? = null
        store.select(nameSelector)
                .subscribe(isThreadLocal = true) {
                    name = it
                }.use {
                    store.dispatch(nameChange("NEW NAME"))
                    assertEquals("NEW NAME", name)
                }
    }

    @Test
    fun testLocationChangeReducer() {
        var location: Location? = null
        store.select(locationSelector)
                .subscribe(isThreadLocal = true) {
                    location = it
                }.use {
                    val updatedLocation = Location(5, "Other")
                    store.dispatch(locationChange(updatedLocation))
                    assertEquals(updatedLocation, location)
                }
    }

    @Test
    fun testResetActionType() {
        var location: Location? = null
        store.select(locationSelector)
                .subscribe(isThreadLocal = true) {
                    location = it
                }.use {
                    val updatedLocation = Location(5, "Other")
                    store.dispatch(locationChange(updatedLocation))
                    assertEquals(updatedLocation, location)

                    store.dispatch(resetAction)
                    assertEquals(initialState.location, location)
                }
    }
}
