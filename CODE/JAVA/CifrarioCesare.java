import java.util.*;
import java.io.*;

public class CifrarioCesare {

    public static void main(String[] args) {
        try {
            System.out.println("Inserisci la chiave di cifratura:");
            Scanner sc = new Scanner(System.in);
            int key = sc.nextInt();

            int ch = 0;
            char character = ' ';
            FileReader fileReader = new FileReader("input.txt");
            FileWriter fileWriter = new FileWriter("output.txt");

            while ((ch = fileReader.read()) != -1) {
                character = (char) ch;
                character = Character.toLowerCase(character);
                ch = (int) character;
                if (character >= 'a' && character <= 'z') {
                    ch = ((ch - 97 + key) % 26) + 97;
                }
                character = (char) ch;
                fileWriter.write(character);
            }
            fileReader.close();
            fileWriter.close();
            sc.close();
        } catch (FileNotFoundException e) {
            System.out.println("File non trovato");
        } catch (IOException e) {
            System.out.println("Errore durante la lettura del file");
        }
    }
}
