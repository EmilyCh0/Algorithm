import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

fun main(){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val sb = StringBuilder()
    val (a,b) = br.readLine().split(' ')
    val map = mutableMapOf<String, Int>()
    val arr = arrayListOf<String>()
    for(i in 0 until a.toInt()){
        val pok = br.readLine()
        map[pok] = i+1
        arr.add(pok)
    }
    for(i in 0 until b.toInt()){
        val inp = br.readLine()
        if(inp.toIntOrNull()!=null){ // 숫자
            sb.append(arr[inp.toInt()-1]).append('\n')
        }else{
            sb.append(map[inp]).append('\n')
        }
    }
    println(sb)
}