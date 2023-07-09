import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (n, k) = br.readLine().split(' ').map { it.toInt() }
    val coins = Array(n) { 0 }
    repeat(n) {
        coins[it] = br.readLine().toInt()
    }
    val dp = Array(k + 1) { 0 }
    dp[0] = 1
    (0 until n).forEach { coinIdx ->
        val coin = coins[coinIdx]
        (coin..k).forEach { dpIdx ->
            dp[dpIdx] += dp[dpIdx - coin]
        }
    }
    println(dp[k])
}
