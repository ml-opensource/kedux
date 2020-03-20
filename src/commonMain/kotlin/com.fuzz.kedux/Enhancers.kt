package com.fuzz.kedux

typealias Enhancer<S> = (store: Store<S>) -> (next: (action: Any) -> Any) -> (action: Any) -> Any

fun <S: Any> emptyEnhancer(): Enhancer<S> = { _: Store<S> ->
    { next -> { action -> next(action) } }
}
