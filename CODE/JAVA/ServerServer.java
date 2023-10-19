import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.*;
import java.util.*;

public class ServerServer {
    public static void main(String[] args) {
        final int PORT = 5862;
        Socket ClientSocket;
        ServerSocket ServerSocket;
        PrintWriter ClientStreamOut;
        Scanner scn = new Scanner(System.in);

        System.out.println("Server started ...");

        try {
            ServerSocket = new ServerSocket(PORT);
            
            ClientSocket = ServerSocket.accept();
            System.out.println("Client connected !");
            
            String txt = "Server connected !";
            ClientStreamOut = new PrintWriter(ClientSocket.getOutputStream());
            ClientStreamOut.println(txt);

            while (txt != "exit") {
                System.out.println("Text: ");
                txt = scn.nextLine();
                ClientStreamOut.println(txt);
            }

            scn.close();
            ClientSocket.close();
        } catch (Exception e) {
            System.out.println("Errore Server");
        }

    }
}
