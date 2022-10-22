import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.math.abs

// plus, minus 두 개의 pq로 관리
/*
fun main(){
    val minusPQ = PriorityQueue<Int>(Collections.reverseOrder())
    val plusPQ = PriorityQueue<Int>()
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    repeat(n){
        val inp = br.readLine().toInt()
        if(inp==0){
            if(plusPQ.isEmpty()&&minusPQ.isEmpty()) println(0)
            else if(plusPQ.isEmpty()){
                println(minusPQ.poll())
            }else if(minusPQ.isEmpty()){
                println(plusPQ.poll())
            }else if(minusPQ.peek()*-1>plusPQ.peek()){
                println(plusPQ.poll())
            }else{
                println(minusPQ.poll())
            }
        }
        else if(inp>0) plusPQ.add(inp)
        else minusPQ.add(inp)
    }
}*/

// pq 정렬 조건 정하기
fun main(){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val n = br.readLine().toInt()
    val pq = PriorityQueue<Int> { o1, o2 ->
        if(abs(o1) == abs(o2)){ // 절댓값이 같으면 -1, 1
            Integer.compare(o1, o2) // 작은 거 -1
        }else{
            Integer.compare(abs(o1), abs(o2)) // 절딧값이 작은거
        }
    }
    repeat(n){
        val inp = br.readLine().toInt()
        if(inp==0){
            if(pq.isEmpty()) bw.write("0")
            else bw.write("${pq.poll()}")
            bw.newLine()
        }else{
            pq.add(inp)
        }
    }
    bw.flush()
    bw.close()
}
