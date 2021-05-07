package com.tianyu.dd;
interface Ian{
    public static final int age = 10;
    public abstract void getInfo();
    public default void sayNo(){
        System.out.println("No");
    }
}
interface Ipg{
    public static final String number = "10010";
    public default void sayNo2(){
        System.out.println("No");
    }
}
class Jk implements Ian,Ipg{

    @Override
    public void getInfo() {
        System.out.println(age+"!!!?");
    }
}
public class A1{
    public static void main(String[] args){
        Ipg i1 = new Jk();
        i1.sayNo2();
//        Jk a = new Jk();
//        a.getInfo();
//        a.sayNo();
//        Ipg d = (Ipg)a;
//        d.sayNo2();
//        System.out.println(Ipg.number);
//        Ipg j = new Ipg();

    }
}
