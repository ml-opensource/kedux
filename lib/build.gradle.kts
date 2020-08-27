import org.jetbrains.kotlin.gradle.tasks.KotlinCompile

plugins {
    kotlin("multiplatform")
    id("org.jetbrains.kotlin.native.cocoapods")
    id("maven-publish")
    id("com.android.library")
}
group = "com.example"
version = "0.0.1"

tasks.withType<KotlinCompile> {
    kotlinOptions {
        jvmTarget = "1.8"
    }
}

kotlin {
    jvm()
    android()
    js {
        browser {
        }
        nodejs {
        }
        binaries.executable()
    }
    // For ARM, should be changed to iosArm32 or iosArm64
    // For Linux, should be changed to e.g. linuxX64
    // For MacOS, should be changed to e.g. macosX64
    // For Windows, should be changed to e.g. mingwX64
    //macosX64("macos")
    ios {
        binaries {
            executable {
                baseName = "Kedux"
            }
        }
    }
    val hostOs = System.getProperty("os.name")
    val isMingwX64 = hostOs.startsWith("Windows")
    val nativeTarget = when {
        hostOs == "Mac OS X" -> macosX64("desktop")
        hostOs == "Linux" -> linuxX64("desktop")
        isMingwX64 -> mingwX64("desktop")
        else -> throw GradleException("Host OS is not supported in Kotlin/Native.")
    }
    cocoapods {
        // Configure fields required by CocoaPods.
        summary = "Kedux is a kotlin-multiplatform state management library."
        homepage = "Link to a Kotlin/Native module homepage"
    }

    sourceSets {
        all {
            languageSettings.useExperimentalAnnotation("kotlinx.coroutines.ExperimentalCoroutinesApi")
            languageSettings.useExperimentalAnnotation("kotlinx.coroutines.FlowPreview")
        }
        val commonMain by getting {
            dependencies {
                api(Dependencies.Coroutines)
                api(Dependencies.AtomicFu)
            }
        }
        val commonTest by getting {
            dependencies {
                implementation(kotlin("test-common"))
                implementation(kotlin("test-annotations-common"))
                implementation("org.jetbrains.kotlinx:kotlinx-coroutines-test:1.3.8")
            }
        }
        val nonNative by creating {
            dependsOn(commonMain)
        }
        val nativeMain by creating {
            dependsOn(commonMain)
        }
        val nativeTest by creating {
            dependsOn(commonTest)
            dependsOn(nativeMain)
        }
        val iosMain by getting
        iosMain.dependsOn(nativeMain)
        val iosTest by getting
        iosTest.dependsOn(nativeTest)

        val desktopMain by getting
        desktopMain.dependsOn(nativeMain)
        val desktopTest by getting
        desktopTest.dependsOn(nativeTest)
        val jvmMain by getting {
            dependsOn(nonNative)
        }
        val jvmTest by getting {
            dependencies {
                implementation(kotlin("test"))
                implementation(kotlin("test-junit"))
            }
        }
        val androidMain by getting {
            dependsOn(jvmMain)
        }
        val androidTest by getting {
            dependencies {
                implementation(kotlin("test"))
                implementation(kotlin("test-junit"))
            }
        }
        val jsMain by getting {
            dependsOn(nonNative)
        }
        val jsTest by getting
    }
}

android {
    compileSdkVersion(29)
    defaultConfig {
        minSdkVersion(21)
        targetSdkVersion(29)
    }
    buildTypes {
        getByName("release") {
            minifyEnabled(false)
        }
    }

    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_1_8
        targetCompatibility = JavaVersion.VERSION_1_8
    }
}
