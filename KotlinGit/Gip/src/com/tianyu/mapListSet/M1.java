package com.tianyu.mapListSet;
import java.util.*;
class St{
    private static int id = 0;
    public int ownId;
    public String name;
    public St(String _name){
        name = _name;
        id = id + 1;
        ownId = id;
    }
    public int getId() {
        return id;
    }
}
public class M1 {
    private int sends = 0;
    public static int randomInt(int seed,int low, int high){
        Random rand = new Random(seed);
        int randGet = (int)rand.nextInt();
        return low+(randGet>0?randGet:-randGet)%high;
    }
    public static void main(String[] args){
//        HashSet<Integer> c = new HashSet<Integer>();
//        for(int i = 0; i < 200;i++){
//            c.add((Integer)randomInt(i,0,101));
//        }
//        System.out.println(c);
//        for(Integer d : c){
//            System.out.println(d);
//        }
//        List<Integer> s = new ArrayList<Integer>();
//        s.add(1);
//        s.add(2);
//        s.add(3);
////        System.out.println(s);
//        s.remove((Integer)2);
////        System.out.println(s);
//        System.out.println(s.indexOf(3));
//        System.out.println(s.contains((Integer)1));
//        s.add(4);
//        s.add(5);//1 3 4 5
////        System.out.println(s.subList(1,3));
////        System.out.println(s.containsAll(new ArrayList<Integer>(1)));
//        System.out.println(Arrays.toString(s.toArray()));
//        List<Integer> j = new ArrayList<Integer>();
//        j.add(3);
//        j.add(1,4);
//        j.add(2,0);
//        Collections.sort(j);
//        for(Integer s:j){
////            System.out.println(s);
//        }
//        Collections.reverse(j);
//        for(Integer s:j){
////            System.out.println(s);
//        }
//        Collections.shuffle(j);
//        for(Integer k:j){
////            System.out.println(k);
//        }
//        List<Integer> k = new ArrayList<>();
//        k.add(1);
//        k.add(2);
//        k.add(3);
//        List<Integer> l = new ArrayList<>(k);
//        l.addAll(j);
//        k.retainAll(j);
//        for(Integer d:k){
//            System.out.println(d+"$$");
//        }
//        for(Integer s:l){
//            System.out.println(s);
//        }
//        Collection<Integer> kl = new ArrayList<>();
//        kl.add(1);
//        kl.add(3);
//        kl.add(0);
//        Collection<Integer> op = new ArrayList<>(kl);
//        Iterator<Integer> itr = kl.iterator();
//        Integer s;
//        while(itr.hasNext()){
//            s = itr.next();
//            System.out.println("  "+s);
//        }
//        kl.add(8);
//        kl.add(9);
//        System.out.println(kl);
//        itr = kl.iterator();
//        for(int i = 0; i < 3;i++){
//            if(i == 0||i==2){
//                itr.next();
//                itr.remove();
//            }else{
//                itr.next();
//            }
//        }
//        System.out.println(kl);
//        HashSet<Integer> x = new HashSet<>();
//        for(int i = 0; i<100;i++){
//            x.add((Integer)(i%10));
//        }
////        for(Integer s :x){
////            System.out.println(s);
////        }
//        Iterator<Integer> gh = x.iterator();
//        Integer i;
//        while(gh.hasNext()){
//            i = gh.next();
//            System.out.println(i);
//        }
//        System.out.println(x);
        HashSet<St> jk = new HashSet<>();
        jk.add(new St("eric"));
        jk.add(new St("hui"));
        jk.add(new St("kl"));
        Iterator<St> io = jk.iterator();
        St hj;
        while(io.hasNext()){
            hj = io.next();
            System.out.println(hj.ownId+"  "+hj.name);
        }


    }

}
