import app.cash.turbine.test
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
import kotlinx.coroutines.flow.flowOf
import kotlin.test.BeforeTest
import kotlin.test.Test
import kotlin.test.assertNull
import logAssertEquals as assertEquals

data class State(val product: LoadingModel<Product> = LoadingModel.empty())

val initialLoadingState = State()

val loadingProduct = KeduxLoader<Int, Product>("product") { id -> flowOf(Product(id = id, name = "Product Demo")) }

val reducer = typedReducer { state: State, action: LoadingAction<*, *> ->
    state.copy(product = loadingProduct.reducer.reduce(state.product, action))
}

val productSelector = createSelector() { state: State -> state.product }
val productSuccessSelector = productSelector.success()
val productOptionalSuccessSelector = productSelector.optionalSuccess()
val productErrorSelector = productSelector.error()


/**
 * Description:
 */
class LoadingTest : BaseTest() {

    private lateinit var store: Store<State>
    private lateinit var effects: EffectTester<State>

    @BeforeTest
    fun beforeTest() {
        store = createStore(reducer, initialLoadingState)
        effects = EffectTester(Effects(loadingProduct.effect), store)
    }

    @Test
    fun testRequestState() = runBlocking {
        effects.use(this) {
            store.select(productSuccessSelector)
                    .test {
                        store.dispatch(loadingProduct.request(5))
                        assertEquals(Product(5, "Product Demo"), expectItem())
                    }
        }
    }

    @Test
    fun testRequestClear() = runBlocking {
        effects.use(this) {
            store.select(productOptionalSuccessSelector)
                    .test {
                        assertNull(expectItem())

                        store.dispatch(loadingProduct.request(5))
                        assertNull(expectItem())

                        store.dispatch(loadingProduct.clear)
                        assertNull(expectItem())
                    }
        }
    }

    @Test
    fun testErrorState() = runBlocking {
        effects.use(this) {
            store.select(productErrorSelector)
                    .test {
                        val error1 = Error("This is an error")
                        store.dispatch(loadingProduct.error(error1))
                        assertEquals(error1, expectItem())
                    }
        }
    }

}

