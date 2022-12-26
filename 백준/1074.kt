import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val n = nextInt()
    val r = nextInt()
    val c = nextInt()

    println(solve(n, r, c))
}

fun solve(n: Int, r: Int, c: Int): Int {
    if (n == 0) return 0

    val temp = 1.shl(n -1)

    var result = 0
    if (r >= temp) {
        result += 2
    }
    if (c >= temp) {
        result += 1
    }

    return result * 1.shl(2 * (n - 1)) + solve(n-1, r.index(temp), c.index(temp))
}

fun Int.index(temp: Int) = if (this - temp < 0) {
        this
    } else {
        this - temp
    }

// 문제 출처 : https://www.acmicpc.net/problem/1074
