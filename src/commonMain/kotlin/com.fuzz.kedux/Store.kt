package com.fuzz.kedux

typealias StoreCreator<S> = (reducer: Reducer<S>, initialState: S) -> Store<S>
typealias ChangeListener<S> = (state: S) -> Unit

@Suppress("UNCHECKED_CAST")
fun <S> createStore(
    reducer: Reducer<S>,
    initialState: S,
    enhancer: Enhancer<S>? = null
) =
    Store(reducer, initialState, enhancer)

class Store<S>(
    private var reducer: Reducer<S>,
    initialState: S,
    private val enhancer: Enhancer<S>? = null
) {
    private var _state: S = initialState
    private val changeListenerSet = mutableSetOf<ChangeListener<S>>()

    val state: S
        get() = _state

    fun dispatch(action: Any) {
        _state = reducer.reduce(_state, action)
        changeListenerSet.forEach { it(_state) }
    }

    fun subscribe(fn: ChangeListener<S>) {
        changeListenerSet.add(fn)
    }

    fun unsubscribe(fn: ChangeListener<S>) {
        changeListenerSet.remove(fn)
    }

    fun replaceReducer(reducer: Reducer<S>) {
        this.reducer = reducer
    }
}
