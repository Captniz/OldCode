import java.net.*;
import java.util.*;

public class ServerServer {
    public static void main(String[] args) {
        try {
            ServerSocket s = new ServerSocket(5862);
            Scanner scn = new Scanner(System.in);
            Socket sock = s.accept();

            String txt = "Connesso";
            sock.getOutputStream().write(txt.getBytes());
            while (txt != "exit") {
                txt = scn.nextLine();
                sock.getOutputStream().write(txt.getBytes());
            }
            scn.close();
            s.close();
        } catch (Exception e) {
            System.out.println("Errore Server");
        }

    }
}
