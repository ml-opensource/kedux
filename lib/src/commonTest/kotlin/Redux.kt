import com.fuzz.kedux.typedReducer

sealed class StoreTestAction {

    data class NameChange(val name: String) :
        StoreTestAction()

    data class LocationChange(val location: Location) :
        StoreTestAction()

    object Reset : StoreTestAction()
}

val sampleReducer = typedReducer<GlobalState, StoreTestAction> { state, action ->
    when (action) {
        is StoreTestAction.NameChange -> state.copy(name = action.name)
        is StoreTestAction.Reset -> state
        is StoreTestAction.LocationChange -> state.copy(location = action.location)
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
