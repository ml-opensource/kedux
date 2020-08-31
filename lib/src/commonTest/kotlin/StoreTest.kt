import app.cash.turbine.test
import com.fuzz.kedux.NoAction
import com.fuzz.kedux.Store
import com.fuzz.kedux.combineReducers
import com.fuzz.kedux.createStore
import com.fuzz.kedux.multipleActionOf
import kotlinx.coroutines.flow.launchIn
import kotlinx.coroutines.flow.onEach
import kotlin.test.BeforeTest
import kotlin.test.Test
import kotlin.test.fail
import logAssertEquals as assertEquals

class StoreTest : BaseTest() {

    private lateinit var store: Store<GlobalState>

    @BeforeTest
    fun constructStore() {
        Store.loggingEnabled = true
        store = createStore(combineReducers(sampleReducer, sampleReducer2), initialState)
    }

    @Test
    fun storeConstructed() = runBlocking {
        store.state.test {
            assertEquals(GlobalState(""), expectItem())
        }
    }

    @Test
    fun dispatchActionChangesState() = runBlocking {
        store.dispatch(StoreTestAction.NameChange("NewName"))
        store.state.test {
            assertEquals(GlobalState("NewName"), expectItem())
        }
    }

    @Test
    fun invalidAction() = runBlocking {
        val action = object {
        }
        store.dispatch(action)
        store.state.test {
            assertEquals(GlobalState(""), expectItem())
        }
    }

    @Test
    fun noAction() = runBlocking {
        store.actions.onEach {
            fail("Action called $it, when it's not expected.")
        }.launchIn(this).use {
            store.dispatch(NoAction)
        }
    }

    @Test
    fun dispatchPairAction() = runBlocking {
        val action1 = object {}
        val action2 = object {}
        val actionsList = mutableListOf<Any>()
        store.actions.test {
            store.dispatch(action1 to action2)
            assertEquals(action1, expectItem())
            assertEquals(action2, expectItem())
        }
    }

    @Test
    fun dispatchTripleAction() = runBlocking {
        val action1 = object {}
        val action2 = object {}
        val action3 = object {}
        store.actions.test {
            store.dispatch(Triple(action1, action2, action3))
            assertEquals(action1, expectItem())
            assertEquals(action2, expectItem())
            assertEquals(action3, expectItem())
        }
    }

    @Test
    fun dispatchMultiAction() = runBlocking {
        val action1 = object {}
        val action2 = object {}
        val action3 = object {}
        val action4 = object {}
        store.actions.test {
            val multiAction = multipleActionOf(action1, action2, action3, action4)
            store.dispatch(multiAction)
            multiAction.actions.forEach { action ->
                assertEquals(action, expectItem())
            }
        }
    }
}
