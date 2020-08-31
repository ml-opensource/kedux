pluginManagement {
    repositories {
        maven { url = uri("https://dl.bintray.com/kotlin/kotlin-eap") }

        mavenCentral()

        maven { url = uri("https://plugins.gradle.org/m2/") }
    }
}
rootProject.name = "kedux"

include(":lib", ":app", ":js-react")
enableFeaturePreview("GRADLE_METADATA")
