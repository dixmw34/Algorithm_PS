import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val num = nextLine().toInt()

    var result = 0

    repeat(num) {
        val st = nextLine()

        val stringBuilder = StringBuilder()
        var isGroup = true
        st.forEach { ch ->
            if (stringBuilder.isEmpty() || stringBuilder.last() != ch) {
                if (stringBuilder.contains(ch, ignoreCase = false)) {
                    isGroup = false
                    return@forEach
                }
                stringBuilder.append(ch)
            }
        }
        if (isGroup) result ++
    }

    println(result)
}
