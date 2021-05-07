import java.io.FileNotFoundException;
import java.util.Formatter;

public class Q9 {
    public static void main(String[] args) throws FileNotFoundException {
        String str = "123";
        System.out.println(Integer.parseInt(str));
//        System.out.println(Integer.parseInt("123hello"));
//        System.out.println(Boolean.parseBoolean("truE"));
//        System.out.println("truE".toLowerCase());
        System.out.println(String.valueOf(1232));
        System.out.println(String.valueOf('中'));
        System.out.println("这个");
        System.out.println(String.valueOf(new char[]{'a', 'b', 'c'}));
        System.out.println("hello".toString());
//        String l = "";
//        System.out.println(new Formatter(l).format("hello%d",12));
//        System.out.println(String.format("我的名字是%s,我的年龄是%d", "eric", 19));
        System.out.printf("我的名字是%s,我的年龄是%d%n", "eric", 19);
        System.out.printf("%s %d%n","hello",100);
    }

}
