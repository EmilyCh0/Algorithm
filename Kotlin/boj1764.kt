import java.io.BufferedReader
import java.io.InputStreamReader

fun main(){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (n,m) = br.readLine().split(' ').map { it.toInt() }
    val nameSet = mutableSetOf<String>()
    repeat(n){
        nameSet.add(br.readLine())
    }
    val ans = arrayListOf<String>()
    repeat(m){
        val name = br.readLine()
        if(nameSet.contains(name)) ans.add(name)
    }
    ans.sort()
    val sb = StringBuilder()
    sb.append(ans.size).append('\n')
    for (i in ans){
        sb.append(i).append('\n')
    }
    println(sb)
}