import java.util.LinkedList

fun main(){
    val que = LinkedList<Int>()
    val n = readLine()!!.toInt()
    for(i in 0 until n){
        var opt = readLine()
        when(opt){
            "pop" -> {
                if(que.isEmpty()) println(-1)
                else {
                    println(que.peek())
                    que.pollFirst()
                }
            }
            "size" -> {
                println(que.size)
            }
            "empty" -> {
                if(que.isEmpty()) println(1)
                else println(0)
            }
            "front" -> {
                if (que.isEmpty()) println(-1)
                else println(que.peek())
            }
            "back" -> {
                if (que.isEmpty()) println(-1)
                else println(que.peekLast())
            }
            else -> {
                val (a,b) = opt!!.split(' ')
                que.offer(b.toInt())
            }
        }
    }

}