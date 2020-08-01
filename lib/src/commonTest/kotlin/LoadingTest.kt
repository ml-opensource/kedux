import com.badoo.reaktive.observable.toObservable
import com.fuzz.kedux.Effects
import com.fuzz.kedux.KeduxLoader
import com.fuzz.kedux.LoadingAction
import com.fuzz.kedux.LoadingModel
import com.fuzz.kedux.Store
import com.fuzz.kedux.createSelector
import com.fuzz.kedux.createStore
import com.fuzz.kedux.error
import com.fuzz.kedux.optionalSuccess
import com.fuzz.kedux.success
import com.fuzz.kedux.typedReducer
import kotlin.test.AfterTest
import kotlin.test.BeforeTest
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertNull

data class State(val product: LoadingModel<Product> = LoadingModel.empty())

val initialLoadingState = State()

val loadingProduct = KeduxLoader<Int, Product>("product") { id -> Product(id = id, name = "Product Demo").toObservable() }

val reducer = typedReducer { state: State, action: LoadingAction<*, *> ->
    state.copy(product = loadingProduct.reducer.reduce(state.product, action))
}

val productSelector = createSelector { state: State -> state.product }
val productSuccessSelector = productSelector.success()
val productOptionalSuccessSelector = productSelector.optionalSuccess()
val productErrorSelector = productSelector.error()

val effects = Effects(loadingProduct.effect)

/**
 * Description:
 */
class LoadingTest {

    private lateinit var store: Store<State>

    @BeforeTest
    fun beforeTest() {
        applyTestSchedulers()
        store = createStore(reducer, initialLoadingState).also { effects.bindTo(it) }
    }

    @AfterTest
    fun afterTest() {
        effects.clearBindings()
    }

    @Test
    fun testRequestState() {
        var product: Product? = null
        store.select(productSuccessSelector)
                .subscribe(isThreadLocal = true) { next ->
                    product = next
                }
        store.dispatch(loadingProduct.request(5))

        assertEquals(product, Product(5, "Product Demo"))
    }

    @Test
    fun testRequestClear() {
        var product: Product? = null
        store.select(productOptionalSuccessSelector)
                .subscribe(isThreadLocal = true) { next ->
                    product = next
                }
        store.dispatch(loadingProduct.request(5))
        store.dispatch(loadingProduct.clear)

        assertNull(product)
    }

    @Test
    fun testErrorState() {
        var error: Throwable? = null
        store.select(productErrorSelector)
                .subscribe(isThreadLocal = true) { next ->
                    error = next
                }
        val error1 = Error("This is an error")
        store.dispatch(loadingProduct.error(error1))
        assertEquals(error1, error)
    }

}

