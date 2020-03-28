package sample

import com.fuzz.kedux.FracturedState
import com.fuzz.kedux.Selector
import com.fuzz.kedux.Store
import com.fuzz.kedux.fracturedSelector
import com.fuzz.kedux.compose

/**
 * Description:
 */
val moviesSelector: Selector<FracturedState, List<Movie>> = fracturedSelector(movieReducer)
        .compose { it.movies }

val isMovieAddedSelector: Selector<FracturedState, Boolean> = fracturedSelector(movieReducer)
        .compose { it.isMovieAdded }
