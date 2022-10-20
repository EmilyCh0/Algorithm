import java.util.*

fun main(){
    val stack = Stack<Int>()
    val n = readLine()!!.toInt()
    for(i in 0 until n){
        var opt = readLine()
        when(opt){
            "top" -> {
                if(stack.empty()) println(-1)
                else println(stack.peek())
            }
            "size" -> {
                println(stack.size)
            }
            "empty" -> {
                if(stack.empty()) println(1) else println(0)
            }
            "pop" -> {
                if(stack.empty()) println(-1)
                else {
                    println(stack.peek())
                    stack.pop()
                }
            }
            else -> {
                val (a,b) = opt!!.split(' ')
                stack.push(b.toInt())
            }
        }
    }
}