package sample

import org.kodein.di.Kodein

actual fun Kodein.MainBuilder.bindKodein() {
    import(viewModelModule)
}