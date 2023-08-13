import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (n, k, m) = br.readLine().split(' ').map { it.toInt() }
    val arr = mutableListOf<Int>()
    repeat(n) {
        arr.add(br.readLine().toInt())
    }
    arr.forEachIndexed { index, i ->
        if (i >= 2 * k) arr[index] = i - 2 * k
        else if (i >= k) arr[index] = i - k
        else arr[index] = 0
    }
    val arr2 = arr.filterNot { it == 0 }
    var left = 1
    var right = arr2.maxOrNull() ?: 0
    var ans = 0

    while (left <= right) {
        val mid = (left + right) / 2
        val cnt = arr2.sumOf { it / mid }
        if (cnt >= m) {
            ans = mid
            left = mid + 1
        } else {
            right = mid - 1
        }
    }
    if (ans == 0) println(-1)
    else println(ans)
}
