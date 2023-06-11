import java.io.BufferedReader
import java.io.InputStreamReader

var arr = mutableListOf<List<Int>>()
val ans = StringBuilder()
var n = 0

fun divConq(row: Int, col: Int, size: Int) {

    var zeroCount = 0
    for (i in row until row + size) {
        for (j in col until col + size) {
            if (arr[i][j] == 0) zeroCount++
        }
    }
    if (zeroCount == size * size) {
        ans.append(0)
        return
    } else if (zeroCount == 0) {
        ans.append(1)
        return
    }
    ans.append('(')
    divConq(row, col, size / 2)
    divConq(row, col + size / 2, size / 2)
    divConq(row + size / 2, col, size / 2)
    divConq(row + size / 2, col + size / 2, size / 2)
    ans.append(')')
    return
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    n = br.readLine().toInt()

    repeat(n) {
        val tmp = mutableListOf<Int>()
        br.readLine().forEach {
            tmp.add(Character.getNumericValue(it))
        }
        arr.add(tmp)
    }
    divConq(0, 0, n)
    println(ans.toString())
}
