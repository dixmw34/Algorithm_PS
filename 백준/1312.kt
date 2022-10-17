import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    var a = nextInt()
    val b = nextInt()
    val n = nextInt()

    repeat(n) {
        a %= b
        a *= 10
    }

    println((a/b))
}
