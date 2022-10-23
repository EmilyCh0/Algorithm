import java.io.BufferedReader
import java.io.InputStreamReader

val br = BufferedReader(InputStreamReader(System.`in`))
val arr = arrayListOf<Pair<Int, String>>()
fun biSearch(left: Int, right: Int, target: Int): Int{

    if(left>=right) return left
    val mid = (left+right)/2
    //return if(arr[mid].first==target) mid
    return if(arr[mid].first<target) biSearch(mid+1, right, target)
    else biSearch(left, mid, target)

}

fun main(){
    val sb = StringBuilder()

    val (n,m) = br.readLine().split(' ').map { it.toInt() }

    for(i in 0 until n){
        val (title, strength) = br.readLine().split(' ')
        arr.add(Pair(strength.toInt(), title))
    }
    repeat(m){
        val t = br.readLine().toInt()
        val idx = biSearch(0,n,t)
        sb.append(arr[idx].second).append('\n')
    }
    print(sb)
}