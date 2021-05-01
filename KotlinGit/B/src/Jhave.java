import org.jetbrains.annotations.Nullable;

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
    public static void main(String[] args){
        System.out.println(HeroKt.add(3,1));
        HeroKt.handOverFood();
        SpellBook h = new SpellBook();
        for(String spell : h.spells){
            System.out.println(spell);
        }
    }

}
