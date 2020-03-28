package sample

import com.badoo.reaktive.observable.map
import com.fuzz.kedux.Effects
import com.fuzz.kedux.createEffect

val movieAddEffect = createEffect<MovieActions.AddMovie, MovieActions.MovieAdded> { action ->
    action.map { (movie) -> MovieActions.MovieAdded(movie) }
}

val movieEffects = Effects(movieAddEffect)