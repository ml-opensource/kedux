package com.fuzz.kedux

typealias ObjCClass = kotlinx.cinterop.ObjCClass

internal fun getOriginalKotlinClass(clazz: ObjCClass) = kotlinx.cinterop.getOriginalKotlinClass(clazz)
