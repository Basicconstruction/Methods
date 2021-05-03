import java.lang.reflect.Array;

class Person{
    public String name;
    public static int age;
    public Person(String _name, int _age){
        this.name = _name;
        age = _age;
        System.out.println("hello, Person generate!");
    }
    @Deprecated
    public void getInfo(){
        System.out.println(this.name+" "+ age);
    }
}

class Student extends Person{
    public String gender;
    public Student(String _gender,String name){
        super(name,19);
        this.gender = _gender;
    }
    public Student(String _gender,String _name,int _age){
        this(_gender,_name);
        age = _age;
//        super(_name, _age);
//        gender = _gender;
        System.out.println("hello, Student generate!");
    }
    @Override
    public void getInfo(){
        System.out.println(this.name+" "+this.gender+" "+age);
    }

}
public class Q7 {
    public static void main(String[] args) throws InterruptedException {
//        Student Eric = new Student("man", "Eric", 19);
//        Eric.getInfo();
//        System.out.println(Eric instanceof Student);
//        Object obj = new int[]{1,2,3};
//        if(obj instanceof int[]){
//            for(int i : (int[])obj){
//                System.out.println(i);
//            }
//        }
//        Object o = new Student("man","Eric",19);
//        o.wait(2000);
        Object c = 19272L;
        long h = (long)c;
        System.out.println(h);
        System.out.println(c.toString());
        Object d = new Student("man", "Alex");
        System.out.println(d.toString());

    }
}
