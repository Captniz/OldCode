/*6>221128_garage.java
Scrivere una classe Auto che rappresenti le seguenti informazioni relative ad un docente: marca(string), modello(string), cilindrata(int) e costo(float), e che contenga il costruttore parametrizzato ed i metodi getMarca, getModello e getCilindrata e  getCosto che restituiscono rispettivamente i campi privati.
Usare poi una variabile boolean a piacere.

Scrivere poi una classe Garage, che rappresenti un insieme di automobili tramite un array di tipo Auto, e che contenga il costruttore parametrizzato ed un metodo costoMinimo che restituisce il costo minimo tra le varie vetture.*/
//221128_garage.java
import java.util.Scanner;
public class Garage {
    private Auto[] auto;

    Garage(int numeroAuto) {
        Scanner input = new Scanner(System.in);
        auto = new Auto[numeroAuto];
        for (int i = 0; i < auto.length; i++) {
            System.out.println("Inserisci la marca dell'auto " + (i+1) + ": ");
            String marca = input.nextLine();
            System.out.println("Inserisci il modello dell'auto " + (i+1) + ": ");
            String modello = input.nextLine();
            System.out.println("Inserisci la cilindrata dell'auto " + (i+1) + ": ");
            int cilindrata = input.nextInt();
            System.out.println("Inserisci il costo dell'auto " + (i+1) + ": ");
            float costo = input.nextFloat();
            System.out.println("Inserisci se l'auto " + (i+1) + " ha l'autodistruttore (true/false): ");
            boolean autodistruttore = input.nextBoolean();
            input.nextLine();
            auto[i] = new Auto(marca, modello, cilindrata, costo, autodistruttore);
        }
    }
    
    public float costoMinimo() {
        float min = auto[0].getCosto();
        for (int i = 1; i < auto.length; i++) {
            if (auto[i].getCosto() < min) {
                min = auto[i].getCosto();
            }
        }
        return min;
    }
    public static void main(String[] args) {
        
    }
}
