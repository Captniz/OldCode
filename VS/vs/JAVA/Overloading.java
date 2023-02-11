import java.util.Scanner;
public class Overloading {
    public static void main(String[] args) {
        Persona p = new Persona();
        Scanner scn = new Scanner(System.in);
        String tmp = "";

        try{

        }catch()
    }
}
class Persona {
    int eta;
    String nme;

    Persona(){
        eta=0;
        nme="pippo";
    }

    public void setDati(int eta){
        this.eta=eta;
    }
    public void setDati(String nme){
        this.nme=nme;
    }
    public void stampa(){
        System.out.println("["+nme+","+eta+"]");
    }
}