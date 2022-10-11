import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    var num = nextInt()

    var now = 666L

    while(true) {
        if (now.toString().contains("666")) {
            if (-- num == 0) {
                println(now)
                return@with
            }
        }
        now ++
    }
}
