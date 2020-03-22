package com.fuzz.kedux.js_react

import com.badoo.reaktive.observable.Observable
import com.badoo.reaktive.observable.distinctUntilChanged
import com.badoo.reaktive.observable.subscribe
import com.fuzz.kedux.Store
import react.useEffectWithCleanup

/**
 * Provides a hook into the selector for the [Store], providing cleanup.
 */
fun <S : Any, R : Any> Store<S>.useSelector(setValue: (value: R) -> Unit, fn: Store<S>.() -> Observable<R>) =
        useEffectWithCleanup(listOf(setValue)) {
            val observable = fn()
                    .distinctUntilChanged() // only emit if changed.
                    .subscribe {
                        setValue(it)
                    }
            return@useEffectWithCleanup { observable.dispose() }
        }
