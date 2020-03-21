import com.badoo.reaktive.observable.subscribe
import com.badoo.reaktive.scheduler.overrideSchedulers
import com.badoo.reaktive.test.scheduler.TestScheduler
import com.fuzz.kedux.Store
import com.fuzz.kedux.createSelector
import com.fuzz.kedux.createStore
import kotlin.test.BeforeTest
import kotlin.test.Test
import kotlin.test.assertEquals

class SelectorTest {

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
    fun selectorEmitsAllValues() {
        var count = 0
        var name = ""
        store.createSelector { state -> state.name }
            .subscribe(isThreadLocal = true) {
                name = it
                println("INCREMENTING COUNT $count")
                count++
            }.use {
                repeat(3) {
                    store.dispatch(StoreTestAction.NameChange("Name$it"))
                    store.dispatch(StoreTestAction.NameChange("Name2-$it"))
                }
                assertEquals(name, "Name2-2")
                assertEquals(7, count)
            }
    }

    @Test
    fun selectorSelectivelyEmitsValues() {
        var count = 0
        var name = ""
        store.createSelector { state ->
            count++
            state.name
        }.subscribe {
            name = it
        }.use {
            repeat(3) {
                store.dispatch(StoreTestAction.NameChange("Name$it"))
                store.dispatch(StoreTestAction.NameChange("Name$it"))
            }
            assertEquals("Name2", name)
            assertEquals(4, count)
        }
    }

    @Test
    fun composeSelectors() {
        var count1 = 0
        var count2 = 0
        var value: Int? = null
        store.createSelector({ state ->
                count1++
                state.location
            }) { state ->
                count2++
                state?.id
            }
            .subscribe { value = it }
            .use {
                repeat(3) {
                    store.dispatch(StoreTestAction.LocationChange(Location(5, "1")))
                    store.dispatch(StoreTestAction.LocationChange(Location(5, "1")))
                    store.dispatch(StoreTestAction.NameChange("New Name"))
                }
                assertEquals(5, value)
                assertEquals(3, count1)
                assertEquals(1, count2)
            }
    }

    @Test
    fun composeSelectors3() {
        var count1 = 0
        var count2 = 0
        var count3 = 0
        store.createSelector({ state ->
            count1++
            state.location
        }, { state ->
            count2++
            state?.product
        }) { state ->
            count3++
            state?.id
        }.subscribe { value ->
            assertEquals(5, value)
            assertEquals(2, count1)
            assertEquals(1, count2)
            assertEquals(1, count3)
        }.use {
            repeat(3) {
                store.dispatch(StoreTestAction.LocationChange(Location(5, "1", product = Product(5, "Burger"))))
                store.dispatch(StoreTestAction.LocationChange(Location(5, "1", product = Product(5, "Burger"))))
                store.dispatch(StoreTestAction.NameChange("New Name"))
            }
        }
    }
}
