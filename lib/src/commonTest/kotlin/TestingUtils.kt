import kotlin.test.assertEquals

/**
 * Description: Console logs the assertion.
 */
fun <T> logAssertEquals(value1: T, value2: T) {
    println("${platformName()} Asserting: ${value1} == ${value2}")
    assertEquals(value1, value2)
}

expect fun platformName(): String