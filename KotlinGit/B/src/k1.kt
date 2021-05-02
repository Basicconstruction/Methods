class k1 {
}
fun main(args:Array<String>){
    var k2 = generateSequence(0){
        it + 1
    }.filter{
        it % 2 == 0 && it % 3 == 0 && (it+1) % 17 == 1
    }.take(100).toList().easyPrint()
}