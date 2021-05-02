import kotlin.Unit;
import kotlin.jvm.functions.Function1;
import kotlin.jvm.functions.Function2;
import kotlin.jvm.functions.Function3;
import org.jetbrains.annotations.Nullable;

import java.io.IOException;

public class Jhave {
    private int HitPoints = 100;
    private int a = 10;
    public String utterGreeting(){
        return "black";
    }
    @Nullable
    public String determineFriendshipLevel(){
        return null;
    }
    public void setHitPoints(int value){
        this.HitPoints = value * 10;
    }
    public int getHitPoints(){
        return this.HitPoints * 10;
    }
    public void setA(int value){
        this.a = value * 10;
    }
    public int getA(){
        return this.a * 10;
    }
    public static void easyPrint(String str){
        System.out.println(str);
    }
    public void extendHandInFriendship() throws Exception{
        throw new Exception();
    }
    public static void apologize(){
        try{
            HeroKt.acceptApology();
        }catch(IOException e){
            easyPrint("Caught it!");
        }
    }
    public static void main(String[] args){
        System.out.println(HeroKt.add(3,1));
        HeroKt.handOverFood();
        SpellBook h = new SpellBook();
        for(String spell : h.spells){
            System.out.println(spell);
        }
        easyPrint(SpellBook.npy+"");
        SpellBook.printer();
        apologize();
        Function1<String, Unit>  translator = HeroKt.getTranslator();
        translator.invoke("i love you!");
        Function1<String, String> description = HeroKt.getDescription();
        System.out.println(description.invoke("Eric"));
//        Function3<String, Unit> translator2 = HeroKt.getTranslator2();
//        translator.invoke("i love you!");

    }

}
