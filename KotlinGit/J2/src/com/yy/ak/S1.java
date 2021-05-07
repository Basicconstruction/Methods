package com.yy.ak;
import com.tianyu.dd.Pointer;
import com.tianyu.dd.Pointer.*;
import com.tianyu.dd.Tester;
import com.tianyu.dd.Cat;

import static com.tianyu.dd.Pointer.sayNo;
enum Color{
    RED,
    GREEN,
    BLUE
}
public class S1 {
    public static void main(String[] args){
//        Pointer<Integer> f = new Pointer<>();
//        f.x = 18;
//        f.y = 10;
//        System.out.println(f.x+""+f.y);
//        sayNo();
//        sayNo();
//        Tester a = null;
//        a = Tester.getInstance();
//        a.sayNo();
//        Cat d = null;
//        d = Cat.getInstance();
        for(Color c :Color.values()){
            System.out.println(c+"  "+c.ordinal() + "  "+c.name());
        }

    }
}
