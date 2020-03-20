import com.badoo.reaktive.observable.subscribe
import com.badoo.reaktive.observable.take
import com.badoo.reaktive.scheduler.overrideSchedulers
import com.badoo.reaktive.test.scheduler.TestScheduler
import com.fuzz.kedux.Store
import com.fuzz.kedux.createStore
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
        store = createStore(sampleReducer, initialState, loggingEnabled = true)
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
}
