import java.net.*;
import java.util.*;

public class ServerClient {
    public static void main(String[] args) {
        try {
            Socket sock = new Socket("127.0.0.1", 5862);

            Scanner scan = new Scanner(sock.getInputStream());

            while (scan.hasNextLine() && scan.nextLine() != "exit") {
                System.out.println(scan.nextLine());
            }
        } catch (Exception e) {
            System.out.println("Errore Server");
        }

    }
}
