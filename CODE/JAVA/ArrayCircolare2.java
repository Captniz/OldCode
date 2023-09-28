import java.util.Random;

public class ArrayCircolare2 {
    public static void main(String[] args) {
        final int DIM = 5;
        Semaphore sem[] = new Semaphore[DIM];
        Thinker[] thnk = new Thinker[DIM];
        for (int i = 0; i < DIM; i++) {
            sem[i] = new Semaphore(1);
        }
        for (int i = 0; i < DIM; i++) {
            thnk[i] = new Thinker(sem[(i)], sem[((i + 1) % DIM)]);
        }

        for (int i = 0; i < DIM; i++) {
            thnk[i].start();
        }
    }
}

class Semaphore {
    private int permits; // Numero di permessi

    public Semaphore(int v) {
        permits = v;
    }

    public synchronized void acquire() {
        while (permits == 0) {
            try {
                wait();
            } catch (InterruptedException e) {
            }
        }
        permits--;
    }

    public synchronized void release() {
        permits++;
        notify();
    }

    public synchronized int getPermits() {
        return permits;
    }
}

class Thinker extends Thread {
    private Semaphore L;
    private Semaphore R;
    Random rnd = new Random();
    Random r = new Random();

    public Thinker(Semaphore l, Semaphore r) {
        L = l;
        R = r;
    }

    public synchronized void run() {
        System.out.println(this.getName() + " | Parto");
        System.out.println(this.getName() + ", Non c'ho forchette quindi penso");
        try {
            Thread.sleep(rnd.nextInt(100) + 1);
        } catch (InterruptedException e) {
        }
        while (true) {
            L.acquire();
            if (R.getPermits() == 1) {
                R.acquire();
                System.out.println(this.getName() + ", Mi me magni eh");
                try {
                    Thread.sleep(rnd.nextInt(100) + 1);
                } catch (InterruptedException e) {
                }
                R.release();
                L.release();

            } else {
                L.release();
                System.out.println(this.getName() + ", Non c'ho forchette quindi penso");
                try {
                    Thread.sleep(rnd.nextInt(100) + 1);
                } catch (InterruptedException e) {
                }
            }
        }
    }
}