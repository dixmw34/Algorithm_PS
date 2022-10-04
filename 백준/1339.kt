import java.util.*
import kotlin.math.pow


fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val num = nextLine().toInt()
    val list = MutableList(26) { 0L }

    repeat(num) {
        val st = nextLine()
        for (i in st.indices) {
            list[st[i] - 'A'] += (10.0).pow(st.length - i - 1).toLong()
        }
    }

    list.sort()
    list.reverse()

    var result = 0L

    for (i in 0 until 10) {
        result += list[i] * (9 - i)
    }

    println(result)

}
