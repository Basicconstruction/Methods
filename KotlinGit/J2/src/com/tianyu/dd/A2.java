package com.tianyu.dd;

public class A2 {
    public static void main(String [] args){
        Integer[] a = new Integer[]{1,2,3,4,5};
        reverseArray(a);
        for(Integer b:a){
            System.out.println(b);
        }
        String[] g = new String[]{"a","b","c","d","e"};
        reverseArray(g);
        for(String s:g){
            System.out.println(s);
        }


    }
    public static <T> T[] reverseArray(T[] arr){
        T temp;
        for(int i = 0;i < (arr.length-1)/2;i++){
            temp = arr[i];
            arr[i] = arr[arr.length - 1 - i];
            arr[arr.length - 1 - i] = temp;
        }
        return arr;
    }
}
