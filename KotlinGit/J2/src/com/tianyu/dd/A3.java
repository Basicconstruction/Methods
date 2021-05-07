package com.tianyu.dd;

class Point{
    private Object x;
    private Object y;
    public void setX(Object x){
        this.x = x;
    }
    public void setY(Object y){
        this.y = y;
    }
    public Object getX(){
        return this.x;
    }
    public Object getY(){
        return this.y;
    }
}

public class A3 {
    public static void saysomething(Pointer<?> temp){
        System.out.println(temp);
    }
    public static <T> void sayT(T a){
        System.out.println(a);
    }
    public static void main(String [] args){
        Pointer<Integer> p2 = new Pointer<>();
        p2.x = 2;
        p2.y = 3;
        saysomething(p2);
        sayT("somethings");
//        System.out.println(p2.x);
//        System.out.println(p2.y);
//        p2.setX(1000);
//        System.out.println(p2.x);

//        Point p1 = new Point();
//        p1.setX(10);
////        p1.setY(10);
//        p1.setY("hello");
//        System.out.println((Integer)p1.getX());
////        System.out.println((Integer)p1.getY());
//        System.out.println((String)p1.getY());

    }
}
