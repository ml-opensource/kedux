package sample

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import androidx.ui.core.Text
import androidx.ui.core.setContent
import com.badoo.reaktive.disposable.CompositeDisposable
import com.badoo.reaktive.disposable.addTo
import com.badoo.reaktive.observable.subscribe
import com.fuzz.kedux.FracturedState
import com.fuzz.kedux.Store
import com.fuzz.kedux.fracturedSelector
import org.kodein.di.erased.instance

class MainActivity : AppCompatActivity() {

    private val store by kodein.instance<Store<FracturedState>>()

    private val disposable = CompositeDisposable()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            Text(text = "Hello Worldies")
            store.fracturedSelector(movieReducer) { it.movies }
                .subscribe { movies -> MoviesList(moviesList = movies) }
                .addTo(disposable)
        }

        store.dispatch(MovieActions.AddMovie(Movie(1, "Name", "Description")))
    }

    override fun onDestroy() {
        super.onDestroy()
        disposable.clear()
    }
}
