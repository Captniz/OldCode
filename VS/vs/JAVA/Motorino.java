/*2> 221103_motorino.java
Scrivere la classe Motorino che ha i seguenti attributi
colore: una stringa indicante il colore del motorino, 
velocità: un numero con la virgola indicante la velocità in Km/h che possiede il motorino, 
tipo: una stringa indicante la marca e il modello del motorino es. “Piaggio scarabeo”, 
antifurto: un boolean che indica se è stato inserito l’antifurto (ha un valore iniziale pari a false). 

Usare Dia per UML

Il costruttore ha come parametri una stringa per il colore, una stringa per il tipo, un numero con la virgola per la velocità ed assegna opportunamente i valori dei parametri agli attributi. 

Scrivere il metodo 
getVelocità: che restituisce la velocità del motorino, 
accelera: che ha come parametro un numero con la virgola indicante i Km/h che si vogliono aggiungere alla velocità, il metodo verifica il valore dell’attributo antifurto se è false aggiunge il valore del parametro all’attributo velocità, altrimenti non fa nulla.
inserisciAntifurto: che assegna un valore true all’attributo antifurto.

Istanziare 2 oggetti.*/
//221103_motorino.java
public class Motorino {
    String col;
    double vel;
    String tipo;
    boolean aFurt;
    
    Motorino(String col, String tipo, double vel){
        this.col = col;
        this.vel = vel;
        this.tipo = tipo;
        this.aFurt = false;
    }

    public double getVelocita(){
        return this.vel;
    }

    public void accelera(double vel){
        if(this.aFurt == false){
            this.vel += vel;
        }
    }

    public void inserisciAntifurto(){
        this.aFurt = true;
    }

    public static void main(String[] args) {
        Motorino m1 = new Motorino("rosso", "Piaggio", 0);
        Motorino m2 = new Motorino("verde", "Yamaha", 0);
        m1.accelera(10);
        m2.accelera(20);
        System.out.println("Velocita m1: " + m1.getVelocita());
        System.out.println("Velocita m2: " + m2.getVelocita());
        m1.inserisciAntifurto();
        m1.accelera(10);
        System.out.println("Velocita m1: " + m1.getVelocita());
    }
}
