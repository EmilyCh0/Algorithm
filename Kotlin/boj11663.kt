import java.io.BufferedReader
import java.io.InputStreamReader

val br = BufferedReader(InputStreamReader(System.`in`))
lateinit var list: List<Int>

fun binarySearch(left: Int, right: Int, target: Int): Int {
    if(left>=right){
        return left
    }
    val mid = (left+right)/2
    return when{
        list[mid] == target -> mid
        list[mid] > target -> binarySearch(left, mid, target)
        else -> binarySearch(mid+1,right, target)
    }
}

fun main(){

    val (n,m) = br.readLine().split(' ').map { it.toInt() }
    list = br.readLine().split(' ').map { it.toInt() }.sorted()
    for(i in 0 until m){
        val (left, right) = br.readLine().split(' ').map { it.toInt() }
        val start = binarySearch(0,n,left)
        var end = binarySearch(0,n, right)
        if(end < n && right == list[end]) end ++
        println(end-start)
    }

}
