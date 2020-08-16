import com.fuzz.kedux.FracturedState
import com.fuzz.kedux.Store
import com.fuzz.kedux.createFracturedStore
import com.fuzz.kedux.fracturedSelector
import com.fuzz.kedux.reduce
import kotlinx.atomicfu.AtomicRef
import kotlinx.atomicfu.atomic
import kotlinx.coroutines.flow.launchIn
import kotlinx.coroutines.flow.onEach
import kotlin.test.BeforeTest
import kotlin.test.Test
import kotlin.test.assertEquals

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
        store.dispatch(ProductActions.NameChange("Name Changed"))

        val product: AtomicRef<Product?> = atomic(null)
        store.select(fracturedSelector(productReducer))
                .onEach { value ->
                    product.value = value
                }.launchIn(this)
        assertEquals(Product(0, "Name Changed"), product.value)
    }

    @Test
    fun canUpdateLocationState() = runBlocking {
        store.dispatch(LocationActions.ProductChange(Product(5, "Namey")))

        val product: AtomicRef<Product?> = atomic(null)
        store.select(fracturedSelector(locationReducer).compose { it.product })
                .onEach { value ->
                    product.value = value
                }.launchIn(this)
        assertEquals(Product(5, "Namey"), product.value)
    }
}
