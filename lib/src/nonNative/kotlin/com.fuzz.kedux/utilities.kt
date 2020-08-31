package com.fuzz.kedux

import kotlinx.coroutines.CoroutineDispatcher
import kotlinx.coroutines.Dispatchers

actual fun getBackgroundDispatch(): CoroutineDispatcher = Dispatchers.Default

