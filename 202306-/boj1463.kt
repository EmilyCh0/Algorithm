import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Math.min

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val num = br.readLine().toInt()
    val arr = if (num <= 2) intArrayOf(0, 0, 1, 1).toMutableList() else MutableList(num + 1) { 0 }
    arr[0] = 0
    arr[1] = 0
    arr[2] = 1
    arr[3] = 1
    (3..num).forEach {
        arr[it] = arr[it - 1] + 1
        if (it % 6 == 0) {
            arr[it] = min(arr[it / 3] + 1, min(arr[it / 2] + 1, arr[it]))
            return@forEach
        }
        if (it % 3 == 0) {
            arr[it] = min(arr[it / 3] + 1, arr[it])
            return@forEach
        }
        if (it % 2 == 0) {
            arr[it] = min(arr[it / 2] + 1, arr[it])
            return@forEach
        }
    }
    println(arr[num])
}
