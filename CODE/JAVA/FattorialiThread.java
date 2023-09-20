
/*Scrivere un programma che calcoli con N thread different i valori fattoriali di N numeri naturali tra 1 e 10 generati casualmente in un vettore*/
import java.util.Random;

public class FattorialiThread extends Thread {
    private int num;
    private int fattoriale;

    public FattorialiThread(int n) {
        num = n;
        fattoriale = 1;
    }

    public void run() {
        for (int j = 1; j <= num; j++) {
            fattoriale *= j;
        }
        System.out.println("Il fattoriale di " + num + " è " + fattoriale);
    }

    public static void main(String[] args) {
        final int DIM = 10;
        int[] vettore = new int[DIM];
        Random random = new Random();
        for (int i = 0; i < vettore.length; i++) {
            vettore[i] = random.nextInt(10) + 1;
        }
        FattorialiThread[] threads = new FattorialiThread[DIM];
        for (int i = 0; i < threads.length; i++) {
            threads[i] = new FattorialiThread(vettore[i]);
            threads[i].start();
        }
        for (int i = 0; i < threads.length; i++) {
            try {
                threads[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}