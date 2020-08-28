buildscript {
    repositories {
        google()
        jcenter()
        maven { url = uri("https://dl.bintray.com/kotlin/kotlin-eap") }
    }

    dependencies {
        classpath("com.android.tools.build:gradle:4.2.0-alpha07")
        classpath("org.jetbrains.kotlin:kotlin-gradle-plugin:$kotlin_version")
        classpath("org.jetbrains.kotlinx:atomicfu-gradle-plugin:$atomicfu_version")
        classpath("co.touchlab:kotlinnativecocoapods:0.11")
    }
}

plugins {
    kotlin("multiplatform") version kotlin_version apply false
}

subprojects {
    repositories {
        google()
        jcenter()
        //maven(url = "https://dl.bintray.com/ekito/koin") TODO: revert when Koin is available
        maven(url = "https://dl.bintray.com/touchlabpublic/kotlin")
        maven { url = uri("https://dl.bintray.com/kotlin/kotlin-eap") }
        maven { url = uri("https://kotlin.bintray.com/kotlin-js-wrappers/") }
        maven {
            url = uri("https://dl.bintray.com/kodein-framework/kodein-dev")
        }
    }
}
