import com.fuzz.kedux.Store
import com.fuzz.kedux.createSelector
import com.fuzz.kedux.createStore
import com.fuzz.kedux.typedReducer
import kotlinx.coroutines.ExperimentalCoroutinesApi
import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.flow.collectLatest
import kotlinx.coroutines.flow.consumeAsFlow
import kotlinx.coroutines.flow.first
import kotlinx.coroutines.launch
import kotlin.test.BeforeTest
import kotlin.test.Test
import kotlin.test.assertEquals

data class Location(val id: Int)
data class State(val name: String, val location: Location? = null)

sealed class StoreTestAction {

    data class NameChange(val name: String) :
        StoreTestAction()

    data class LocationChange(val location: Location) :
        StoreTestAction()

    object Reset : StoreTestAction()
}

val sampleReducer = typedReducer<State, StoreTestAction> { state, action ->
    when (action) {
        is StoreTestAction.NameChange -> state.copy(name = action.name)
        is StoreTestAction.Reset -> state
        is StoreTestAction.LocationChange -> state.copy(location = action.location)
    }
}

@ExperimentalCoroutinesApi
class StoreTest {

    private lateinit var store: Store<State>

    @BeforeTest
    fun constructStore() {
        store = createStore(sampleReducer, State(""), loggingEnabled = true)
    }

    @Test
    fun storeConstructed() = runTest {
        assertEquals(State(""), store.state.receive())
    }

    @Test
    fun dispatchActionChangesState() = runTest {
        store.awaitDispatch(StoreTestAction.NameChange("NewName"))
        val updated = store.state.receive()
        assertEquals(State("NewName"), updated)
    }

    @Test
    fun canSubscribeToAction() = runTest {
        var count = 0

        val job = GlobalScope.launch {
            val state = store.state.consumeAsFlow().first()
            assertEquals(State("NewName2", null), state)
            count++
        }
        store.awaitDispatch(StoreTestAction.NameChange("NewName2"))
        job.join()
        assertEquals(1, count)

        store.awaitDispatch(StoreTestAction.NameChange("Done"))
        job.join()
        // ensure count no longer increases.
        assertEquals(1, count)

    }

    @Test
    fun invalidAction() = runTest {
        val action = object {
        }
        store.awaitDispatch(action)
        assertEquals(State(""), store.state.receive())
    }

    @Test
    fun selectorEmitsAllValues() = runTest {
        var count = 0
        val name = store.createSelector { state ->
            count++
            state.name
        }
        repeat(3) {
            store.awaitDispatch(StoreTestAction.NameChange("Name$it"))
            store.awaitDispatch(StoreTestAction.NameChange("Name2-$it"))
        }
        store.closeState()
        name.consumeAsFlow().collectLatest {
            assertEquals("Name2-2", it)
        }
        assertEquals(7, count)
    }

    @Test
    fun selectorSelectivelyEmitsValues() = runTest {
        var count = 0
        val name = store.createSelector { state ->
            count++
            state.name
        }
        repeat(3) {
            store.awaitDispatch(StoreTestAction.NameChange("Name$it"))
            store.awaitDispatch(StoreTestAction.NameChange("Name$it"))
        }
        store.closeState()
        name.consumeAsFlow().collectLatest {
            assertEquals("Name2", it)
        }
        assertEquals(4, count)
    }

    @Test
    fun composeSelectors() = runTest {
        var count1 = 0
        var count2 = 0
        val location = store.createSelector({ state ->
            count1++
            state.location
        }) { state ->
            count2++
            state?.id
        }
        repeat(3) {
            store.awaitDispatch(StoreTestAction.LocationChange(Location(5)))
            store.awaitDispatch(StoreTestAction.LocationChange(Location(3)))
            store.awaitDispatch(StoreTestAction.NameChange("New Name"))
        }
        store.closeState()
        location.consumeAsFlow().collectLatest { value: Int? ->
            assertEquals(3, value)
        }
    }
}
