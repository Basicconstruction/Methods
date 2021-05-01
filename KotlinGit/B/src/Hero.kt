import kotlin.properties.Delegates
fun <T> T.easyPrint():T{
    println(this)
    return this
}
fun add(a:Int, b:Int):Int{
    return a+b
}

class SpellBook{
    @JvmField
    val spells = listOf("Magic Ms. L", "Lay on Hans")
}

@JvmOverloads
fun handOverFood(leftHand:String = "berriers", rightHand:String = "beef"){
    println("Mmmm, you hand some decilious food $leftHand and $rightHand")
}
fun main(args:Array<String>){
//    val J1:Jhave = Jhave()
//    println(J1.utterGreeting())
//    println(J1.determineFriendshipLevel()?.toUpperCase() ?: "Null, I don't know what is friendship!")
//    println(J1.javaClass)
//    J1.hitPoints = 1000
//    println(J1.hitPoints)
//    println(J1.a)
    add(2,3).easyPrint()
//    3.let{
//        "hello"
//    }.easyPrint()
//    2.also{
//        Jhave()
//    }.easyPrint()
//    2.run{
//        "hello world"
//        Jhave()
//    }.easyPrint()
//    with(3){
//        this + 1
//    }.easyPrint()
}