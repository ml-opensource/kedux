package com.fuzz.kedux

typealias Enhancer<S> = (next: StoreCreator<S>) -> StoreCreator<S>
