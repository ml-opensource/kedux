import com.badoo.reaktive.observable.subscribe
import com.badoo.reaktive.scheduler.overrideSchedulers
import com.badoo.reaktive.test.scheduler.TestScheduler
import com.fuzz.kedux.FracturedState
import com.fuzz.kedux.Store
import com.fuzz.kedux.createFracturedStore
import com.fuzz.kedux.fracturedSelector
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
            productReducer to Product(0, ""),
            locationReducer to Location(0, ""),
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
}
