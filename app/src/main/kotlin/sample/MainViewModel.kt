package sample

import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import com.fuzz.kedux.FracturedState
import com.fuzz.kedux.Store
import kotlinx.coroutines.ExperimentalCoroutinesApi
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.launchIn
import kotlinx.coroutines.flow.onEach

/**
 * Description:
 */
@ExperimentalCoroutinesApi
class MainViewModel(store: Store<FracturedState>) : ViewModel() {

    val moviesSubject: MutableStateFlow<List<Movie>> = MutableStateFlow(listOf())

    init {
        store.select(moviesSelector)
                .onEach { moviesSubject.value = it }
                .launchIn(viewModelScope)
    }
}
