package sample

import react.dom.render
import kotlin.browser.document

val store = appGlobalStore()

fun main() {
    GlobalStyles.inject()
    document.addEventListener("DOMContentLoaded", {
        render(document.getElementById("root")) {
            child(MoviesComponent::class) {}
        }
    })
}
