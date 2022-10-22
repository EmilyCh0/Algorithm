import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.LinkedList
import java.util.StringTokenizer

fun main(){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val sb = StringBuilder()
    val n = br.readLine().toInt()
    val arr = Array(n+2){ arrayListOf<Int>() }
    val ans = Array(n+2){0}
    ans[1] = 1
    repeat(n-1){
        val st = StringTokenizer(br.readLine())
        val a = st.nextToken().toInt()
        val b = st.nextToken().toInt()
        arr[a].add(b)
        arr[b].add(a)
    }
    val que = LinkedList<Int>()
    que.add(1)
    while(!que.isEmpty()){
        val now = que.poll()
        for(i in arr[now]){
            if(ans[i]==0){
                ans[i] = now
                que.add(i)
            }
        }
    }
    for(i in 2 until n+1){
        sb.append(ans[i]).append('\n')
    }

    println(sb)
}