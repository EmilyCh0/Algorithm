import java.util.*
import java.io.*

fun main(){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    val dq = LinkedList<Int>()
    val sb = StringBuilder()
    repeat(n){
        val opt = StringTokenizer(br.readLine())
        when(opt.nextToken()){
            "push" -> dq.offer(opt.nextToken().toInt())
            "pop" -> sb.append(if(dq.isEmpty()) -1 else dq.poll()).append('\n')
            "size" -> sb.append(dq.size).append('\n')
            "empty" -> sb.append(if(dq.isEmpty()) 1 else 0).append('\n')
            "front" -> sb.append(if(dq.isEmpty()) -1 else dq.peekFirst()).append('\n')
            "back" -> sb.append(if(dq.isEmpty()) -1 else dq.peekLast()).append('\n')
        }
    }
    println(sb)
}