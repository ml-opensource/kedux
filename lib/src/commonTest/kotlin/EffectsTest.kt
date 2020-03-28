import StoreTestAction.NameChange
import StoreTestAction.NamedChanged
import com.badoo.reaktive.observable.map
import com.badoo.reaktive.observable.subscribe
import com.badoo.reaktive.observable.take
import com.badoo.reaktive.scheduler.overrideSchedulers
import com.badoo.reaktive.test.scheduler.TestScheduler
import com.fuzz.kedux.Effects
import com.fuzz.kedux.Store
import com.fuzz.kedux.combineReducers
import com.fuzz.kedux.createEffect
import com.fuzz.kedux.createStore
import kotlin.test.AfterTest
import kotlin.test.BeforeTest
import kotlin.test.Test
import kotlin.test.assertTrue

val nameChangeEffect = createEffect<NameChange, NamedChanged> { change -> change.map { NamedChanged(it.name) } }

val nameEffects = Effects(nameChangeEffect)

class EffectsTest {

    private lateinit var store: Store<GlobalState>

    @BeforeTest
    fun setupTest() {
        overrideSchedulers(
                main = { TestScheduler() },
                computation = { TestScheduler() }
        )
        Store.loggingEnabled = true
        store = createStore(combineReducers(sampleReducer, sampleReducer2), initialState)
                .also { nameEffects.bindTo(it) }
    }

    @AfterTest
    fun teardownTest() {
        nameEffects.dispose()
    }

    @Test
    fun canChangeNameEffect() {
        store.dispatch(NameChange("New Name"))

        store.select(namedChangedSelector)
                .take(1)
                .subscribe {
                    assertTrue(it)
                }
    }
}
