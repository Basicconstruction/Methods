package www.Kotlin.basic

class FlipValues {
    fun flipValues(map1:Map<Int, Int>):MutableMap<Int,Int>{
        val u:MutableList<Int> = mutableListOf()
        val i:MutableList<Int> = mutableListOf()
        map1.forEach{
                a,b->
            u.add(a)
            i.add(b)
        }
        return i.zip(u).toMap().easyPrinter().toMap() as MutableMap
    }
}
fun <T,V> Map<T, V>.flipMap():MutableMap<V,T>{
    val u:MutableList<T> = mutableListOf()
    val i:MutableList<V> = mutableListOf()
    this.forEach{
            a,b->
        u.add(a)
        i.add(b)
    }
    return i.zip(u).toMap().easyPrinter().toMap() as MutableMap
}
fun main(args:Array<String>){
    FlipValues().flipValues(mapOf( 2 to 2, 3 to 4))
    mapOf(1 to "h", 2 to "l").flipMap()
}
