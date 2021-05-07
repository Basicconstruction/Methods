package com.tianyu.dd;

public class Tester {
    private static final Tester instance = new Tester();
    private Tester(){

    }
    public static Tester getInstance(){
        return instance;
    }
    public void sayNo(){
        if(instance == null){
            System.out.println("No, I am ok~");
        }else{
            System.out.println("No, No");
        }
    }
}
