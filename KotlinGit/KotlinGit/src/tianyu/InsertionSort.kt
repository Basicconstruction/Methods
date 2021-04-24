package tianyu

//点击顶部工具栏中的【Code】选项；3、在弹出的选项列表中，点击【Reformat Code】
object InsertionSort {
    public fun reverseList(list:MutableList<Int>):MutableList<Int>{
        var trans:Int
        for(i in (0 until ( (list.size - 1) / 2).toInt())){
            trans = list[i]
            list[i] = list[list.size - 1 - i]
            list[list.size - 1 - i ] = trans
        }
        return list
    }
    fun insertionSort(list: MutableList<Int>, ascending:Boolean = true): MutableList<Int> {
        //5,2,4,6,1,3,9,7,8,11,10
        var key: Int
        var j: Int
        for (i in (1 until list.size)) {
            key = list[i]
            j = i - 1
            while (j >= 0 && list[j] > key) {
                list[j + 1] = list[j]
                j--
            }
            list[j + 1] = key
        }
        return if(ascending){
            list.toMutableList()
        }else{
            reverseList(list).toMutableList()
        }
    }
}

fun main(args: Array<String>) {
    val list: MutableList<Int> = mutableListOf(5, 2, 4, 6, 1, 3, 9, 7, 8, 11, 10)
    val list2 = InsertionSort.insertionSort(list,false)
    println(list2)

}