package com.Kotlin.tianyu
// by tianyu 2021/4/24
//插入排序--Kotlin插入排序及测试代码
object InsertionSort {
    fun insertionSort(list:MutableList<Int>):MutableList<Int>{
        //5,2,4,6,1,3,9,7,8,11,10
        var key:Int
        var j:Int
        for(i in (1 until list.size)){
            key = list[i]
            j = i - 1
            while(j >=0  && list[j] > key){
                list[j+1] = list[j]
                j --
            }
            list[j+1] = key
        }
        return list
    }
}
fun main(args:Array<String>){
    val list:MutableList<Int> = mutableListOf(5,2,4,6,1,3,9,7,8,11,10)
    val list2 = InsertionSort.insertionSort(list)
    println(list2)

}