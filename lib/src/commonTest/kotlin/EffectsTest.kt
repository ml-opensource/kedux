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
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.flow.map
import kotlin.test.BeforeTest
import kotlin.test.Test
import logAssertEquals as assertEquals
import logAssertTrue as assertTrue

val nameChangeEffect = createEffect<NameChange, NamedChanged> { change -> change.map { (name) -> NamedChanged(name) } }

val multipleDispatchEffect = createEffect<LocationChange, MultiAction> { change ->
    change.map { (location) -> multipleActionOf(LocationChanged(location.other), Reset) }
}

suspend fun Effects.use(scope: CoroutineScope, store: Store<*>, fn: suspend () -> Unit) {
    bindTo(store, scope)
    fn()
    clearBindings()
}

class EffectsTest : BaseTest() {

    private lateinit var store: Store<GlobalState>

    private lateinit var nameEffects: Effects

    @BeforeTest
    fun setupTest() {
        Store.loggingEnabled = true
        store = createStore(combineReducers(sampleReducer, sampleReducer2), initialState)
        nameEffects = Effects(nameChangeEffect, multipleDispatchEffect)
    }

    @Test
    fun canChangeNameEffect() = runBlocking {
        nameEffects.use(this, store) {
            store.select(namedChangedSelector)
                    .test {
                        store.dispatch(NameChange("New Name"))
                        assertTrue(expectItem())
                    }
        }
    }

    @Test
    fun changeDispatchMultipleActionsInEffect() = runBlocking {
        nameEffects.use(this, store) {
            store.actions.test {
                val originalAction = LocationChange(Location(55, "OTHER NAME"))
                store.dispatch(originalAction)
                assertEquals(originalAction, expectItem())
                assertEquals(LocationChanged("OTHER NAME"), expectItem())
                assertEquals(Reset, expectItem())
            }
        }
    }
}
