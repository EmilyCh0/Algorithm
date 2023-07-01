import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.LinkedList
import java.util.Queue
import java.util.StringTokenizer

var n = -1
var m = -1
var t = -1
val arr = mutableListOf<MutableList<Int>>()
val dr = intArrayOf(0, 0, 1, -1)
val dc = intArrayOf(1, -1, 0, 0)
val que: Queue<Triple<Int, Int, Int>> = LinkedList()
var ans = -1
var ans2 = -1

fun bfs() {
    while (!que.isEmpty()) {
        val (curR, curC, curD) = que.poll()
        if (arr[curR][curC] == 1) continue

        if (curD > t) {
            ans = -1
            break
        }
        if (curR == n - 1 && curC == m - 1) {
            ans = curD
            break
        }
        if (arr[curR][curC] == 2) {
            ans2 = curD + (n - curR - 1) + (m - curC - 1)
        }
        arr[curR][curC] = 1

        repeat(4) { idx ->
            val nr = curR + dr[idx]
            val nc = curC + dc[idx]
            if (nr < 0 || nc < 0 || nr >= n || nc >= m || arr[nr][nc] == 1) return@repeat
            que.add(Triple(nr, nc, curD + 1))
        }
    }
    return
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine())
    n = st.nextToken().toInt()
    m = st.nextToken().toInt()
    t = st.nextToken().toInt()
    repeat(n) {
        arr.add(br.readLine().split(' ').map { it.toInt() }.toMutableList())
    }
    que.add(Triple(0, 0, 0))
    bfs()
    if ((ans2 != -1 && ans2 < ans) || ans == -1) ans = ans2
    if (ans == -1 || ans > t) println("Fail")
    else println(ans)
}
