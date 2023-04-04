import java.util.*;

public class Threading extends Thread {
    public static void main(String[] args) {
        Threading[] t = new Threading[10];
        for (int i = 0; i < 10; i++) {
            t[i] = new Threading();
        }
        for (int i = 0; i < 10; i++) {
            t[i].start();
        }
    }

    public void run() {
        for (int i = 0; i < 10; i++) {
            System.out.println(i + " " + this.getName() + " ");
        }
    }
}
