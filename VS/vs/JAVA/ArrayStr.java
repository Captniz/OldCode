import java.util.Scanner;

/*7>221201_arraystr.java
Scrivere un programma ArrayStringhe che chiede all'utente di inserire una stringa.
La stringa andrà a caricare una array di stringhe con right push la cui dimensione è la lunghezza della stringa:
es: Marco
Marco
arcoM
rcoMa
coMar
oMarc

nel main prevedere un metodo statico per visualizzare l'array.

- (più complesso) si potrebbe anche creare una classe Stringa(), una classe Stringhe() che permetta di istanziare l stringhe di lunghezza l (che contenga almeno un costruttore  e un metodo per visualizzare l'array) e una classe MainStringhe() che permetta di creare un paio di oggetti Stringhe e visualizzarle.*/
//221201_arraystr.java
import java.util.Scanner;
public class ArrayStr {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String str = "";
        String[] array;

        System.out.print("Inserisci una stringa: ");
        str = scn.nextLine();
        array = new String[str.length()];
        array[0] = str;
        for (int i = 1; i < array.length; i++) {
            //str = ciao
            // array[i] = iao + c 
            array[i] = array[i-1].substring(1) + array[i-1].charAt(0);
        }
        for (int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }

        scn.close();
    }
}
