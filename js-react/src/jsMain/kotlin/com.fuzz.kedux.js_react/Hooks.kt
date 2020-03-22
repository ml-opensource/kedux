package com.fuzz.kedux.js_react

import com.badoo.reaktive.observable.Observable
import com.badoo.reaktive.observable.distinctUntilChanged
import com.badoo.reaktive.observable.subscribe
import com.fuzz.kedux.Store
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
fun <S : Any, R : Any> useSelector(setValue: (value: R) -> Unit, fn: Store<S>.() -> Observable<R>) {
    val store = useStore<S>()
    useEffectWithCleanup(listOf(store, setValue)) {
        val observable = store.fn()
                .distinctUntilChanged() // only emit if changed.
                .subscribe {
                    setValue(it)
                }
        return@useEffectWithCleanup { observable.dispose() }
    }
}

/**
 * Convenience hook to grab dispatcher.
 */
fun useDispatch(): (Any) -> Unit {
    val store = useStore<dynamic>()
    return store::dispatch
}
