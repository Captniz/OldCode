/*5>221125_studenti.java
Creare una classe Studente() contenente 4 campi:
Id: codice intero progressivo (il primo studente avrà 1)
Cognome: string
Nome: string
Eta: intero (random [20..50])

-creare un array di DIM studenti (DIM = 10) 
-popolare l'array (Id progressivo) (Cognome 5 lettere maiuscole AAAAA, poi BBBBB) (Nome 5 lettere minuscole aaaaa, poi bbbbb) (Eta random)
-visualizzare l'array*/
//221125_studenti.java
import java.util.Random;
public class Studenti {
    int id;
    String cognome;
    String nome;
    int eta;

    Studenti(int id, String cognome, String nome, int eta) {
        this.id = id;
        this.cognome = cognome;
        this.nome = nome;
        this.eta = eta;
    }
    public static void main(String[] args) {
        Random rnd = new Random();
        Studenti[] studenti = new Studenti[10];
        char tmp []= new char[5];

        for (int i = 0; i < studenti.length; i++) {
            for (int j = 0; j < tmp.length; j++) {
                tmp[j] = (char) (i+'a');
            }
            studenti[i] = new Studenti(i+1, new String(tmp).toUpperCase(), new String(tmp), rnd.nextInt(30)+20);
        }

        for (Studenti std : studenti) {
            System.out.println("Id: " + std.id + "\nCognome: " + std.cognome + "\nNome: " + std.nome + "\nEta: " + std.eta + "\n");
        }
    }
}
