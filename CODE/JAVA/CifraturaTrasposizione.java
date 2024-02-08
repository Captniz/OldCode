import java.io.FileReader;
import java.io.FileWriter;

public class CifraturaTrasposizione {
    public static void main(String[] args) {
        try {
            String key = "CIFRA".toLowerCase();
            String message = "";
            String criptedMsg = "";
            int maxlen;

            String singleString = "";

            FileWriter fileWriter = new FileWriter("output.txt");
            FileReader fileReader = new FileReader("input.txt");

            int ch;
            while ((ch = fileReader.read()) != -1) {
                message += (char) ch;
            }
            message = message.toLowerCase();

            maxlen = (int) Math.ceil((double) message.length() / key.length());

            for (int i = 0; i < key.length(); i++) {
                for (int j = i; singleString.length() < maxlen; j += key.length()) {
                    if (j >= message.length()) {
                        singleString += "*";
                    } else {
                        singleString += message.charAt(j);
                    }
                }
                criptedMsg += singleString;
                singleString = "";
            }

            String finalCrypted = "";
            for (int i = (int) 'a'; i <= (int) 'z'; i++) {
                for (int j = 0; j < key.length(); j++) {
                    if (key.charAt(j) == (char) i) {
                        finalCrypted += criptedMsg.substring((j * maxlen), (j * maxlen + maxlen));
                        break;
                    }
                }
            }

            fileWriter.write(finalCrypted);

            fileReader.close();
            fileWriter.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
