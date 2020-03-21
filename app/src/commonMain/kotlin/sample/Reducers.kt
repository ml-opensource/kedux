package sample

import com.fuzz.kedux.typedReducer

val movieReducer = typedReducer<MoviesState, MovieActions> { state, action ->
    when (action) {
        is MovieActions.AddMovie -> state.copy(movies = state.movies + action.movie)
        is MovieActions.RemoveMovie -> state.copy(movies = state.movies - action.movie)
        MovieActions.ClearMovies -> state.copy(movies = listOf())
    }
}
