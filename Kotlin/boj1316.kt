import java.io.BufferedReader
import java.io.InputStreamReader

val alphabetSet = mutableSetOf<Char>()
fun isGroupWord(word: String): Boolean{
    var flag = true
    for(i in word.indices){
        if(alphabetSet.contains(word[i])){
            if(i!=0&&word[i-1]==word[i]) continue
            else{
                flag = false
                break
            }
        }else alphabetSet.add(word[i])
    }
    return flag
}

fun main(){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    var cnt = 0

    repeat(n){
        alphabetSet.clear()
        val word = br.readLine()
        if(isGroupWord(word)) cnt++
    }
    println(cnt)
}