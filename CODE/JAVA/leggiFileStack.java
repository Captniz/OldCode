import java.io.File;
import java.util.Scanner;
import java.util.Stack;

public class leggiFileStack {
    public static void main(String[] args) {
        Stack<Integer> s = new Stack<Integer>();
        Scanner scn;
        try {
            scn = new Scanner(new File("input.txt"));
            try {
                s.push(scn.nextInt());

                while (scn.hasNext()) {
                    s.push(scn.nextInt());
                }
            } catch (Exception e) {
                System.out.println("Errore: File vuoto");
                return;
            }
        } catch (Exception e) {
            System.out.println("Errore: File inesistente");
            return;
        }

        System.out.println("Stack: " + s);
    }
}