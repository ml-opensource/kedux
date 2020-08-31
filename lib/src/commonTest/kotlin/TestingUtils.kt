import kotlin.test.assertEquals
import kotlin.test.assertTrue

/**
 * Description: Console logs the assertion.
 */
fun <T> logAssertEquals(value1: T, value2: T) {
    println("${platformName()} Asserting: ${value1} == ${value2}")
    assertEquals(value1, value2)
}

fun logAssertTrue(value: Boolean) {
    println("${platformName()} Asserting: true == ${value}")
    assertTrue(value)
}

expect fun platformName(): String