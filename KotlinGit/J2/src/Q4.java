public class Q4 {
    public static void main(String[] args){
        String str = new String(new char[]{'a','b','c'}, 1,2);
        String s2 = new String(new int[]{100,102,103,104},1,3);
        String s3 = new String(new int[]{1,2,3},0,2);
        String s4 = new String(new char[]{'s','d','f'});

//        System.out.println(str);
//        System.out.println(s2);
//        System.out.println(s3);
//        System.out.println(s4);
//        System.out.println(s4.length());
//        System.out.println("sdf".equalsIgnoreCase(s4));
//        System.out.println(s4.hashCode());
//        String s5 = "sdf";
//        System.out.println(s5.hashCode());
        String a = new String("abc").intern();
        String b = new String("abc").intern();
        String c = "abc";
        System.out.println(a == b);
        System.out.println(b == c);
 //        System.out.println(str);
    }
}
