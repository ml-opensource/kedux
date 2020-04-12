package com.fuzz.kedux

import kotlin.reflect.KClass

typealias ObjCClass = kotlinx.cinterop.ObjCClass

internal fun getOriginalKotlinClass(clazz: ObjCClass) = kotlinx.cinterop.getOriginalKotlinClass(clazz)

/**
 * Finds an [ObjCClass] from [KClass] by looking up original [getOriginalKotlinClass]
 */
internal fun Map<ObjCClass, Any>.findByKClass(valueClass: KClass<*>): Any {
    return entries.first { (key, value) ->
        getOriginalKotlinClass(key) == valueClass
    }.value
}