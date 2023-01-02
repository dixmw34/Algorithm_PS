import java.util.*
import kotlin.math.sqrt

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    repeat(nextInt()) {
        val n = nextInt()
        val m = nextInt()
        println(solve(m - n))
    }
}

fun solve(distance: Int): Int {
    var max = sqrt(distance.toDouble()).toInt()

    return max * 2 - 1 + (distance - max * max + max - 1) / max
}

// 문제출처 : https://www.acmicpc.net/problem/1011
