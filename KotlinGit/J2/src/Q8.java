class Data{
    private long d1;
    private boolean b;
    public Data(){
        d1 = 0;
    }
    public Data(long _d){
        d1 = _d;
    }
    public Data(String s, boolean _b){
        d1 = toLong(s,false);
        b = _b;
    }
    public Data(String s){
        d1 = toLong(s,true);
    }

    public boolean isNumber(char c){
        return isNumber((byte)c);
    }

    public boolean isNumber(byte i){
        if(i>=48 && i<=57){
            return true;
        }else{
            return false;
        }
    }

    public long pow(int a,int b){
        long output = 1L;
        for(int k = 0; k < b;k++){
            output *= a;
        }
        return output;
    }

    private long toLong(String s,boolean strict) {
        boolean sign = true;
        long output = 0L;
        byte b[] = s.getBytes();
        for(int i = 0; i < b.length;i++){
            if(!isNumber(b[i])&&strict){
                return 0L;
            }else if(isNumber(b[i])){
                output += ((int)b[i] - 48) * pow(10,(b.length - i - 1));
            }else{
                return output / pow(10, i);
            }
        }
        return output;
    }
    public long getValue(){
        return d1;
    }
}
public class Q8 {
    public static void main(String[] args){
//        Integer a = 1011;
//        Integer b = 1011;
//        int c = a;
//        Object f = 10.3f;
//        float g = (float)f;
//        System.out.println(c);
//        System.out.println(g);
        Data a = new Data(100);
//        System.out.println(a.getValue());
        Object v = new Data("728qad", false);
        System.out.println(((Data) v).getValue());

    }
}
