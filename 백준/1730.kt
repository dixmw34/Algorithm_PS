import java.util.*

val array = Array(10) { CharArray(10) { '.' } }

var n = 0

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    n = nextLine().toInt()

    val input = nextLine()

    var start = 0 to 0

    input.forEach { ch ->
        start = when(ch) {
            'U' -> go(start, -1 to 0)
            'D' -> go(start, 1 to 0)
            'L' -> go(start, 0 to -1)
            'R' -> go(start, 0 to 1)
            else -> start
        }
    }

    array.sliceArray(0 until n).forEach {
        println(it.sliceArray(0 until n).joinToString(""))
    }
}

fun go(cur: Pair<Int, Int>, des: Pair<Int, Int>): Pair<Int, Int> {
    val next = cur + des

    return if (next.isInside()) {
        draw(cur, des)
        draw(next, des)

        next
    } else {
        cur
    }

}

operator fun Pair<Int, Int>.plus(other: Pair<Int, Int>) = Pair(this.first + other.first, this.second + other.second)

fun Pair<Int, Int>.isInside() = (this.first in 0 until n) && (this.second in 0 until n)

private fun draw(point: Pair<Int, Int>, des: Pair<Int, Int>) {
    if (des.first != 0) {
        if (array[point.first][point.second] == '.') {
            array[point.first][point.second] = '|'
        } else if (array[point.first][point.second] == '-') {
            array[point.first][point.second] = '+'
        }
    } else if (des.second != 0) {
        if (array[point.first][point.second] == '.') {
            array[point.first][point.second] = '-'
        } else if (array[point.first][point.second] == '|') {
            array[point.first][point.second] = '+'
        }
    }
}
