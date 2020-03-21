import com.badoo.reaktive.observable.map
import com.badoo.reaktive.observable.subscribe
import com.badoo.reaktive.scheduler.overrideSchedulers
import com.badoo.reaktive.test.scheduler.TestScheduler
import com.fuzz.kedux.*
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
        store = createFracturedStore(
            productReducer reduce Product(0, ""),
            locationReducer reduce Location(0, ""),
            loggingEnabled = true
        )
    }

    @Test
    fun canUpdateProductState() {
        store.dispatch(ProductActions.NameChange("Name Changed"))

        var product: Product? = null
        store.fracturedSelector(productReducer)
            .subscribe { value ->
                product = value
            }.use {
                assertEquals(Product(0, "Name Changed"), product)
            }
    }

    @Test
    fun canUpdateLocationState() {
        store.dispatch(LocationActions.ProductChange(Product(5, "Namey")))

        var product: Product? = null
        store.fracturedSelector(locationReducer)
            .map { it.product }
            .subscribe { value ->
                product = value
            }.use {
                assertEquals(Product(5, "Namey"), product)
            }
    }
}
