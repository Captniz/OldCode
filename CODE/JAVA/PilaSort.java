import java.io.*;
import java.util.Scanner;
import java.util.Stack;
public class PilaSort {
    public static void main(String[] args) {
        Stack<Integer> pila1 = new Stack<Integer>();
        Stack<Integer> pila2 = new Stack<Integer>();
        try {
            Scanner sc = new Scanner(new File("input.txt"));
            int n=0;
            int tmp=0;

            pila1.push(sc.nextInt());

            while (sc.hasNext()) {
                n = sc.nextInt();
                //SE CAVI IL PRIMO NUMERO ENTRA SUBITO LA CONDIZIONE DI VUOTO
                tmp = pila1.pop();

                while (!pila1.empty() && n < tmp) {
                    pila2.push(tmp);
                    tmp = pila1.pop();
                }
                pila1.push(tmp);
                pila1.push(n);
                  
                while (!pila2.empty()) {
                    pila1.push(pila2.pop());
                }     
                System.out.println(pila1);
            }
            System.out.println(pila1);
            sc.close();
        } catch (IOException e) {
            System.out.println("Errore di I/O");
        }
    }
    
}