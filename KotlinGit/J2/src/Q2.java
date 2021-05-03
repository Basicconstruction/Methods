class ArrayTester{
    public int a;
    public static void mainFunction(){
        int[] b = new int[]{1,2,3,1,2,7,1,2,0};
        java.util.Arrays.sort(b);
        for(int k:b){
            System.out.println(k);
        }
    }
    public static void sum(String a,int... data){
        System.out.println(a);
        int h = 0;
        for(int u:data){
            h += u;
        }
        System.out.println(h);
    }
    public static void sum(int... data){
        int j = 0;
        for(int y: data){
            j += y;
        }
        System.out.println(j);
    }
}
public class Q2 {
    public static void main(String[] args){
//        ArrayTester.mainFunction();
//        ArrayTester.sum(1,2,3,4,5,6,78,9,10);
//        ArrayTester.sum(1,2,3,1,2,3);
        ArrayTester.sum("hello world", 1,2,3,4);
        ArrayTester a[] = new ArrayTester[10];
        a[0] = new ArrayTester();

    }
}

