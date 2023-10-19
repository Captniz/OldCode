public class AutoPompa {
    public static void main(String[] args) {

    }
}

class Semaphore {
    private int value;

    public Semaphore(int value) {
        this.value = value;
    }

    public synchronized void P() {
        while (value == 0) {
            try {
                wait();
            } catch (InterruptedException e) {
                System.out.println("Errore");
            }
        }
        value--;
    }

    public synchronized void V() {
        value++;
    }
}
