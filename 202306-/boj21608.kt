//import java.io.BufferedReader
//import java.io.InputStreamReader
//
//var n = -1
//lateinit var arr: List<MutableList<Int>>
//val dr = intArrayOf(0, 0, 1, -1)
//val dc = intArrayOf(1, -1, 0, 0)
//
//fun firstCondition(num: Int, likes: List<Int>) {
//    val likeCntArr = List(n) { MutableList(n) { 0 } }
//    (0 until n).forEach { row ->
//        (0 until n).forEach { col ->
//            var likeCnt = 0
//            (0..3).forEach { idx ->
//                val nr = row + dr[idx]
//                val nc = col + dc[idx]
//                if (nr < 0 || nc < 0 || nr >= n || nc >= n) return@forEach
//                if (likes.contains(arr[nr][nc])) likeCnt++
//            }
//            likeCntArr[row][col] = likeCnt
//        }
//    }
//
//    var max = 0
//    val maxPositions = mutableListOf<Pair<Int, Int>>()
//    (0 until n).forEach { row ->
//        (0 until n).forEach { col ->
//            if (likeCntArr[row][col] > max && arr[row][col] == 0) {
//                max = likeCntArr[row][col]
//                maxPositions.clear()
//            }
//            if (likeCntArr[row][col] == max && arr[row][col] == 0) {
//                maxPositions.add(row to col)
//            }
//        }
//    }
//    if (maxPositions.size == 1) {
//        arr[maxPositions[0].first][maxPositions[0].second] = num
//        return
//    }
//    secondCondition(num, maxPositions)
//}
//
//fun secondCondition(num: Int, positions: List<Pair<Int, Int>>) {
//    var max = 0
//    val maxPositions = mutableListOf<Pair<Int, Int>>()
//    positions.forEach { pos ->
//        var vacantCnt = 0
//        (0..3).forEach { idx ->
//            val nr = pos.first + dr[idx]
//            val nc = pos.second + dc[idx]
//            if (nr < 0 || nc < 0 || nr >= n || nc >= n) return@forEach
//            if (arr[nr][nc] == 0) vacantCnt++
//        }
//        if (vacantCnt > max && arr[pos.first][pos.second] == 0) {
//            max = vacantCnt
//            maxPositions.clear()
//        }
//        if (vacantCnt == max && arr[pos.first][pos.second] == 0) {
//            maxPositions.add(pos)
//        }
//    }
//    arr[maxPositions[0].first][maxPositions[0].second] = num
//}
//
//fun main() {
//    val br = BufferedReader(InputStreamReader(System.`in`))
//    n = br.readLine().toInt()
//    arr = List(n) { MutableList(n) { 0 } }
//    val likeMap: MutableMap<Int, List<Int>> = mutableMapOf()
//    repeat(n * n) {
//        val input = br.readLine().split(' ').map { it.toInt() }
//        firstCondition(input[0], input.subList(1, 5))
//        likeMap[input[0]] = input.subList(1, 5)
//    }
//    var ans = 0
//    (0 until n).forEach { row ->
//        (0 until n).forEach { col ->
//            var likeCnt = 0
//            (0..3).forEach { idx ->
//                val nr = row + dr[idx]
//                val nc = col + dc[idx]
//                if (nr < 0 || nc < 0 || nr >= n || nc >= n) return@forEach
//                if (likeMap[arr[row][col]]?.contains(arr[nr][nc]) == true) likeCnt++
//            }
//            when (likeCnt) {
//                1 -> ans += 1
//                2 -> ans += 10
//                3 -> ans += 100
//                4 -> ans += 1000
//            }
//        }
//    }
//    println(ans)
//}
