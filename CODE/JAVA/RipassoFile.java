import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class RipassoFile {

    public static void main(String[] args) {
        try {
            FileWriter output = new FileWriter("output.txt");
            FileReader input = new FileReader("input.txt");
            BufferedReader in = new BufferedReader(input);
            BufferedWriter out = new BufferedWriter(output);
            char c = (char) input.read();
            String num = "0";
            int sum = 0;
            while (c != (char) -1) {
                c = (char) input.read();
                try {
                    Integer.parseInt(String.valueOf(c));
                    num += c;
                } catch (Exception e) {
                    if (num != "") {
                        sum += Integer.parseInt(String.valueOf(num));
                        num = "";
                    }
                }
            }
            output.write(String.valueOf(sum));
            input.close();
            output.close();
        } catch (IOException e) {
            System.out.println("File non trovato");
        }
    }
}