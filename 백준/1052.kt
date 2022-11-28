import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {

    val a = nextInt()
    val b = nextInt()

    var max = 1

    while(max < a) {
        max *= 2
    }

    (a .. max).forEach { num ->
        val string = Integer.toBinaryString(num)
        val cnt = count(string)
        if (cnt <= b) {
            println(num-a)
            return@with
        }
    }
}

fun count(st: String): Int {
    var cnt = 0
    st.forEach { ch ->
        if (ch == '1') cnt ++
    }
    return cnt
}

// 문제 출처 : https://www.acmicpc.net/problem/1052
