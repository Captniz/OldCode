import java.util.*;

/*
2) Sommare i primi 10.00 numeri naturali. Un thread somma i primi 5.000, il secondo thread somma gli altri 5.000.

2) Dato un array di DIM (inserito dall'utente) elementi generati casualmente compresi tra 0 e 100, scrivi un programma parallelo che ricerchi un valore K all'interno dell'array e dichiari esso è presente almeno una volta nell'array.

Per farlo si devono usare 2 thread.*/

public class Threading {
    public static void main(String[] args) {
        MyThread[] v = new MyThread [10];
        int surplus = 0;
        int input = 21;
        int div = input/10;
        int i = 0;

        if ( input%10 != 0f && input > 10) {
            surplus = input%10;
        }
        
        if (div == 0) {
            div=1;
        }

        for (i = 0; i < 9 || input<=1; i++) {
            v[i] = new MyThread(div);
            input -= div;
        }
        v[i+1] = new MyThread(div+surplus);


    }
}

class MyThread extends Thread {
    Semaphore s;
    float pay;
    int time;

    public MyThread(int s) {
        Random rnd = new Random();
        this.s = s;
        pay = 0f;
        time = rnd.nextInt(2001)+1500;
    }

    public void run() {
        s.P();
        try {
            Thread.sleep(time);
            pay = time/1000f*0.5f;
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        s.V();
    }

    public float getPay() {
        return pay;
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
                e.printStackTrace();
            }
        }
        value--;
    }

    public synchronized void V() {
        value++;
        notify();
    }
}

/*
public class Threading {
    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        RunnableFind find1 = new RunnableFind(arr, 3);
        Thread t1 = new Thread(find1);
        t1.start();
        try {
            t1.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class RunnableFind implements Runnable {
    int[] arr;
    int n;

    public RunnableFind(int[] arr, int n) {
        this.arr = arr;
        this.n = n;
    }

    public void run() {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == n) {
                System.out.println("Found " + n + " at index " + i);
                break;
            }
        }
    }
}*/