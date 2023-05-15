public class MultiThreadSezioniCritiche {
    public static void main(String[] args) {
        CustomThread t1[] = new CustomThread[10];
        Semaphore s = new Semaphore(3);
        for (int i = 0; i < t1.length; i++) {
            t1[i] = new CustomThread(s);
            t1[i].start();
        }

        try {
            for (int i = 0; i < t1.length; i++) {
                t1[i].join();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class CustomThread extends Thread {
    Semaphore s;

    CustomThread(Semaphore s) {
        super();
        this.s = s;
    }

    @Override
    public void run() {
        try {
            s.aquire();
            System.out.println("Thread " + this.getName() + " is running");
            Thread.sleep(3000);
            s.release();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Semaphore {
    private int valore;

    public Semaphore(int v) {
        valore = v;
    }

    public synchronized void aquire() throws InterruptedException {
        while (valore == 0) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        valore--;
    }

    public synchronized void release() {
        valore++;
        notify();
    }
}