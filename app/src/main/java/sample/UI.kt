package sample

import androidx.compose.Composable
import androidx.ui.core.Text
import androidx.ui.layout.Column

/**
 * Description:
 */
@Composable
fun MoviesList(moviesList: List<Movie>) {
    Column {
        moviesList.map { Text(text = it.name) }
    }
}