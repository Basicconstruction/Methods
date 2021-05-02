import java.io.IOException
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
    companion object{
        @JvmField
        val npy:Int = 1
        @JvmStatic
        fun printer():Unit{
            "hello, my son".easyPrint()
        }
    }
}

@JvmOverloads
fun handOverFood(leftHand:String = "berriers", rightHand:String = "beef"){
    println("Mmmm, you hand some decilious food $leftHand and $rightHand")
}

@Throws(IOException::class)
fun acceptApology(){
    throw IOException()
}

val translator = {
    utterance:String->
    println(utterance.toLowerCase().capitalize())
}

val translator2 = {
        utterance:String->
    println(utterance.toLowerCase().capitalize())
}

val description:(String)->String = {
    name:String->
    println("My name is $name")
    "My name is $name"
}
//fun descriptionT2(name:String):Unit{
//    println("My name is $name")
//    return "My name is $name"
//}
fun main(args:Array<String>){
    val J1:Jhave = Jhave()
    try{
        J1.extendHandInFriendship()
    }catch(e:Exception){
        println(e).apply{
            println("这是一个异常处理")
        }
    }
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