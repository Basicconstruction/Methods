package com.yy.ak;

public class M1 {
    public static int divide(int a,int b) throws Exception{
        int g = 0;
        try{
            g = a / b;
        }finally{
            System.out.println();
        }
        return g;
    }
    public static void main(String [] args) throws Exception{
//        try{
//            System.out.println(2/0);
//        }catch(Exception e){
//            e.printStackTrace();
//        }finally{
//            System.out.println("End!");
//            System.exit(1);
//        }
//
        try{
            divide(2,0);
        }catch(Exception e){
            e.printStackTrace();
        }finally{
            System.out.println("hello world");
        }
        System.out.println("what's your matter?");

    }

}
