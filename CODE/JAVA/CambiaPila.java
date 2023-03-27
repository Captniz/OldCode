import java.io.File;
import java.util.Scanner;
import java.util.Stack;

public class CambiaPila {
    public static void main(String[] args) {
        Scanner scn;
        Stack<Integer> st = new Stack<Integer>();
        try {
            scn = new Scanner(new File("input.txt"));
            while (scn.hasNext()) {
                st.push(Integer.parseInt(scn.next()));
            }
        } catch (Exception e) {
            System.out.println("errore");
        }
        System.out.println(st);
    }

    public static void subs(){
        
    }
}
