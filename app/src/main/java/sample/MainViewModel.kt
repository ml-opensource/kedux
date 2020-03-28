package sample

import androidx.lifecycle.ViewModel
import com.badoo.reaktive.disposable.CompositeDisposable
import com.badoo.reaktive.disposable.addTo
import com.badoo.reaktive.subject.Subject
import com.badoo.reaktive.subject.behavior.BehaviorSubject
import com.fuzz.kedux.FracturedState
import com.fuzz.kedux.Store

/**
 * Description:
 */
class MainViewModel(private val store: Store<FracturedState>) : ViewModel() {

    private val storeDisposable = CompositeDisposable()
    val moviesSubject: Subject<List<Movie>> = BehaviorSubject(listOf())

    init {
        store.select(moviesSelector)
                .subscribe { moviesSubject.onNext(it) }
                .addTo(storeDisposable)
    }

    override fun onCleared() {
        super.onCleared()
        storeDisposable.dispose()
    }
}