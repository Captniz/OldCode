import java.util.*;

//Make a program with two threads. One adds up the first 500 numbers, the other adds up the last 500 numbers. The main thread should wait for the two threads to finish, and then print the sum of the first 500 numbers, the sum of the last 500 numbers, and the total sum.
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
}