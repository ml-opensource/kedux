import StoreTestAction.LocationChange
import StoreTestAction.LocationChanged
import StoreTestAction.NameChange
import StoreTestAction.NamedChanged
import StoreTestAction.Reset
import com.badoo.reaktive.observable.map
import com.badoo.reaktive.observable.subscribe
import com.badoo.reaktive.observable.take
import com.fuzz.kedux.Effects
import com.fuzz.kedux.MultiAction
import com.fuzz.kedux.Store
import com.fuzz.kedux.combineReducers
import com.fuzz.kedux.createEffect
import com.fuzz.kedux.createStore
import com.fuzz.kedux.multipleActionOf
import kotlin.test.AfterTest
import kotlin.test.BeforeTest
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertTrue

val nameChangeEffect = createEffect<NameChange, NamedChanged> { change -> change.map { (name) -> NamedChanged(name) } }

val multipleDispatchEffect = createEffect<LocationChange, MultiAction> { change ->
    change.map { (location) -> multipleActionOf(LocationChanged(location.other), Reset) }
}


class EffectsTest {

    private lateinit var store: Store<GlobalState>

    private lateinit var nameEffects: Effects


    @BeforeTest
    fun setupTest() {
        applyTestSchedulers()
        Store.loggingEnabled = true
        nameEffects = Effects(nameChangeEffect, multipleDispatchEffect)
        store = createStore(combineReducers(sampleReducer, sampleReducer2), initialState)
                .also { nameEffects.bindTo(it) }
    }

    @AfterTest
    fun teardownTest() {
        nameEffects.clearBindings()
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

    @Test
    fun changeDispatchMultipleActionsInEffect() {
        val actionsList = mutableListOf<Any>()
        store.actions.subscribe(isThreadLocal = true) {
            actionsList += it
        }

        store.dispatch(LocationChange(Location(55, "OTHER NAME")))
        assertEquals(LocationChanged("OTHER NAME"), actionsList[1])
        assertEquals(Reset, actionsList[2])
    }
}
