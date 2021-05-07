package com.yy.ak;
import java.util.*;
public class M5 {
    public static void main(String[] args){
        Collection<Integer> a = new ArrayList<Integer>(Arrays.asList(1,2,3));
        Integer[] b = {7,6,4,3,2};
        a.addAll(Arrays.asList(b));
        Collections.addAll(a,5,34,2);
        Collections.addAll(a,b);
        List<Integer> list = Arrays.asList(1,2,3,4,5,6);
//        list.add(2);
        list.set(2,10);
        System.out.println(list.get(2));
        HashSet<Integer> bn = new HashSet<Integer>();
        bn.add(1);
        bn.add(3);
        bn.add(9);
        for(Integer g:bn){
            System.out.println(g);
        }

    }
}
