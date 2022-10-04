import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    var num = nextLine().toInt()

    var result = 0

    while(num != 0) {
        result += num % 2
        num  = num shr 1
    }

    println(result)

}
