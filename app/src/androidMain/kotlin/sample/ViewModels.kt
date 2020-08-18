package sample

import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import org.kodein.di.DirectDI
import org.kodein.di.DI
import org.kodein.di.direct
import org.kodein.di.bind
import org.kodein.di.instance
import org.kodein.di.instanceOrNull
import org.kodein.di.provider
import org.kodein.di.singleton

/**
 * Description:
 */
val viewModelModule = DI.Module(name = "viewModelModule") {
    bind<ViewModelProvider.Factory>() with singleton { ViewModelFactory(kodein.direct) }
    bind<ViewModel>(tag = MainViewModel::class.java.simpleName) with provider {
        MainViewModel(instance())
    }
}

class ViewModelFactory(private val injector: DirectDI) : ViewModelProvider.Factory {

    override fun <T : ViewModel> create(modelClass: Class<T>): T {
        return injector.instanceOrNull<ViewModel>(tag = modelClass.simpleName) as T?
                ?: modelClass.newInstance()
    }
}
