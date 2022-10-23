import java.io.BufferedReader
import java.io.InputStreamReader

fun main(){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val s = br.readLine().toLong()
    var sum: Long = 0L
    var i: Long = 1L
    while(sum<=s){
        sum+=i++
    }
    println(i-2)
}