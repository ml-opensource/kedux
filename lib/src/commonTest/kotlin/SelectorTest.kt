import com.fuzz.kedux.Store
import com.fuzz.kedux.createStore
import kotlinx.atomicfu.atomic
import kotlinx.coroutines.flow.launchIn
import kotlinx.coroutines.flow.onEach
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
    fun selectorEmitsAllValues() = runBlocking {
        var count = 0
        var name = ""
        store.select(nameSelector)
                .onEach {
                    name = it
                    count++
                }.launchIn(this)
        repeat(3) {
            store.dispatch(StoreTestAction.NameChange("Name$it"))
            store.dispatch(StoreTestAction.NameChange("Name2-$it"))
        }
        assertEquals(name, "Name2-2")
        assertEquals(7, count)
    }

    @Test
    fun selectorSelectivelyEmitsValues() = runBlocking {
        val count = atomic(0)
        val name = atomic("")
        store.select(nameSelector).onEach {
            count.value = count.value + 1
            name.value = it
        }.launchIn(this)
        repeat(3) {
            store.dispatch(StoreTestAction.NameChange("Name$it"))
            store.dispatch(StoreTestAction.NameChange("Name$it"))
        }
        assertEquals("Name2", name.value)
        assertEquals(4, count.value)
    }

    @Test
    fun composeSelectors() = runBlocking {
        var value: Int? = null
        var count = 0
        store.select(locationIdSelector).onEach {
            count++
            value = it
        }.launchIn(this)
        repeat(3) {
            store.dispatch(StoreTestAction.LocationChange(Location(5, "1")))
            store.dispatch(StoreTestAction.LocationChange(Location(5, "1")))
            store.dispatch(StoreTestAction.NameChange("New Name"))
        }
        assertEquals(5, value)
        assertEquals(2, count)
    }

    @Test
    fun composeSelectors3() = runBlocking {
        var count = 0
        var value: Int? = null
        store.select(locationProductIdSelector)
                .onEach { next ->
                    count++
                    value = next
                }.launchIn(this)
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

