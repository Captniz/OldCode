import java.util.*;

//Make a program with two threads. One adds up the first 500 numbers, the other adds up the last 500 numbers. The main thread should wait for the two threads to finish, and then print the sum of the first 500 numbers, the sum of the last 500 numbers, and the total sum.
public class Threading {
    public static void main(String[] args) {
        ThreadAdd addr1 = new ThreadAdd(0);
        Thread t1 = new Thread(addr1);
        t1.start();
        ThreadAdd addr2 = new ThreadAdd(addr1.getN());
        Thread t2 = new Thread(addr2);
        t2.start();
        try {
            t1.join(500);
            t2.join(500);
        } catch (Exception e) {
            System.out.println(e);
        }
        System.out.println(addr2.getN());
    }
}

class ThreadAdd implements Runnable {
    int n;

    public ThreadAdd(int n) {
        this.n = n;
    }

    public void run() {
        for (int i = 0; i < 500; i++) {
            n++;
        }
    }

    public int getN() {
        return n;
    }
}