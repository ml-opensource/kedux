package sample

import com.fuzz.kedux.FracturedState
import com.fuzz.kedux.Store
import com.fuzz.kedux.createFracturedStore

fun store(): Store<FracturedState> = createFracturedStore(
    movieReducer to defaultMoviesState
)
