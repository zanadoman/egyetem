fun main() {
    println("Hello, World!")

    // Variables, datatypes
    var variable1: Int = 0
    var variable2 = 0
    val constant = 0

    // Late initialization
    lateinit var file: String
    file = "hello"
    println(file)

    /// Float, double
    val pif = 3.14F
    val pi = 3.14

    // Strings, concat
    val fruit1 = "pine"
    val fruit2 = "apple"
    val fruit3 = fruit1 + fruit2
    println("Fruit $fruit3")

    // Arrays
    val array = arrayOf(1, 2, 3)
    array.forEach {
        println(it)
    }

    var sum = 0;
    array.forEach {
        sum += it
    }
    println(sum)

    // Delegate
    val add: (Int, Int) -> Int
    add = {x: Int, y: Int -> x + y}
    println(add(5, 7))
}
