package sample


data class Movie(val id: Int, val name: String, val description: String)

data class MoviesState(val movies: List<Movie>)

val defaultMoviesState = MoviesState(movies = listOf())
