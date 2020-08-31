import StoreTestAction.LocationChange
import StoreTestAction.LocationChanged
import StoreTestAction.NameChange
import StoreTestAction.NamedChanged
import StoreTestAction.Reset
import app.cash.turbine.test
import com.fuzz.kedux.Effects
import com.fuzz.kedux.MultiAction
import com.fuzz.kedux.Store
import com.fuzz.kedux.combineReducers
import com.fuzz.kedux.createEffect
import com.fuzz.kedux.createStore
import com.fuzz.kedux.multipleActionOf
import kotlinx.coroutines.flow.map
import kotlin.test.AfterTest
import kotlin.test.BeforeTest
import kotlin.test.Test
import logAssertEquals as assertEquals
import logAssertTrue as assertTrue

val nameChangeEffect = createEffect<NameChange, NamedChanged> { change -> change.map { (name) -> NamedChanged(name) } }

val multipleDispatchEffect = createEffect<LocationChange, MultiAction> { change ->
    change.map { (location) -> multipleActionOf(LocationChanged(location.other), Reset) }
}

class EffectsTest : BaseTest() {

    private lateinit var store: Store<GlobalState>

    private lateinit var nameEffects: Effects


    @BeforeTest
    fun setupTest() {
        Store.loggingEnabled = true
        nameEffects = Effects(nameChangeEffect, multipleDispatchEffect, scope = getTestScope())
        store = createStore(combineReducers(sampleReducer, sampleReducer2), initialState)
                .also { nameEffects.bindTo(it) }
    }

    @AfterTest
    fun teardownTest() {
        nameEffects.clearBindings()
    }

    @Test
    fun canChangeNameEffect() = runBlocking {
        store.select(getNamedChangedSelector())
                .test {
                    store.dispatch(NameChange("New Name"))
                    assertTrue(expectItem())
                }
    }

    @Test
    fun changeDispatchMultipleActionsInEffect() = runBlocking {
        store.actions.test {
            store.dispatch(LocationChange(Location(55, "OTHER NAME")))
            assertEquals(LocationChanged("OTHER NAME"), expectItem())
            assertEquals(Reset, expectItem())
        }

    }
}
