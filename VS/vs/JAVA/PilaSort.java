/**
20>230311_PilaSort.java
Dato il file numeri.txt (su Moodle) e uno Stack istanziare un obj Pila1 che legga un numero e lo inserisca correttamente col metodo di inserction sort.
visualizzare la Pila1.
es: 3 5 67 41 12 8
[3, 5, 8, 12, 41, 67]
 */
import java.io.*;
import java.util.Stack;
public class PilaSort {
    public static void main(String[] args) {
        Stack<Integer> pila1 = new Stack<Integer>();
        Stack<Integer> pila2 = new Stack<Integer>();
        try {
            //read file
            FileReader fr = new FileReader("numeri.txt");
            BufferedReader br = new BufferedReader(fr);
            String line = ""; 
            int n=0;
            int tmp=0;

            pila1.push(Integer.parseInt(br.readLine()));
            line = br.readLine();

            while (line != null) {
                System.out.println("pila1" + pila1);
                n = Integer.parseInt(line);
                
                tmp = pila1.pop();

                if (n > tmp) {
                    while (!pila1.empty() && n > tmp) {
                        pila2.push(tmp);
                        tmp = pila1.pop();
                    }
                    if (n > tmp) {
                        pila1.push(n);
                        pila1.push(tmp);
                    }else{
                        pila1.push(tmp);
                        pila1.push(n);
                    }

                    while (!pila2.empty()) {
                        pila1.push(pila2.pop());
                    }     
                }else{
                    pila1.push(tmp);
                    pila1.push(n);
                }

                line = br.readLine();
            }
            System.out.println(pila1);
            br.close();
        } catch (IOException e) {
            System.out.println("Errore di I/O");
        }
    }
    
}