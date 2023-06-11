import java.io.BufferedReader
import java.io.InputStreamReader

val arr: MutableList<List<Int>> = mutableListOf()

var blue = 0
var white = 0

fun divConq(row: Int, col: Int, size: Int) {
    var blueCount = 0
    for (i in row until row + size) {
        for (j in col until col + size) {
            if (arr[i][j] == 1) blueCount++
        }
    }
    if (blueCount == size * size) {
        blue++
        return
    } else if (blueCount == 0) {
        white++
        return
    }
    divConq(row, col, size / 2)
    divConq(row, col + size / 2, size / 2)
    divConq(row + size / 2, col, size / 2)
    divConq(row + size / 2, col + size / 2, size / 2)
    return
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    repeat(n) {
        val tmp = br.readLine().split(' ').map { it.toInt() }
        arr.add(tmp)
    }
    divConq(0, 0, n)
    println(white)
    println(blue)
}
