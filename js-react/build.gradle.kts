plugins {
    kotlin("multiplatform")
    id("maven-publish")
}
group = "com.example"
version = "0.0.1"

kotlin {
    js {
        browser {
        }
        useCommonJs()
        binaries.executable()
    }
    sourceSets {
        val commonMain by getting {
            dependencies {
                api(project(":lib"))
            }
        }
        val commonTest by getting {
            dependencies {
                implementation(kotlin("test-common"))
                implementation(kotlin("test-annotations-common"))
            }
        }
        val jsMain by getting {
            dependencies {
                api(Dependencies.React)
                api(Dependencies.ReactDom)
            }
        }
        val jsTest by getting {
            dependencies {
                implementation(kotlin("test-js"))
            }
        }
    }
}
