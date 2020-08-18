package sample

import android.content.Intent
import android.os.Bundle
import android.view.LayoutInflater
import android.view.ViewGroup
import androidx.activity.viewModels
import androidx.appcompat.app.AppCompatActivity
import androidx.lifecycle.ViewModelProvider
import androidx.recyclerview.widget.DiffUtil
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.ListAdapter
import androidx.recyclerview.widget.RecyclerView
import com.fuzz.kedux.FracturedState
import com.fuzz.kedux.Store
import org.kodein.di.instance
import sample.databinding.ActivityMainBinding
import sample.databinding.ListItemMovieBinding
import androidx.lifecycle.lifecycleScope
import kotlinx.coroutines.flow.launchIn
import kotlinx.coroutines.flow.onEach
import kotlinx.coroutines.flow.map
import kotlinx.coroutines.flow.take

class MainActivity : AppCompatActivity() {

    private val store: Store<FracturedState> by kodein.instance()
    private val viewModelFactory: ViewModelProvider.Factory by kodein.instance()

    private val binding: ActivityMainBinding by lazy { ActivityMainBinding.inflate(layoutInflater) }

    private val viewModel: MainViewModel by viewModels { viewModelFactory }

    private val movieAdapter = MovieAdapter()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(binding.root)
        binding.recyclerView.apply {
            layoutManager = LinearLayoutManager(context)
            adapter = movieAdapter
        }

        binding.composeButton.setOnClickListener {
            startActivity(Intent(this, ComposeActivity::class.java))
        }

        binding.addMovie.setOnClickListener {
            store.dispatch(MovieActions.AddMovie(Movie(5, "This is test movie", "Movies are good.")))
        }

        binding.removeMovie.setOnClickListener {
            viewModel.moviesSubject.take(1)
                    .map { it.lastOrNull() }
                    .onEach { movie ->
                        if (movie != null) {
                            store.dispatch(MovieActions.RemoveMovie(movie))
                        }
                    }.launchIn(lifecycleScope)
        }

        viewModel.moviesSubject
                .onEach { movies -> movieAdapter.submitList(movies) }
                .launchIn(lifecycleScope)
    }

}

class MovieViewHolder(parent: ViewGroup) : RecyclerView.ViewHolder(LayoutInflater.from(parent.context).inflate(R.layout.list_item_movie, parent, false)) {
    val binding = ListItemMovieBinding.bind(itemView)
}

class MovieAdapter : ListAdapter<Movie, MovieViewHolder>(object : DiffUtil.ItemCallback<Movie>() {
    override fun areItemsTheSame(oldItem: Movie, newItem: Movie): Boolean = oldItem === newItem

    override fun areContentsTheSame(oldItem: Movie, newItem: Movie): Boolean = oldItem == newItem
}) {
    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): MovieViewHolder = MovieViewHolder(parent)

    override fun onBindViewHolder(holder: MovieViewHolder, position: Int) {
        val movie = getItem(position)
        holder.binding.apply {
            title.text = movie.name
            description.text = movie.description
        }
    }
}