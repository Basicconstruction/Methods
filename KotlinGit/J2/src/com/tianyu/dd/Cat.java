package com.tianyu.dd;

public class Cat {
    private static Cat c;
    private Cat(){

    }
    public static Cat getInstance(){
        if(c == null){
            c = new Cat();
        }
        return c;
    }
    public String toString(){

        return "hello world";
    }
}
