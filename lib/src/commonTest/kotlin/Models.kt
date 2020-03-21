data class Product(val id: Int, val name: String)
data class Location(val id: Int, val other: String, val product: Product? = null)
data class GlobalState(val name: String, val location: Location? = null)

val initialState = GlobalState(name = "", location = null)
