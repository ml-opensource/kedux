import com.badoo.reaktive.scheduler.overrideSchedulers
import com.badoo.reaktive.test.scheduler.TestScheduler
import com.badoo.reaktive.utils.atomic.AtomicInt
import com.badoo.reaktive.utils.atomic.AtomicReference
import com.fuzz.kedux.Store
import com.fuzz.kedux.createStore
import kotlin.test.BeforeTest
import kotlin.test.Test
import kotlin.test.assertEquals

class SelectorTest {

    private lateinit var store: Store<GlobalState>

    @BeforeTest
    fun constructStore() {
        applyTestSchedulers()
        Store.loggingEnabled = true
        store = createStore(sampleReducer, initialState)
    }

    @Test
    fun selectorEmitsAllValues() {
        var count = 0
        var name = ""
        store.select(nameSelector)
                .subscribe(isThreadLocal = true) {
                    name = it
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
        val count = AtomicInt(0)
        val name = AtomicReference("")
        store.select(nameSelector).subscribe {
            count.value = count.value + 1
            name.value = it
        }.use {
            repeat(3) {
                store.dispatch(StoreTestAction.NameChange("Name$it"))
                store.dispatch(StoreTestAction.NameChange("Name$it"))
            }
            assertEquals("Name2", name.value)
            assertEquals(4, count.value)
        }
    }

    @Test
    fun composeSelectors() {
        var value: Int? = null
        var count = 0
        store.select(locationIdSelector).subscribe(isThreadLocal = true) {
            count++
            value = it
        }.use {
            repeat(3) {
                store.dispatch(StoreTestAction.LocationChange(Location(5, "1")))
                store.dispatch(StoreTestAction.LocationChange(Location(5, "1")))
                store.dispatch(StoreTestAction.NameChange("New Name"))
            }
            assertEquals(5, value)
            assertEquals(2, count)
        }
    }

    @Test
    fun composeSelectors3() {
        var count = 0
        var value: Int? = null
        store.select(locationProductIdSelector)
                .subscribe(isThreadLocal = true) { next ->
                    count++
                    value = next
                }.use {
                    repeat(3) {
                        store.dispatch(
                                StoreTestAction.LocationChange(
                                        Location(
                                                5,
                                                "1",
                                                product = Product(5, "Burger")
                                        )
                                )
                        )
                        store.dispatch(
                                StoreTestAction.LocationChange(
                                        Location(
                                                5,
                                                "1",
                                                product = Product(5, "Burger")
                                        )
                                )
                        )
                        store.dispatch(StoreTestAction.NameChange("New Name"))
                    }

                    assertEquals(5, value)
                    assertEquals(2, count)
                }
    }
}

