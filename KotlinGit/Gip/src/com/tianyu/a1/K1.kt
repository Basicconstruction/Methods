package com.tianyu.a1
import java.awt.FlowLayout
import java.awt.event.ActionEvent
import java.awt.event.ActionListener
import javax.swing.*;
class K1(): JFrame() {
    public fun run(jframe:JFrame, width:Int=800, height:Int=300, _title:String = "OMG,yes!"){
        this.title = _title
        this.defaultCloseOperation = JFrame.EXIT_ON_CLOSE
        this.isVisible = true
//        this.setSize(width,height)
        this.setBounds(800,400,width,height)
    }
}
fun main(args:Array<String>){
    val j = K1()
    val jb = JButton("Button")
    val j2 = JButton("Button2")
    j.layout = FlowLayout()
    val txt = JTextField(10)
//    val bl = ActionListener(){
//        fun actionPerformed(e: ActionEvent):Unit{
//            val name:String = (1..100).shuffled().first().toString()
//            jb.text = name
//        }
//    }
//    jb.addActionListener (bl)
//    j2.addActionListener (bl)
    j.add(jb)
    j.add(j2)
    j.add(txt)
    j.run(j)

}

private fun JButton.addActionListener(s: String) {
    println(s)
}
