import java.util.LinkedList;
import java.util.Queue;

/*
 * In un piccolo ristorante fast-food le ordinazioni si presentano alla cassa
 * posta all’ingresso e la cucina le prende in carico una alla volta,
 * nell’ordine in cui sono state effettuate. 
 * 
 * Il cassiere predispone per ogni piatto ordinato un foglietto che ne riporta il nome, la quantità ordinata e
 * le eventuali note di preparazione e lo pone in cima alla pila delle
 * ordinazioni precedenti; 
 * 
 * il cuoco quando è disponibile prende il primo
 * foglietto in fondo alla pila e ne inizia la preparazione. L’informatizzazione
 * del processo descritto può essere basata sulle classi del diagramma UML a
 * fianco.
 * 
 * La classe ListaOrdinazioni deve realizzare uno schema produttore/consumatore
 * con politica FIFO di oggetti di tipo Ordinazioni.
 * 
 * Implementare le classi ListaOrdinazioni e Ordinazioni. Per verificare il
 * corretto funzionamento dell’implementazione realizzare due classi che
 * simulino il comportamento del cassiere e del cuoco in modo che rappresentino
 * due thread distinti che, rispettivamente, inseriscono ed estraggono
 * ordinazioni dalla lista con un tempo di attesa casuale tra un’operazione e la
 * successiva.
 */

public class ristoranteThread {
    public static void main(String[] args) {
        ListaOrdinazioni ordinazioni = new ListaOrdinazioni();
        Cameriere cameriere = new Cameriere(ordinazioni);
        Cuoco cuoco = new Cuoco(ordinazioni);
        Cuoco cuoco2 = new Cuoco(ordinazioni);

        cameriere.start();
        cuoco.start();
        cuoco2.start();

    }
}

class ListaOrdinazioni {
    Queue<Ordinazione> ordinazioni;

    public ListaOrdinazioni() {
        ordinazioni = new LinkedList<Ordinazione>();
    }

    public synchronized void inserisciOrdinazione(Ordinazione ordinazione) {
        ordinazioni.add(ordinazione);
    }

    public synchronized Ordinazione estraiOrdinazione() {
        return ordinazioni.remove();
    }

    public boolean isEmpty() {
        return ordinazioni.isEmpty();
    }
}

class Ordinazione {
    public String name;
    public String add;

    public Ordinazione(String name, String add) {
        this.name = name;
        this.add = add;
    }
}

class Cameriere extends Thread {
    ListaOrdinazioni ordinazioni;

    public Cameriere(ListaOrdinazioni ordinazioni) {
        this.ordinazioni = ordinazioni;
    }

    @Override
    public void run() {
        String[] nomi = { "Pasta", "Pizza", "Hamburger", "Insalata", "Patatine", "Bibita" };
        String[] note = { "Al dente", "Senza pomodoro", "Senza cipolla", "Senza maionese", "Senza sale" };

        for (;;) {
            String nome = nomi[(int) (Math.random() * nomi.length)];
            String nota = note[(int) (Math.random() * note.length)];
            int quantita = (int) (Math.random() * 3) + 1;

            Ordinazione ordinazione = new Ordinazione(nome, nota);

            for (int i = 0; i < quantita; i++) {
                ordinazioni.inserisciOrdinazione(ordinazione);
            }

            System.out.println("Cameriere: " + ordinazione.name + " " + ordinazione.add + " " + quantita);

            try {
                Thread.sleep((int) (Math.random() * 1000));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class Cuoco extends Thread {
    ListaOrdinazioni ordinazioni;

    public Cuoco(ListaOrdinazioni ordinazioni) {
        this.ordinazioni = ordinazioni;
    }

    @Override
    public void run() {
        for (;;) {
            if (ordinazioni.isEmpty()) {
                System.out.println("Non ci sono ordinazioni");
                try {
                    Thread.sleep((int) (Math.random() * 100));
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                continue;
            }
            Ordinazione o = ordinazioni.estraiOrdinazione();

            System.out.println("Cuoco: Sto cuocando " + o.name + " " + o.add);

            try {
                Thread.sleep((int) (Math.random() * 1000));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
