package sample

import org.kodein.di.DI

actual fun DI.MainBuilder.bindKodein() {
    import(viewModelModule)
}