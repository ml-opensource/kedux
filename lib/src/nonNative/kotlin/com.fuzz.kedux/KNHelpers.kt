package com.fuzz.kedux

/**
 * No-op
 */
actual fun <T> T.freeze(): T {
    return this
}

/**
 * No-op
 */
actual val <T> T.isFrozen: Boolean
    get() = false

/**
 * No-op
 */
actual fun Any.ensureNeverFrozen() = Unit
