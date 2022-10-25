import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.PriorityQueue

var n = 0
lateinit var graph: Array<ArrayList<Int>>
lateinit var cost: Array<IntArray>
var flag = false

fun findCost(src: Int, dst: Int): Int{
    val pq = PriorityQueue<Pair<Int,Int>>{ o1, o2 ->
        Integer.compare(o1.first, o2.first)
    }
    val dist = Array(n){ Integer.MAX_VALUE }
    dist[src] = 0
    pq.add(0 to src)
    while(!pq.isEmpty()){
        val curDist = pq.peek().first
        val cur = pq.poll().second
        for(nxt in graph[cur]){
            if(dist[nxt] > curDist+cost[cur][nxt]){
                dist[nxt] = curDist+cost[cur][nxt]
                pq.add(dist[nxt] to nxt)
            }
        }
    }
    if(dist[dst]==Integer.MAX_VALUE) flag = true
    return dist[dst]
}

fun main(){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (tmpn,e) = br.readLine().split(' ').map { it.toInt() }
    n = tmpn

    graph = Array(n){ arrayListOf<Int>() }
    cost = Array(n){IntArray(n){0} }
    repeat(e){
        val (a,b,w) = br.readLine().split(' ').map { it.toInt() }
        cost[a-1][b-1] = w
        cost[b-1][a-1] = w
        graph[a-1].add(b-1)
        graph[b-1].add(a-1)
    }
    val (pt1, pt2) = br.readLine().split(' ').map { it.toInt() }.map { it.minus(1) }
    var sum = 0
    sum += findCost(0,pt1)
    sum += findCost(pt1,pt2)
    sum += findCost(pt2, n-1)
    var sum2 = 0
    sum2 += findCost(0,pt2)
    sum2 += findCost(pt2,pt1)
    sum2 += findCost(pt1,n-1)

    if(flag) println(-1)
    else println(Integer.min(sum,sum2))

}

