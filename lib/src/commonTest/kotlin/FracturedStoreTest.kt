import app.cash.turbine.test
import com.fuzz.kedux.FracturedState
import com.fuzz.kedux.Store
import com.fuzz.kedux.createFracturedStore
import com.fuzz.kedux.fracturedSelector
import com.fuzz.kedux.reduce
import kotlin.test.BeforeTest
import kotlin.test.Test
import logAssertEquals as assertEquals

class FracturedStoreTest {

    private lateinit var store: Store<FracturedState>

    @BeforeTest
    fun constructStore() {
        applyTestSchedulers()
        Store.loggingEnabled = true
        store = createFracturedStore(
                productReducer reduce Product(0, ""),
                locationReducer reduce Location(0, "")
        )
    }

    @Test
    fun canUpdateProductState() = runBlocking {
        store.select(fracturedSelector(productReducer))
                .test {
                    store.dispatch(ProductActions.NameChange("Name Changed"))
                    assertEquals(Product(0, "Name Changed"), expectItem())
                }
    }

    @Test
    fun canUpdateLocationState() = runBlocking {

        store.select(fracturedSelector(locationReducer).compose { it.product })
                .test {
                    store.dispatch(LocationActions.ProductChange(Product(5, "Namey")))
                    assertEquals(Product(5, "Namey"), expectItem())
                }
    }
}
