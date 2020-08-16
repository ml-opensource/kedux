package com.fuzz.kedux.js_react

import com.fuzz.kedux.Selector
import com.fuzz.kedux.Store
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.flow.launchIn
import kotlinx.coroutines.flow.onEach
import react.useContext
import react.useEffectWithCleanup

internal external val process: dynamic = definedExternally

/**
 * [useContext] convenience.
 */
fun <S : Any> useStore(): Store<S> {
    val store = useContext<Store<S>>(KeduxContext)
    if (process.env.NODE_ENV !== "production" && store == null) {
        throw Error("could not find kedux store context value; please ensure the component is wrapped in a StoreProvider")
    }
    return store
}

/**
 * useSelector referencing context. This requires a [Store] provided using the [StoreProvider] globally to use.
 */
fun <S : Any, R : Any> useSelector(setValue: (value: R) -> Unit, selector: Selector<S, R>) {
    val store = useStore<S>()
    useEffectWithCleanup(listOf(store, setValue, selector)) {
        val observable = store.select(selector) // only emit if changed.
                .onEach {
                    setValue(it)
                }.launchIn(CoroutineScope(Dispatchers.Main))
        return@useEffectWithCleanup { observable.cancel() }
    }
}

/**
 * Convenience hook to grab dispatcher.
 */
fun useDispatch(): (Any) -> Unit {
    val store = useStore<dynamic>()
    return store::dispatch
}
