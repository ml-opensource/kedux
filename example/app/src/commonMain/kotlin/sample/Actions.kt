package sample

sealed class MovieActions {

    data class AddMovie(val movie: Movie) : MovieActions()

    data class RemoveMovie(val movie: Movie) : MovieActions()

    object ClearMovies : MovieActions()
}
