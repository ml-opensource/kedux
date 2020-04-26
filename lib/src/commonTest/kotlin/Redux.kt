import com.fuzz.kedux.Action
import com.fuzz.kedux.actionTypeReducer
import com.fuzz.kedux.createAction
import com.fuzz.kedux.typedReducer

sealed class StoreTestAction {

    data class NameChange(val name: String) :
            StoreTestAction()

    data class NamedChanged(val name: String) : StoreTestAction()

    data class LocationChange(val location: Location) :
            StoreTestAction()

    data class LocationChanged(val other: String) :
            StoreTestAction()

    object Reset : StoreTestAction()
}

val sampleReducer = typedReducer<GlobalState, StoreTestAction> { state, action ->
    println("Action received ${action}")
    when (action) {
        is StoreTestAction.NameChange -> state.copy(name = action.name)
        is StoreTestAction.Reset -> state
        is StoreTestAction.LocationChange -> state.copy(location = action.location)
        is StoreTestAction.NamedChanged -> state.copy(nameChanged = true)
        is StoreTestAction.LocationChanged -> state
    }
}

val sampleReducer2 = typedReducer<GlobalState, ProductActions> { state, action ->
    when (action) {
        is ProductActions.NameChange -> state
    }
}

sealed class ProductActions {
    data class NameChange(val name: String) : ProductActions()
}

val productReducer = typedReducer<Product, ProductActions> { state, action ->
    when (action) {
        is ProductActions.NameChange -> state.copy(name = action.name)
    }
}

sealed class LocationActions {
    data class ProductChange(val product: Product) : LocationActions()
}

val locationReducer = typedReducer<Location, LocationActions> { state, action ->
    when (action) {
        is LocationActions.ProductChange -> state.copy(product = action.product)
    }
}

enum class SampleEnumType {
    LocationChange,
    NameChange,
    Reset
}

val sampleTypedReducer = actionTypeReducer { state: GlobalState, action: Action<SampleEnumType, out Any> ->
    when (action.type) {
        SampleEnumType.LocationChange -> state.copy(location = action.payload as Location?)
        SampleEnumType.NameChange -> state.copy(name = action.payload as String)
        SampleEnumType.Reset -> initialState
    }
}

val locationChange = createAction(SampleEnumType.LocationChange) { payload: Location -> payload }
val nameChange = createAction(SampleEnumType.NameChange) { payload: String -> payload }
val resetAction = createAction(SampleEnumType.Reset)
