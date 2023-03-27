import java.io.File;
import java.util.Scanner;
import java.util.Stack;
import java.util.Queue;
import java.util.LinkedList;

public class CambiaPila {
    public static void main(String[] args) {
        Scanner scn;
        Stack<Integer> st = new Stack<Integer>();
        scn = new Scanner(System.in);

        System.out.print("Numero da trovare:");
        int a = scn.nextInt();
        System.out.print("Numero sostituito:");
        int b = scn.nextInt();

        try {
            scn = new Scanner(new File("input.txt"));
            while (scn.hasNext()) {
                st.push(Integer.parseInt(scn.next()));
            }
        } catch (Exception e) {
            System.out.println("errore");
        }

        System.out.println(st);
        subsS(st, a, b);
        System.out.println(st);
    }

    public static void subsS(Stack<Integer> st, int find, int replace) {
        Stack<Integer> temp = new Stack<Integer>();
        int box = 0;
        while (!st.isEmpty()) {
            box = st.pop();
            if (box == find) {
                temp.push(replace);
            } else {
                temp.push(box);
            }
        }

        while (!temp.isEmpty()) {
            st.push(temp.pop());
        }
    }

    public static Queue<Integer> subsQ(Queue<Integer> qu, int find, int replace) {
        Queue<Integer> temp = new LinkedList<Integer>();
        int box = 0;
        while (!qu.isEmpty()) {
            box = qu.poll();
            if (box == find) {
                temp.add(replace);
            } else {
                temp.add(box);
            }
        }

        return temp;
    }
}
