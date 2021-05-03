
class People{
    public static String name;
    public People(String _name){
        name = _name;
    }
    public static void mainFunction(){
        int a[] = new int[10];
        int[] b = new int[]{1,2,3};
        for(int i : b){
            System.out.println(i);
        }
        int[][] c = new int[10][3];
//        for(int[] i: c){
//            System.arraycopy(b, 0, i, 0, i.length);
////            System.out.println(""+i);
////            i = b;
////            System.out.println(""+i+b+"");
////            for(int y: i){
////                System.out.println(y);
////            }
//        }
        for(int l = 0; l < 10; l++){
            c[l] = b;
        }
//        c[0] = b;
        System.out.println("\n");
        b[2] = 100;
        for(int[] p: c){
            System.out.println(""+p);
            for(int l: p){
                System.out.println(l);
            }
        }
    }
//    {
//        System.out.println(name+" hello!!!");
//    }
//    static{
//        System.out.println(name+" Start!!!");
//    }
}
public class Q1 {
    public static int sd = 123;
    public Q1(int _sd){
        sd = _sd;
    }
    public static void easyPrint(Object o){
        System.out.print(o);
    }
    public static void easyPrintln(Object o){
        System.out.println(o);
    }
    public static int absolute(int number){
        return number>0?number:-number;
    }
    public static int max(int n1, int n2){
        return Math.max(n1, n2);
    }
    public static void main(String[] args){
        People.mainFunction();
//        People p1 = new People("via");
//        People p2 = new People("viw");

//        easyPrintln("what's your matter? :"+1+0);
//        easyPrintln(~2);
//        int k = 10;
//        switch (k) {
//            case 1 ->    {
//                easyPrint("ghost");
//                easyPrintln(12);
//            }
//            case 2 -> easyPrint("I love you!");
//            case 10 -> easyPrintln("hello world");
//            default -> easyPrintln("no matter!");
//        }
////        int k = 10;
////        var d = switch (k) {
////            case 1 -> 1;
////            case 2 -> 2;
////            case 10 -> 3;
////            default -> 4;
////        };
//        easyPrintln(1);

    }
}
