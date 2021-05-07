package com.tianyu.dd;

public class Pointer<T> {
    public T x;
    public T y;

    public Pointer() {

    }

    public void setX(T _x) {
        this.x = _x;
    }

    public void setY(T _y) {
        this.y = _y;
    }

    public T getX() {
        return this.x;
    }
    public static void main(String[] args){
        System.out.println("Pointer"+"被调用了");
    }
    public static void sayNo(){
        System.out.println("No, No, No!");
    }

}
