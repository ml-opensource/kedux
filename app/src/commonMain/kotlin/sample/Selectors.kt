package sample

import com.fuzz.kedux.FracturedState
import com.fuzz.kedux.Selector
import com.fuzz.kedux.compose
import com.fuzz.kedux.fracturedSelector

/**
 * Description:
 */
val moviesSelector: Selector<FracturedState, List<Movie>> = fracturedSelector(movieReducer)
        .compose { it.movies }

val isMovieAddedSelector: Selector<FracturedState, Boolean> = fracturedSelector(movieReducer)
        .compose { it.isMovieAdded }
