import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.LinkedList
import java.util.Queue
import java.util.StringTokenizer
import kotlin.math.abs

var arr = arrayOf(arrayOf(0))
var visit = arrayOf(arrayOf(false))
val que: Queue<Pair<Int, Int>> = LinkedList()
var n = 0
var min = 0
var max = 0
var dr = arrayOf(1, -1, 0, 0)
var dc = arrayOf(0, 0, 1, -1)
var ans = 0

fun bfs(r: Int, c: Int): Boolean { // (r, c)를 기준으로 연합인 나라를 찾아서 인구 이동까지 한다
    if (visit[r][c]) return false
    val group = LinkedList<Pair<Int, Int>>() // (r, c)를 시작으로 연합인 나라들
    var groupSum = 0
    while (!que.isEmpty()) {
        val now = que.poll()
        if (visit[now.first][now.second]) continue
        group.add(now)
        val nowNum = arr[now.first][now.second]
        visit[now.first][now.second] = true
        groupSum += arr[now.first][now.second]
        repeat(4) { i -> // 상하좌우 연합 찾기
            val nr = now.first + dr[i]
            val nc = now.second + dc[i]
            if (nr < 0 || nc < 0 || nr >= n || nc >= n || visit[nr][nc]) return@repeat
            val diff = abs(arr[nr][nc] - nowNum)
            if (diff > max || diff < min) return@repeat
            que.add(Pair(nr, nc))
        }
    }
    if (group.size == 1) return true // 이 그룹은 인구 이동 없다

    val avg = groupSum / group.size
    while (group.isEmpty().not()){
        val g = group.poll()
        arr[g.first][g.second] = avg
    }
    return false // 오늘 인구 이동이 있었다
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    var st = StringTokenizer(br.readLine())
    n = st.nextToken().toInt()
    arr = Array(n) { Array(n) { 0 } }
    visit = Array(n) { Array(n) { false } }
    min = st.nextToken().toInt()
    max = st.nextToken().toInt()

    repeat(n) { row ->
        st = StringTokenizer(br.readLine())
        repeat(n) { col ->
            arr[row][col] = st.nextToken().toInt()
        }
    }

    while (true) {
        var isAllFinish = true
        ans++
        repeat(n) { row ->
            repeat(n) { col ->
                if (!visit[row][col]) { // 방문한적이 없다면 (row, col)을 시작으로 연합을 찾는다
                    que.clear()
                    que.add(Pair(row, col))
                    val isFinish = bfs(row, col)
                    if (isFinish.not()) isAllFinish = false
                }
            }
        }
        visit = Array(n) { Array(n) { false } } // 오늘 인구 이동 끝! 방문 여부 초기화
        if (isAllFinish) break // 오늘 인구 이동이 하나도 없었으면 끝내기
    }
    println(ans - 1)
}
