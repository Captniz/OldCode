import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.io.*;

public class zTest {

    public static void main(String[] args) {
        String tmp = "";
        try {
            BufferedReader cin = new BufferedReader(new FileReader("input.txt"));
            try {
                tmp = cin.readLine();
                System.out.println(Integer.parseInt(tmp));

                tmp = cin.readLine();
                while (tmp != null) {
                    System.out.println(Integer.parseInt(tmp));
                    tmp = cin.readLine();
                }

            } catch (Exception e) {
                System.out.println("Il file è vuoto");
            }
        } catch (Exception e) {
            System.out.println("Non c'è il file ");
        }
    }
}