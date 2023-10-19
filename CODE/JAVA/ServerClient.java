import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.*;
import java.util.*;

public class ServerClient {
    
    public static void main(String[] args) {
        final String IP = "127.0.0.1";
        final int PORT = 5862;
        Socket ServerSocket;
        BufferedReader ServerStreamIn;
        
        System.out.println("Client connecting ...");

        try {
            ServerSocket = new Socket(IP, PORT);
            ServerStreamIn = new BufferedReader(new InputStreamReader(ServerSocket.getInputStream()));

            String txt = ServerStreamIn.readLine();
            while (txt != "exit") {
                System.out.println(txt);
                txt = ServerStreamIn.readLine();
            }

            System.out.println("Client disconnected !");
        } catch (Exception e) {
            System.out.println("Errore Server");
        }
    }
}
