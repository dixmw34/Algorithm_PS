import java.util.*
import kotlin.math.sqrt

val dp = Array(31) { LongArray (31) { -1L } }

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    repeat(nextInt()) {
        val n = nextInt()
        val m = nextInt()
        println(solve(n, m))
    }
}

fun solve(n: Int, m: Int): Long {
    if (n == 1) {
        return m.toLong()
    } else if (n == m) {
        return 1L
    } else if (n > m) {
        return 0L
    }

    if (dp[n][m] != -1L) {
        return dp[n][m]
    }

    var result = 0L
    (1 until m).forEach { index ->
        result += solve(n - 1, index)
    }

    dp[n][m] = result
    return dp[n][m]
}

// 문제출처 : https://www.acmicpc.net/problem/1010
