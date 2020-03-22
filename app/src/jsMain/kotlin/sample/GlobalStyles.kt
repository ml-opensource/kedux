package sample

import kotlinext.js.invoke
import kotlinx.css.CSSBuilder
import kotlinx.css.body
import kotlinx.css.margin
import kotlinx.css.padding
import kotlinx.css.px
import styled.StyledComponents

object GlobalStyles {
    fun inject() {
        val styles = CSSBuilder(allowClasses = false).apply {
            body {
                margin(0.px)
                padding(0.px)
            }
        }

        StyledComponents.createGlobalStyle(styles.toString())
    }
}
