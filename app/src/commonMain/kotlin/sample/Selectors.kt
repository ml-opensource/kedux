package sample

import com.badoo.reaktive.observable.ObservableWrapper
import com.badoo.reaktive.observable.map
import com.badoo.reaktive.observable.wrap
import com.fuzz.kedux.FracturedState
import com.fuzz.kedux.Store
import com.fuzz.kedux.fracturedSelector

/**
 * Description:
 */
fun moviesSelector(store: Store<FracturedState>): ObservableWrapper<List<Movie>> =
    store.fracturedSelector(movieReducer)
        .map { it.movies }
        .wrap()