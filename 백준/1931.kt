import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {

    val n = nextInt()

    val list = mutableListOf<Pair<Long, Long>>()

    repeat(n) {
        val a = nextLong()
        val b = nextLong()

        list.add(a to b)
    }

    val sorted = list.sortedWith(compareBy({it.first}, {it.second}))

    var result = 0
    var time = 0L

    sorted.forEach {
        if (time <= it.first) {
            time = it.second
            result++
        } else if (time > it.second) {
            time = it.second
        }
    }

    println(result)

}

// 문제 출처 : https://www.acmicpc.net/problem/1931
