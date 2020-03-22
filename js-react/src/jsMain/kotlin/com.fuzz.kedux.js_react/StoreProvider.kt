package com.fuzz.kedux.js_react

import com.fuzz.kedux.Store
import react.RBuilder
import react.RContext
import react.RElementBuilder
import react.RProviderProps
import react.createContext

val KeduxContext: RContext<Store<dynamic>> = createContext()

/**
 * Provides the [Store] object down the tree.
 */
fun RBuilder.StoreProvider(store: Store<dynamic>, handler: RElementBuilder<RProviderProps<Store<dynamic>>>.() -> Unit) =
        KeduxContext.Provider(value = store, handler = handler)
