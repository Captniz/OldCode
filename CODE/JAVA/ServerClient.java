import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;
import java.net.*;

public class ServerClient {

    public static void main(String[] args) {
        final String IP = "127.0.0.1";
        final int PORT = 5862;
        Socket serverSocket;
        PrintWriter serverStreamOut;
        BufferedReader serverStreamIn;
        Scanner scn = new Scanner(System.in);

        try {
            System.out.println("Nome:");
            String txt = scn.nextLine();

            serverSocket = new Socket(IP, PORT);
            serverStreamOut = new PrintWriter(serverSocket.getOutputStream(), true);
            serverStreamIn = new BufferedReader(new InputStreamReader(serverSocket.getInputStream()));
            System.out.println("Client connecting ...");

            MsgReciever msg = new MsgReciever(serverStreamIn);
            msg.start();

            serverStreamOut.println(txt);

            for (;;) {
                txt = scn.nextLine();
                serverStreamOut.println(txt);
                if (txt.equals("exit")) {
                    System.out.println("{[[disconnected !]]}");
                    serverSocket.close();
                    serverStreamIn.close();
                    serverStreamOut.close();
                    return;
                }
            }

        } catch (Exception e) {
            System.out.println("Errore Server");
            return;
        }
    }
}

class MsgReciever extends Thread {
    BufferedReader serverStreamIn;

    MsgReciever(BufferedReader serverStreamIn) {
        this.serverStreamIn = serverStreamIn;
    }

    @Override
    public void run() {
        String txt;
        for (;;) {
            try {
                txt = serverStreamIn.readLine();
                System.out.println(txt);
            } catch (Exception e) {
                System.out.println("Errore Server");
                return;
            }
        }
    }
}