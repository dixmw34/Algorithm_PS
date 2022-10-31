import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val n = nextLine().toInt()

    val regex = "(100+1+|01)+".toRegex()

    repeat(n) {
        val input = nextLine()

        val message = if (regex.matches(input)) { "YES" } else { "NO" }
        println(message)
    }
}

// 문제 링크 : https://www.acmicpc.net/problem/1013
