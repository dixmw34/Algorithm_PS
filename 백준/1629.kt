import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {

    var a = nextLong()
    var b = nextInt()
    val c = nextLong()

    var result = 1L

    while(b != 0) {
        if (b % 2 == 1) {
            result = (result * a) % c
        }
        a = (a * a) % c
        b = (b/2)
    }

    println(result)
}

// 문제 출처 : https://www.acmicpc.net/problem/1629
