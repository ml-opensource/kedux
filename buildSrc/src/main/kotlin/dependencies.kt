val kotlin_version = "1.4.0"
val reaktiveVersion = "1.1.16"
val reactVersion = "16.13.1"
val atomicfu_version = "0.14.4"
val preVersion = "pre.110-kotlin"
val kodeinVersion = "7.1.0-master-80"
val compose_version = "0.1.0-dev16"

val coroutinesVersion = "1.3.8-native-mt-1.4.0-rc"

object Dependencies {
    val AtomicFu = "org.jetbrains.kotlinx:atomicfu:$atomicfu_version"
    val React = "org.jetbrains:kotlin-react:${reactVersion}-${preVersion}-${kotlin_version}-rc"
    val ReactDom = "org.jetbrains:kotlin-react-dom:${reactVersion}-${preVersion}-${kotlin_version}-rc"
    val Coroutines = "org.jetbrains.kotlinx:kotlinx-coroutines-core:${coroutinesVersion}"
}