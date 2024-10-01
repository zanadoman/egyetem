package org.example

interface Adult {
    fun adult(): Boolean
}

open class Person(name: String, age: Int) : Adult {
    var name: String
        protected set

    var age: Int
        protected set

    init {
        this.name = name
        this.age = age
    }

    constructor(name: String) : this(name, 18)

    override fun adult(): Boolean {
        return 18 <= age
    }

    open fun greet() {
        println("Hi!")
    }

    override fun toString(): String {
        return "Name: " + name + ", Age: " + age + ", Adult: " + adult()
    }
}

abstract class Employee(name: String, age: Int, profession: String) : Person(name, age) {
    var profession: String
        private set

    init {
        this.profession = profession
    }

    override fun greet() {
        println("Good morning!")
    }

    abstract fun work()
}

class Smith(name: String, age: Int) : Employee(name, age, "smith") {
    override fun work() {
        println("Smith working on a claymore...")
    }
}

data class Position(val x: Double, val y: Double)

fun main() {
    println("Hello World!")
    var person = Person("John Doe", 20)
    println(person)
    println(Position(0.0, 5.0))
}
