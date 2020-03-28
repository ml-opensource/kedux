import com.badoo.reaktive.observable.subscribe
import com.badoo.reaktive.observable.take
import com.badoo.reaktive.scheduler.overrideSchedulers
import com.badoo.reaktive.test.scheduler.TestScheduler
import com.fuzz.kedux.Store
import com.fuzz.kedux.combineReducers
import com.fuzz.kedux.createStore
import com.fuzz.kedux.multipleActionOf
import kotlin.test.BeforeTest
import kotlin.test.Test
import kotlin.test.assertEquals

class StoreTest {

    private lateinit var store: Store<GlobalState>

    @BeforeTest
    fun constructStore() {
        overrideSchedulers(
                computation = { TestScheduler() },
                main = { TestScheduler() }
        )
        Store.loggingEnabled = true
        store = createStore(combineReducers(sampleReducer, sampleReducer2), initialState)
    }

    @Test
    fun storeConstructed() {
        store.state.take(1)
                .subscribe {
                    assertEquals(GlobalState(""), it)
                }
    }

    @Test
    fun dispatchActionChangesState() {
        store.dispatch(StoreTestAction.NameChange("NewName"))
        store.state.take(1)
                .subscribe { updated ->
                    assertEquals(GlobalState("NewName"), updated)
                }
    }

    @Test
    fun invalidAction() {
        val action = object {
        }
        store.dispatch(action)
        store.state.take(1).subscribe { state ->
            assertEquals(GlobalState(""), state)
        }
    }

    @Test
    fun dispatchPairAction() {
        val action1 = object {}
        val action2 = object {}
        val actionsList = mutableListOf<Any>()
        store.actions.subscribe(isThreadLocal = true) {
            actionsList += it
        }
        store.dispatch(action1 to action2)
        assertEquals(2, actionsList.count())
        assertEquals(actionsList[0], action1)
        assertEquals(actionsList[1], action2)
    }

    @Test
    fun dispatchTripleAction() {
        val action1 = object {}
        val action2 = object {}
        val action3 = object {}
        val actionsList = mutableListOf<Any>()
        store.actions.subscribe(isThreadLocal = true) {
            actionsList += it
        }
        store.dispatch(Triple(action1, action2, action3))
        assertEquals(3, actionsList.count())
        assertEquals(actionsList[0], action1)
        assertEquals(actionsList[1], action2)
        assertEquals(actionsList[2], action3)
    }

    @Test
    fun dispatchMultiAction() {
        val action1 = object {}
        val action2 = object {}
        val action3 = object {}
        val action4 = object {}
        val actionsList = mutableListOf<Any>()
        store.actions.subscribe(isThreadLocal = true) {
            actionsList += it
        }
        val multiAction = multipleActionOf(action1, action2, action3, action4)
        store.dispatch(multiAction)
        assertEquals(multiAction.actions.count(), actionsList.count())
        multiAction.actions.forEachIndexed { index, action ->
            assertEquals(action, actionsList[index])
        }
    }
}
