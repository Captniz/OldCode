import java.io.FileReader;
import java.io.FileWriter;

public class Vigenere {
    public static void main(String[] args) {
        try {
            String key = "VERME".toLowerCase();
            String message = "";
            String criptedMsg = "";

            FileWriter fileWriter = new FileWriter("output.txt");
            FileReader fileReader = new FileReader("input.txt");

            int ch;
            while ((ch = fileReader.read()) != -1) {
                message += (char) ch;
            }
            message = message.toLowerCase();

            int c = 0;
            for (int i = 0; i < message.length(); i++) {
                if (message.charAt(i) >= 97 && message.charAt(i) <= 122) {
                    c = ((int) message.charAt(i) - 97) + ((int) key.charAt(i % key.length()) - 97);
                    criptedMsg += (char) (97 + (c % 26));
                }else{
                    criptedMsg += message.charAt(i);
                }
            }

            fileWriter.write(criptedMsg);
            fileWriter.close();
            fileReader.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
