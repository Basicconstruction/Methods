public class Q5 {
    public static void main(String[] args){
        for(String arg:args){
            System.out.println(arg);
        }
        String s1 = "hello world npc";
//        for(int i = 0; i < s1.length();i++){
//            System.out.print(s1.charAt(i)+" ");
//        }
//        for(char c:s1.toCharArray()){
//            System.out.print(c+" ");
//        }
//        for(char c:s1.toCharArray()){
//            System.out.print(s1.indexOf(c)+" ");
//        }
//        for(int i = 0; i < s1.length(); i++){
//            System.out.print(s1.indexOf(s1.charAt(i),i)+" ");
//        }
//        s1 = s1.replaceAll("o", "KKK");
//        s1 = s1.replaceFirst("l", "AAA");
//        String d[] = s1.split(" ");
//        System.out.println(s1.toLowerCase().substring(0,10));
//        for(String s:d){
//            System.out.println(s.toUpperCase().substring(0));
//        }
        String d1 = new String("a123");
        String d2 = "C3w";
        System.out.println(d1.compareTo(d2));
        System.out.println(d1.compareToIgnoreCase(d2));
//        byte c[] = d1.getBytes();
//        for(byte d:c){
//            System.out.print(d+" ");
//        }


    }
}
