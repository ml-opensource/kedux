import com.fuzz.kedux.Store
import com.fuzz.kedux.createStore
import com.fuzz.kedux.reducer
import kotlin.test.BeforeTest
import kotlin.test.Test
import kotlin.test.assertEquals


data class State(val name: String)

sealed class StoreTestAction {

    data class NameChange(val name: String) :
        StoreTestAction()

    object Reset : StoreTestAction()
}

val sampleReducer = reducer<State> { state, action ->
    when (action) {
        is StoreTestAction.NameChange -> state.copy(name = action.name)
        is StoreTestAction.Reset -> state
        else -> state
    }
}

class StoreTest {

    private lateinit var store: Store<State>

    @BeforeTest
    fun constructStore() {
        store = createStore(sampleReducer, State(""))
    }

    @Test
    fun storeConstructed() {
        assertEquals(State(""), store.state)
    }

    @Test
    fun dispatchActionChangesState() {
        store.dispatch(StoreTestAction.NameChange("NewName"))
        assertEquals(State("NewName"), store.state)
    }

    @Test
    fun canSubscribeToAction() {
        var count = 0
        val stateListener: (state: State) -> Unit = { state ->
            count++
        }
        store.subscribe(stateListener)
        store.dispatch(StoreTestAction.NameChange("NewName2"))
        assertEquals(1, count)

        store.unsubscribe(stateListener)
        store.dispatch(StoreTestAction.NameChange("Done"))
        // ensure count no longer increases.
        assertEquals(1, count)
    }

    @Test
    fun invalidAction() {
        val action = object {
        }
        store.dispatch(action)
    }
}
