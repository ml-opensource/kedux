package sample

import com.fuzz.kedux.Effects
import com.fuzz.kedux.createEffect
import kotlinx.coroutines.flow.map

val movieAddEffect = createEffect<MovieActions.AddMovie, MovieActions.MovieAdded> { action ->
    action.map { (movie) -> MovieActions.MovieAdded(movie) }
}

val movieEffects = Effects(movieAddEffect)
