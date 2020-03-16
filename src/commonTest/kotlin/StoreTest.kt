import com.fuzz.kedux.Store
import com.fuzz.kedux.createStore
import com.fuzz.kedux.typedReducer
import kotlinx.coroutines.ExperimentalCoroutinesApi
import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.flow.consumeAsFlow
import kotlinx.coroutines.flow.first
import kotlinx.coroutines.launch
import kotlin.test.BeforeTest
import kotlin.test.Test
import kotlin.test.assertEquals


data class State(val name: String)

sealed class StoreTestAction {

    data class NameChange(val name: String) :
        StoreTestAction()

    object Reset : StoreTestAction()
}

val sampleReducer = typedReducer<State, StoreTestAction> { state, action ->
    when (action) {
        is StoreTestAction.NameChange -> state.copy(name = action.name)
        is StoreTestAction.Reset -> state
    }
}

@ExperimentalCoroutinesApi
class StoreTest {

    private lateinit var store: Store<State>

    @BeforeTest
    fun constructStore() {
        store = createStore(sampleReducer, State(""))
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
            assertEquals(State("NewName2"), state)
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
}
