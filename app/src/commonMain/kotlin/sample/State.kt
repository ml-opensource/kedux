package sample

import kotlinx.datetime.Clock
import kotlinx.datetime.LocalDateTime
import kotlinx.datetime.TimeZone
import kotlinx.datetime.toLocalDateTime


data class Movie(val id: Int, val name: String, val description: String,
                 val time: LocalDateTime = Clock.System.now().toLocalDateTime(TimeZone.currentSystemDefault())) {
    constructor(id: Int, name: String, description: String)
            : this(id, name, description, Clock.System.now().toLocalDateTime(TimeZone.currentSystemDefault()))
}

data class MoviesState(val movies: List<Movie>, val isMovieAdded: Boolean = false, val iosCoolAction: Boolean = false)

val defaultMoviesState = MoviesState(movies = listOf())
