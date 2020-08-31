import com.fuzz.kedux.NoAction
import com.fuzz.kedux.Store
import com.fuzz.kedux.combineReducers
import com.fuzz.kedux.createStore
import com.fuzz.kedux.multipleActionOf
import kotlinx.coroutines.flow.launchIn
import kotlinx.coroutines.flow.onEach
import kotlinx.coroutines.flow.take
import kotlin.test.BeforeTest
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.fail

class StoreTest : BaseTest() {

    private lateinit var store: Store<GlobalState>

    @BeforeTest
    fun constructStore() {
        Store.loggingEnabled = true
        store = createStore(combineReducers(sampleReducer, sampleReducer2), initialState)
    }

    @Test
    fun storeConstructed() = runBlocking {
        store.state.take(1)
                .onEach {
                    assertEquals(GlobalState(""), it)
                }.launchIn(this)
    }

    @Test
    fun dispatchActionChangesState() = runBlocking {
        store.dispatch(StoreTestAction.NameChange("NewName"))
        store.state.take(1)
                .onEach { updated ->
                    assertEquals(GlobalState("NewName"), updated)
                }.launchIn(this)
    }

    @Test
    fun invalidAction() = runBlocking {
        val action = object {
        }
        store.dispatch(action)
        store.state.take(1).onEach { state ->
            assertEquals(GlobalState(""), state)
        }.launchIn(this)
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
        store.actions.onEach {
            actionsList += it
        }.launchIn(this).use {
            store.dispatch(action1 to action2)
            assertEquals(2, actionsList.count())
            assertEquals(actionsList[0], action1)
            assertEquals(actionsList[1], action2)
        }
    }

    @Test
    fun dispatchTripleAction() = runBlocking {
        val action1 = object {}
        val action2 = object {}
        val action3 = object {}
        val actionsList = mutableListOf<Any>()
        store.actions.onEach {
            actionsList += it
        }.launchIn(this).use {
            store.dispatch(Triple(action1, action2, action3))
            assertEquals(3, actionsList.count())
            assertEquals(actionsList[0], action1)
            assertEquals(actionsList[1], action2)
            assertEquals(actionsList[2], action3)
        }
    }

    @Test
    fun dispatchMultiAction() = runBlocking {
        val action1 = object {}
        val action2 = object {}
        val action3 = object {}
        val action4 = object {}
        val actionsList = mutableListOf<Any>()
        store.actions.onEach {
            actionsList += it
        }.launchIn(this).use {
            val multiAction = multipleActionOf(action1, action2, action3, action4)
            store.dispatch(multiAction)
            assertEquals(multiAction.actions.count(), actionsList.count())
            multiAction.actions.forEachIndexed { index, action ->
                assertEquals(action, actionsList[index])
            }
        }
    }
}
