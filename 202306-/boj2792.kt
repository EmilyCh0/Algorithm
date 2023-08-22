import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = br.readLine().split(' ').map { it.toInt() }
    val arr = mutableListOf<Int>()

    repeat(m) {
        arr.add(br.readLine().toInt())
    }

    var left = 1
    var right = arr.max()
    var ans = 0

    while (left <= right) {
        val mid = (left + right) / 2
        var cnt = 0
        arr.forEach {
            cnt += it / mid
            if (it % mid != 0) cnt++
        }
        if (cnt > n) {
            left = mid + 1
        } else {
            right = mid - 1
            ans = mid
        }
    }
    println(ans)
}
