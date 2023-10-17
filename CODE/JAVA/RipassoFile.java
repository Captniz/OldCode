import java.io.IOException;
import java.io.FileReader;
import java.io.FileWriter;

public class RipassoFile {

    public static void main(String[] args) {
        try {
            FileWriter output = new FileWriter("output.txt");
            FileReader input = new FileReader("input.txt");
            char c = (char) input.read();
            while (c != (char) -1) {
                c = (char) input.read();
                output.write(c);
            }
            input.close();
            output.close();
        } catch (IOException e) {
            System.out.println("File non trovato");
        }
    }
}