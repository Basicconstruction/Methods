package com.yy.ak;
interface Hk{
    public void send(String mes);
}
interface IMes{
    public void send(String str);
    public static IMes getInstance(){
        return new IMes(){

            @Override
            public void send(String str) {
                System.out.println(str);
            }
        };
    }
}
interface IMath{
    public int add(int x,int y);
}
interface MyStr<R,Q>{
    public Q say(R s);
}
interface MyUI{
    public int Ul(String a);
}
public class M2 {

    public static void main(String[] args){
        MyStr<String, String> df = String::toUpperCase;
        System.out.println(df.say("hello"));
        MyUI jk = (a)->{
            System.out.println(a);
            return a.length();
        };
        jk.Ul("becwwecuew");
//        Hk h1 = new Hk(){
//            public void send(String mes){
//                System.out.println(mes);
//            }
//        };
//        Hk h1 = System.out::println;
////        Hk h1 = mes -> System.out.println(mes);
//        h1.send("helloo");
//        IMes d = IMes.getInstance();
//        d.send("hello world!!!hey");
//        IMath f = Integer::sum;
//        IMath d = (x,y)->{
//            System.out.println(x+y);
//            return x+y;
//        };
//        System.out.println(f.add(1,100));
//        d.add(1,200);
    }
}
