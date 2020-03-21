package sample

import com.fuzz.kedux.FracturedState
import com.fuzz.kedux.Store
import org.kodein.di.Kodein
import org.kodein.di.erased.bind
import org.kodein.di.erased.singleton

val kodein = Kodein {
    bind<Store<FracturedState>>() with singleton { appGlobalStore() }
}
