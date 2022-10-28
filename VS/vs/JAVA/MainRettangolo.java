/*1>
Costruire una classe rettangolo partendo da una base, un’altezza.
Il Main deve permettere di calcolare e visualizzare l'area e il perimetro dell'oggetto istanziato.
Istanziare (Creare) 3 oggetti:

- costruttore: ne sono presenti due. Il primo crea un rettangolo con
le dimensioni definite, il secondo, invece, permette all’utente di
assegnare i valori
- metodi: possono essere suddivisi in più categorie. I metodi
contenenti la dicitura “get” (getBase, getAltezza…) restituiscono il
valore della dimensione richiesta o eseguono un’operazione specifica
(getArea). Quelli contenenti il prefisso “set”, invece, permettono
di assegnare un nuovo valore alla variabile d’istanza.  
*/

public class MainRettangolo {
    public static void main(String[] args) {
        Rettangolo arr[ ]= new Rettangolo[3];
        arr[0]= new Rettangolo();
        arr[1]= new Rettangolo(5,6);
        arr[2]= new Rettangolo(20,30);

        for (int i = 0; i < 3; i++) {
            System.out.println("RETTANGOLO " + (i+1) + ":");
            System.out.println("Area " + (i+1) + ": " + arr[i].getArea());
            System.out.println("Perimetro " + (i+1) + ": " + arr[i].getPerim());
            System.out.print("\n\n");
        }
    }
}
