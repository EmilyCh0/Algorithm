import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.LinkedList

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()

    val arr = List(n + 1) { mutableListOf<Int>() }
    repeat(n - 1) {
        val (a, b) = br.readLine().split(' ').map { it.toInt() }
        arr[a].add(b)
        arr[b].add(a)
    }

    val ans = MutableList(n + 1) { -1 }
    val que = LinkedList<Int>()
    que.add(1)

    while (que.isNotEmpty()) {
        val parent = que.poll()
        for (child in arr[parent]) {
            if (ans[child] == -1) {
                ans[child] = parent
                que.add(child)
            }
        }
    }

    val sb = StringBuilder()
    (2..n).forEach { sb.append("${ans[it]}\n") }
    print(sb.toString())
}
