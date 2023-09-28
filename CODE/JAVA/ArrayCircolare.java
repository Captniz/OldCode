import java.util.Random;

public class ArrayCircolare {

    public static void main(String[] args) {
        final int DIM = 10;
        Buffer buffer = new Buffer(DIM);
        Semaphore P = new Semaphore(0);
        Semaphore V = new Semaphore(DIM);

        Producer p = new Producer(buffer, P, V);
        Consumer c = new Consumer(buffer, P, V);

        p.start();
        c.start();
    }
}

class Buffer {
    public int N;
    public int B[];
    public int in;
    public int out;

    Buffer(int DIM) {
        N = DIM;
        B = new int[N];
        in = 0;
        out = 0;
    }

    void insert(int elem) {
        B[in] = elem;
        in = (in + 1) % N;
    }

    int remove() {
        int tmp = B[out];
        out = (out + 1) % N;
        return tmp;
    }

    public String toString() {
        String s = "";
        for (int i = 0; i < N; i++)
            s += B[i] + " ";
        return s;
    }
}

class Semaphore {
    private int permits;

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

class Producer extends Thread {
    private Buffer buffer;
    private Semaphore P;
    private Semaphore V;
    Random r = new Random();

    public Producer(Buffer b, Semaphore p, Semaphore v) {
        buffer = b;
        P = p;
        V = v;
    }

    public void run() {
        while (true) {
            V.acquire();
            buffer.insert(r.nextInt(20));
            P.release();
        }
    }
}

class Consumer extends Thread {
    private Buffer buffer;
    private Semaphore P;
    private Semaphore V;

    public Consumer(Buffer b, Semaphore p, Semaphore v) {
        buffer = b;
        P = p;
        V = v;
    }

    public void run() {
        while (true) {
            P.acquire();
            int tmp = buffer.remove();
            V.release();
            System.out.println(buffer.toString() + " | " + tmp);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
            }
        }
    }
}