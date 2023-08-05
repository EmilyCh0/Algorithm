import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.LinkedList

lateinit var nums: List<Int>
var que: LinkedList<Pair<Int, Int>> = LinkedList()
var nextQue: LinkedList<Pair<Int, Int>> = LinkedList()


fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    val sb = StringBuilder()

    nums = br.readLine().split(' ').map { it.toInt() }

    que.add(0 to nums.size)
    repeat(n) {
        val ans = mutableListOf<Int>()
        while (!que.isEmpty()) {
            val now = que.poll()
            val start = now.first
            val end = now.second
            val mid = (start + end) / 2

            ans.add(nums[mid])
            if (start == mid) continue

            nextQue.add(start to mid)
            nextQue.add(mid + 1 to end)
        }
        que.addAll(nextQue)
        nextQue.clear()
        sb.append(ans.joinToString(separator = " "))
        sb.append('\n')
    }
    println(sb.toString())
}
