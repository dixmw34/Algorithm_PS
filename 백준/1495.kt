import java.util.*

var m = 0

val list = MutableList(50) { 0 }

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val n = nextInt()
    val s = nextInt()
    m = nextInt()

    (0 until n).forEach { index ->
        list[index] = nextInt()
    }

    var result = setOf(s)

    (0 until n).forEach { index ->
        result = solve(list[index], result)
    }

    if (result.isEmpty()) {
        println("-1")
    } else {
        println(result.maxOrNull())
    }
}

fun solve(volume: Int, temp: Set<Int>): Set<Int> {
    val result = mutableSetOf<Int>()
    temp.forEach { num ->
        if (num + volume in (0 .. m)) {
            result.add(num + volume)
        }

        if (num - volume in (0 .. m)) {
            result.add(num - volume)
        }
    }
    return result
}

// 문제 출처 : https://www.acmicpc.net/problem/1495
