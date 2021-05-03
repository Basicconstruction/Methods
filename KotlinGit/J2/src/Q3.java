
class Department{
    public Civil civilList[];
    public String place;
    public int old;
    public long value;
    public Department(String _place, int _old, long _value){
        this.place = _place;
        this.old = _old;
        this.value = _value;
    }
    public void setCivilList(Civil[] _civilList){
        this.civilList = _civilList;
    }
    public Civil[] getCivil(){
        return this.civilList;
    }
    public void getInfo(){
        System.out.println(""+this.place+" "+this.old+" "+this.value+" "+this.civilList.length);
    }
}

class Civil{
    public Department dep;
    public String name;
    public int age;
    public Civil(String _name, int _age){
        this.name = _name;
        this.age = _age;
    }
    public void setDepartment(Department _dep){
        this.dep = _dep;
    }
    public Department getDepartment(){
        return this.dep;
    }
    public void getInfo(){
        System.out.println(""+this.name+" "+this.age+" "+this.dep.place+" ");
    }

}

public class Q3 {
    public static void main(String[] args){
        Civil a = new Civil("小明",19);
        Civil b = new Civil("小红",18);
        Civil c = new Civil("小李",20);
        Department def = new Department("Beijing", 100, 1000000);
        a.setDepartment(def);
        b.setDepartment(def);
        c.setDepartment(def);
        a.getInfo();
        def.setCivilList(new Civil[]{a,b,c});
        def.getInfo();
    }
}
