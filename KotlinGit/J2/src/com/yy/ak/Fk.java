package com.yy.ak;
enum Sex{
    MALE("男"){
//        @Override
//        public String toString(){
//            System.out.println("hello world");
//            return "男性tt";
//        }
    },FEMALE("女"){
//        @Override
//        public String toString(){
//            System.out.println("hello world");
//            return "女性mm";
//        }
    };
    private String title;
    private Sex(String title){
        this.title = title;
    }
    public String toString(){
        System.out.println("hello world");
        String s1 = "";
        s1 = switch(this){
            case FEMALE -> "女性";
            case MALE -> "男性";
            default -> "null";
        };
        return s1;
    }
//    public abstract String toString();
}
class Pupil{
    private String name;
    private int age;
    private Sex sex;
    public Pupil(String _name, int _age, Sex _sex){
        this.name = _name;
        this.age = _age;
        this.sex = _sex;
    }
    public String toString(){
        return "姓名: "+this.name+" 年龄: "+this.age+" 性别: "+this.sex;
    }
    public Sex getSex(){
        return this.sex;
    }
}
public class Fk {
    public static void main(String[] args){
//        System.out.println(new Pupil("张三",19,Sex.FEMALE));
        Pupil a = new Pupil("张三",19,Sex.FEMALE);
        System.out.println(a+"\n"+a.getSex().name());
    }

}
