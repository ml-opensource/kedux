package sample

import com.badoo.reaktive.disposable.CompositeDisposable
import com.badoo.reaktive.disposable.addTo
import com.fuzz.kedux.FracturedState
import com.fuzz.kedux.js_react.useSelector
import kotlinx.css.Display.flex
import kotlinx.css.FlexDirection.column
import kotlinx.css.display
import kotlinx.css.flexDirection
import kotlinx.html.js.onClickFunction
import react.RBuilder
import react.RComponent
import react.RProps
import react.RState
import react.dom.div
import react.functionalComponent
import react.setState
import react.useState
import styled.css
import styled.styledButton
import styled.styledDiv
import styled.styledSpan

data class State(var movies: List<Movie>) : RState

val SelectorComponent = functionalComponent<RProps> {
    val (movies, setMovies) = useState(listOf<Movie>())
    useSelector<FracturedState, List<Movie>>(setMovies) { moviesSelector(this) }
    div {
        +"Found ${movies.size}"
    }
}

class MoviesComponent : RComponent<RProps, State>() {

    private val disposable = CompositeDisposable()

    override fun State.init() {
        movies = listOf()
    }

    override fun componentDidMount() {
        moviesSelector(store).subscribe {
            setState {
                movies = it
            }
        }.addTo(disposable)
    }

    override fun componentWillUnmount() {
        disposable.dispose()
    }

    private fun addMovie() {
        store.dispatch(MovieActions.AddMovie(Movie(0, "Random Movie", "This is a movie")))
    }

    private fun removeMovie() {
        state.movies.lastOrNull()?.let { last ->
            store.dispatch(MovieActions.RemoveMovie(last))
        }
    }

    override fun RBuilder.render() {
        styledDiv {
            css {
                display = flex
                flexDirection = column
            }
            state.movies.forEach {
                styledSpan {
                    +it.name
                }
            }
            styledButton {
                +"Add Movie"
                attrs {
                    onClickFunction = { addMovie() }
                }
            }
            styledButton {
                +"Remove Movie"
                attrs {
                    onClickFunction = { removeMovie() }
                }
            }
        }
    }
}
