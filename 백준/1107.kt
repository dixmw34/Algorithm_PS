import java.util.*
import kotlin.math.absoluteValue
import kotlin.math.min

val set = mutableSetOf("0", "1", "2", "3", "4", "5", "6", "7", "8", "9")

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val channel = nextInt()

    var cnt = nextInt()

    while(cnt-- > 0) {
        val num = nextInt().toString()
        set.remove(num)
    }

    var result = (channel - 100).absoluteValue

    (0..9999999).forEach {
        if (isPossible(it)) {
            result = min((channel - it).absoluteValue + it.toString().length, result)
        }
    }

    println(result)
}

private fun isPossible(num: Int): Boolean {
    num.toString().forEach { ch ->
        if (set.contains(ch.toString()).not()) {
            return false
        }
    }
    return true
}
