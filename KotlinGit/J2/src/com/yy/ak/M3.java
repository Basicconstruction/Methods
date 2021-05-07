package com.yy.ak;

import java.util.Locale;
import java.util.function.*;

public class M3 {

    public static void main(String[] args){
        Function<Integer, Integer> fg = s->{
            return ++s;
        };//apply  accept  get  test
        System.out.println(fg.apply(10));
        Consumer<Integer> s1 = s->{
            s = s * 100;
            System.out.println(s);
        };
        s1.accept(100);
        Supplier<String> h = "evywuew"::toUpperCase;
        System.out.println(h.get());
        Supplier<Integer> l = ()->{
            return 3;
        };
        System.out.println(l.get());
        Predicate<String> k = "eeijcji"::equals;
        System.out.println(k.test("eh"));
        Predicate<Integer> jk = (s)->{
            if(s>100){
                return true;
            }else{
                return false;
            }
        };
        System.out.println(jk.test(100));
        System.out.println(jk.test(1000));



    }
}
