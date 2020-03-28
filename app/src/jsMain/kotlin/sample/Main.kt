package sample

import com.fuzz.kedux.Store
import com.fuzz.kedux.js_react.StoreProvider
import react.child
import react.dom.render
import kotlin.browser.document

val store = appGlobalStore()

fun main() {
    GlobalStyles.inject()
    Store.loggingEnabled = true
    document.addEventListener("DOMContentLoaded", {
        render(document.getElementById("root")) {
            StoreProvider(store) {
                child(MoviesComponent::class) {}
                child(SelectorComponent)
            }
        }
    })
}
