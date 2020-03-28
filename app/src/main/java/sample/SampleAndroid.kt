package sample

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
import com.badoo.reaktive.disposable.CompositeDisposable
import com.badoo.reaktive.disposable.addTo
import com.badoo.reaktive.observable.map
import com.badoo.reaktive.observable.subscribe
import com.badoo.reaktive.observable.take
import com.fuzz.kedux.FracturedState
import com.fuzz.kedux.Store
import org.kodein.di.erased.instance
import sample.databinding.ActivityMainBinding
import sample.databinding.ListItemMovieBinding

class MainActivity : AppCompatActivity() {

    private val store: Store<FracturedState> by kodein.instance()
    private val viewModelFactory: ViewModelProvider.Factory by kodein.instance()

    private val disposable = CompositeDisposable()

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

        binding.addMovie.setOnClickListener {
            store.dispatch(MovieActions.AddMovie(Movie(5, "This is test movie", "Movies are good.")))
        }

        binding.removeMovie.setOnClickListener {
            viewModel.moviesSubject.take(1)
                    .map { it.lastOrNull() }
                    .subscribe { movie ->
                        if (movie != null) {
                            store.dispatch(MovieActions.RemoveMovie(movie))
                        }
                    }.addTo(disposable)
        }

        viewModel.moviesSubject
                .subscribe { movies -> movieAdapter.submitList(movies) }
                .addTo(disposable)
    }

    override fun onDestroy() {
        super.onDestroy()
        disposable.clear()
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