package sample

import com.fuzz.kedux.Store
import com.fuzz.kedux.js_react.StoreProvider
import kotlinx.browser.document
import react.child
import react.dom.render

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
