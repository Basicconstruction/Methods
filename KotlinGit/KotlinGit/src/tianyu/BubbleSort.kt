package tianyu

class BubbleSort {
    /*
    README.txt
    这是几个冒泡排序的KOtlin的不同实现。并提供了测试用例。
    */
    public fun reverseList(list:MutableList<Int>):MutableList<Int>{
        var trans:Int
        for(i in (0 until ( (list.size - 1) / 2).toInt())){
            trans = list[i]
            list[i] = list[list.size - 1 - i]
            list[list.size - 1 - i ] = trans
        }
        return list
    }
    public fun bubbleSortL1(list:MutableList<Int>, ascending:Boolean = true):MutableList<Int>{
        var trans:Int
        val aSize = list.size
        (0 until aSize-1).forEach{//0 1 2
                index->
            (0 until aSize - index - 1).forEach{//0-2 0-1 0
                    index2->
                if(list[index2] > list[index2+1]){
                    trans = list[index2]
                    list[index2] = list[index2+1]
                    list[index2 + 1] = trans
                }
            }
        }
        return if(ascending){
            list.toMutableList()
        }else{
            reverseList(list).toMutableList()
        }

    }
    public fun bubbleSortL2(list:MutableList<Int>, ascending:Boolean = true):MutableList<Int>{
        var trans:Int = 0
        val aSize = list.size
        (0 until aSize-1).forEach{//0 1 2
            (0 until aSize - it - 1).forEach{//0-2 0-1 0
                if(list[it] > list[it+1]){
                    trans = list[it]
                    list[it] = list[it+1]
                    list[it + 1] = trans
                }
            }
        }
        return if(ascending){
            list.toMutableList()
        }else{
            reverseList(list).toMutableList()
        }
    }
    public fun bubbleSortL3(list:MutableList<Int>, ascending:Boolean = true):MutableList<Int>{
        var trans:Int = 0
        val aSize = list.size
        for(i in (0 until aSize - 1)){
            for(j in (0 until aSize - i - 1)){
                if(list[j] > list[j+1]){
                    trans = list[j]
                    list[j] = list[j+1]
                    list[j + 1] = trans
                }
            }
        }
        return if(ascending){
            list.toMutableList()
        }else{
            reverseList(list).toMutableList()
        }
    }
    public fun bubbleSortL4(list:MutableList<Int>, ascending:Boolean = true):MutableList<Int>{
        var trans:Int = 0
        val aSize = list.size
        for(i in (0..aSize - 2)){
            for(j in (0..aSize - i - 2)){
                if(list[j] > list[j+1]){
                    trans = list[j]
                    list[j] = list[j+1]
                    list[j + 1] = trans
                }
            }
        }
        return if(ascending){
            list.toMutableList()
        }else{
            reverseList(list).toMutableList()
        }
    }
}
fun main(args:Array<String>){
    val l1:MutableList<Int> = mutableListOf(1,2,3,28,2,19,10)
    BubbleSort().bubbleSortL1(l1, false)
    println("$l1")
    val c2 = BubbleSort().bubbleSortL2(l1).toMutableList()
    c2[0] = 100
    val c3 = BubbleSort().bubbleSortL3(l1)
    val c4 = BubbleSort().bubbleSortL4(l1, false)
    println("$c2\n$c3\n$c4")
}