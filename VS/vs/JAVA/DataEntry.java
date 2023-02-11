/*14>230206_dataEntry.java
Creare un metodo main() per vedere il corretto funzionamento di una classe  dataEntry(). Nella classe c'è un metodo controllaDati() che ritorna un boolean se tutto è andato a buon fine. In particolare provate a passare una stringa e un intero: se riuscite, gestite tutto con Exceptions.
Es: di se ho una classe persona: [cognome, nome, eta, reddito]
quando viene passato l'attributo cognome a controllaDati() se ci sono caratteri che non solo alfabetici viene segnalato errore di data entry.
In questo caso viene richiesto il dato all'utente.
Ovviamente il metodo dataEntry() prevederà overloading.*/
/**
 * DataEntry
 */
import java.util.*;
public class DataEntry {
    String nome;
    int eta;
    
    public boolean controllaDati(String str, int id){
        switch (id) {
            case 0:
                //Stringa
                try {
                    for (int i = 0; i < str.length(); i++) {
                        Integer.parseInt(str.substring(i, (i+1)));
                    }
                } catch (Exception e) {
                    return false;
                }
                return true;
            case 1:
                //Integer
                try {
                    Integer.parseInt(str);
                } catch (Exception e) {
                    return true;
                }
                return false;
            default:
                break;
        }
        return true;
    }
    public void setNome(String str){
        nome=str;
    }
    public void setEta(int nmr){
        eta=nmr;
    }
    public void stampa(){
        System.out.println();
        System.out.println(nome);
        System.out.println(eta);
    }

    public static void main(String[] args) {
        String str = "";
        Scanner scn = new Scanner(System.in);
        DataEntry a = new DataEntry();

        do{
            System.out.print("\nNome:");
            str=scn.nextLine();
        }while(a.controllaDati(str, 0));
        a.setNome(str);
        do{
            System.out.print("\nEta:");
            str=scn.nextLine();
        }while(a.controllaDati(str, 1));
        a.setEta(Integer.parseInt(str));
        a.stampa();
    }
}