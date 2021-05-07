fun <T> T.myPrint():T{
    println(this)
    return this
}
fun main(args: Array<String>){
    (1..3).myPrint().sum().myPrint()
//    var c = when(2){
//        1->"hello world"
//        2->"I love you!"
//        else->"No matter!"
//    }
//    println(c)
//    Q1.easyPrintln(2);
}