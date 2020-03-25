import com.badoo.reaktive.scheduler.overrideSchedulers
import com.badoo.reaktive.test.scheduler.TestScheduler
import com.badoo.reaktive.utils.atomic.AtomicReference
import com.fuzz.kedux.FracturedState
import com.fuzz.kedux.Store
import com.fuzz.kedux.compose
import com.fuzz.kedux.createFracturedStore
import com.fuzz.kedux.fracturedSelector
import com.fuzz.kedux.reduce
import kotlin.test.BeforeTest
import kotlin.test.Test
import kotlin.test.assertEquals

class FracturedStoreTest {

    private lateinit var store: Store<FracturedState>

    @BeforeTest
    fun constructStore() {
        overrideSchedulers(
                computation = { TestScheduler() },
                main = { TestScheduler() }
        )
        Store.loggingEnabled = true
        store = createFracturedStore(
                productReducer reduce Product(0, ""),
                locationReducer reduce Location(0, "")
        )
    }

    @Test
    fun canUpdateProductState() {
        store.dispatch(ProductActions.NameChange("Name Changed"))

        val product: AtomicReference<Product?> = AtomicReference(null)
        store.select(fracturedSelector(productReducer))
                .subscribe { value ->
                    product.value = value
                }.use {
                    assertEquals(Product(0, "Name Changed"), product.value)
                }
    }

    @Test
    fun canUpdateLocationState() {
        store.dispatch(LocationActions.ProductChange(Product(5, "Namey")))

        val product: AtomicReference<Product?> = AtomicReference(null)
        store.select(fracturedSelector(locationReducer).compose { it.product })
                .subscribe { value ->
                    product.value = value
                }.use {
                    assertEquals(Product(5, "Namey"), product.value)
                }
    }
}
