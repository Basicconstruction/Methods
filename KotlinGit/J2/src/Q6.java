public class Q6 {
    public static int getSameLength(String s1,String s2){
//        int l = s1.length()>s2.length()?s2.length():s1.length();
        int l = Math.min(s1.length(), s2.length());
        boolean sign = true;
        int get = 0;
        for(int h = 0; h < l-1;h++){
            if(s1.charAt(h) == s2.charAt(h)){
                get ++;
            }else{
                sign = false;
            }
            if(!sign){
                break;
            }
        }
        return get;
    }
    public static void main(String[] args){
        String a = "hello world";
        String f = "hello kity";
//        for(int i = 0;i < f.length()-1;i++){
//            System.out.print(a.contains(f.charAt(i)+"")+" ");
//            System.out.print("&&"+a.contains(f.substring(i,i+2))+"  ");
//        }
        System.out.println(getSameLength(a,f));

    }
}
