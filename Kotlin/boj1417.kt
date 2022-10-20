import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main(){
    val pq = PriorityQueue<Int>(Collections.reverseOrder())
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    var dasom = br.readLine().toInt()
    repeat(n-1){
        val tmp = br.readLine().toInt()
        pq.add(tmp)
    }
    if(n==1){
        println(0)
        return
    }
    var cnt = 0
    while (true){
        if(dasom>pq.peek()) break;
        var tmp = pq.poll()
        cnt++
        dasom++
        pq.add(tmp-1)
    }
    println(cnt)
}