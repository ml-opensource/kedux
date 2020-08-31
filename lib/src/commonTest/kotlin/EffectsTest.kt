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

    /**
     * Binding to effects are active and require blocking runs.
     */
    private fun bindEffects() {
        store.also { nameEffects.bindTo(it) }
    }

    private fun clearEffects() {
        nameEffects.clearBindings()
    }

    @BeforeTest
    fun setupTest() {
        Store.loggingEnabled = true
        nameEffects = Effects(nameChangeEffect, multipleDispatchEffect, scope = getTestScope())
        store = createStore(combineReducers(sampleReducer, sampleReducer2), initialState)
    }

    @Test
    fun canChangeNameEffect() = runBlocking {
        bindEffects()
        store.select(namedChangedSelector)
                .test {
                    store.dispatch(NameChange("New Name"))
                    assertTrue(expectItem())
                }
        clearEffects()
    }

    @Test
    fun changeDispatchMultipleActionsInEffect() = runBlocking {
        bindEffects()
        store.actions.test {
            store.dispatch(LocationChange(Location(55, "OTHER NAME")))
            assertEquals(LocationChanged("OTHER NAME"), expectItem())
            assertEquals(Reset, expectItem())
        }
        clearEffects()
    }
}
