import java.sql.Time;

public class ponte {
    /*
     * Un ponte che collega due sponde di un fiume è così stretto che permette il
     * passaggio delle auto su un’unica corsia a senso alternato (quindi le macchine
     * possono muoversi concorrentemente sul ponte solo se vanno nella stessa
     * direzione). Le macchine che procedono da sinistra a destra vengono indicate
     * con l’espressione “Sinistra” e a quelle che procedono da destra a sinistra
     * con l’espressione “Destra”.
     * 
     * Scrivere un programma che simuli l’accesso al ponte in modo da evitare
     * incidenti fra “Sinistra” e “Destra”, usando i semafori per la
     * sincronizzazione.
     */

    public static void main(String[] args) {
        Semaphore s = new Semaphore(1);
        Corsia dxCorsia = new Corsia(10, s);
        Corsia sxCorsia = new Corsia(7, s);

        dxCorsia.start();
        sxCorsia.start();
    }
}

class Corsia extends Thread {
    private int macchine;
    private Semaphore s;
    long start;

    public Corsia(int macchine, Semaphore s) {
        this.macchine = macchine;
        this.s = s;
        start = 0;
    }

    @Override
    public void run() {
        for (;;) {
            if (s.getValue() == 0) {
                try {
                    Thread.sleep(((int) Math.random() * 300) + 1);
                    System.out.println(this.getName() + " added a car");
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                continue;
            }
            s.p();
            start = System.currentTimeMillis();
            System.out.println(this.getName() + " is letting " + macchine + " cars pass");
            while (System.currentTimeMillis() < (start + 2000)) {
                System.out.println(macchine + " macchine remainging in " + this.getName() + " corsia");
                if (macchine != 0)
                    macchine--;
            }
            s.v();
        }
    }
}

class Semaphore {
    private int value;

    public Semaphore(int value) {
        this.value = value;
    }

    public synchronized void p() {
        while (value == 0) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        value--;
    }

    public synchronized void v() {
        value++;
        notify();
    }

    public synchronized int getValue() {
        return value;
    }
}
