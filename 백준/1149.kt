import java.util.*
import kotlin.math.min

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val n = nextInt()

    val array = Array(n) { IntArray(3) { 0 } }

    for (i in 0 until n) {
        for (j in 0 until 3) {
            array[i][j] = nextInt()
        }
    }

    val dp = Array(n) { IntArray(3) { Int.MAX_VALUE } }

    dp[0] = array[0]

    for (i in 1 until n) {
        dp[i][0] = min (dp[i-1][1], dp[i-1][2]) + array[i][0]

        dp[i][1] = min (dp[i-1][0], dp[i-1][2]) + array[i][1]

        dp[i][2] = min (dp[i-1][0], dp[i-1][1]) + array[i][2]
    }

    println(dp[n-1].minOrNull())

}

// 문제 출처 : https://www.acmicpc.net/problem/1149
