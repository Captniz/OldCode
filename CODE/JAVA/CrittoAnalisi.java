import java.util.*;
import java.io.*;
import java.math.*;

public class CrittoAnalisi {
    public static void main(String[] args) {
        try {
            int ctr = 0;

            // A E I O N
            float[] chars = new float[5];
            float[] ITA = { 11.79f, 11.74f, 11.28f, 9.83f, 6.88f };
            float[] ENG = { 12.31f, 9.59f, 8.05f, 7.94f, 7.19f };

            int ch =0;
            char character = ' ';
            FileReader fileReader = new FileReader("input.txt");

            while ((ch = fileReader.read()) != -1) {
                character=(char) ch;
                character = Character.toLowerCase(character);
                if (character >= 'a' && character <= 'z') {
                    switch (character) {
                        case 'a':
                            chars[0]++;
                            break;
                        case 'e':
                            chars[1]++;
                            break;
                        case 'i':
                            chars[2]++;
                            break;
                        case 'o':
                            chars[3]++;
                            break;
                        case 'n':
                            chars[4]++;
                            break;
                        default:
                            break;
                    }
                    ctr++;
                }
            }

            for (int i = 0; i < chars.length; i++) {
                chars[i] = (chars[i] / ctr) * 100f;
            }

            ctr = 0;
            for (int i = 0; i < chars.length; i++) {
                if (Math.abs(chars[i] - ITA[i]) < Math.abs(chars[i] - ENG[i]))
                    ctr++;
                else
                    ctr--;
            }

            if (ctr>0){
                System.out.println("Ita");
            }else{
                System.out.println("Eng");
            }

            fileReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("File non trovato");
        } catch (IOException e) {
            System.out.println("Errore durante la lettura del file");
        }
    }
}