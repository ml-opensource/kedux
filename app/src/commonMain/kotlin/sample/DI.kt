package sample

import com.fuzz.kedux.FracturedState
import com.fuzz.kedux.Store
import org.kodein.di.DI
import org.kodein.di.bind
import org.kodein.di.singleton

val kodein = DI {
    bind<Store<FracturedState>>() with singleton { appGlobalStore() }
    bindKodein()
}

expect fun DI.MainBuilder.bindKodein()
