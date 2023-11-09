import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.net.*;
import java.util.*;

public class ServerServer {
    public static void main(String[] args) {
        final int PORT = 5862;
        ServerSocket ServerSocket;
        ArrayList<BufferedReader> clientIns;
        ArrayList<PrintWriter> clientOuts;

        System.out.println("Server started ...");

        try {
            // Server port setup
            ServerSocket = new ServerSocket(PORT);

            // Run Manager thread
            Manager manager = new Manager(ServerSocket);
            manager.start();

            clientIns = manager.getClientIns();
            clientOuts = manager.getClientOuts();
            for (;;) {
                while (clientIns.isEmpty() || clientOuts.isEmpty()) {
                    clientIns = manager.getClientIns();
                    clientOuts = manager.getClientOuts();
                }
                clientIns.forEach((in) -> manager.ReadAndSendMsg(in));
            }
        } catch (Exception e) {
            System.out.println("Errore Server");
            e.printStackTrace();
        }
        // TODO:
        // EXIT
        // NOME CLIENT
        // FOREACH SU LISTE è OK?
        // DUPLICAZIONE MSG
    }
}

class Manager extends Thread {
    ServerSocket serverSocket;
    ArrayList<PrintWriter> clientOuts = new ArrayList<PrintWriter>();
    ArrayList<BufferedReader> clientIns = new ArrayList<BufferedReader>();

    Manager(ServerSocket serverSocket) {
        this.serverSocket = serverSocket;
    }

    @Override
    public void run() {
        for (;;) {
            try {
                Socket clientSocket = serverSocket.accept();
                PrintWriter clientStreamOut = new PrintWriter(clientSocket.getOutputStream(), true);
                BufferedReader clientStreamIn = new BufferedReader(
                        new InputStreamReader(clientSocket.getInputStream()));

                clientOuts.add(clientStreamOut);
                clientIns.add(clientStreamIn);

                String name = clientStreamIn.readLine();

                System.out.println("{[[" + name + " connected !]]}");
                for (PrintWriter out : clientOuts) {
                    out.println("{[[" + name + " connected !]]}");
                }

            } catch (Exception e) {
                System.out.println("Errore Server");
            }
        }
    }

    public ArrayList<BufferedReader> getClientIns() {
        return clientIns;
    }

    public ArrayList<PrintWriter> getClientOuts() {
        return clientOuts;
    }

    public void ReadAndSendMsg(BufferedReader in) {
        try {
            String txt = in.readLine();
            System.out.println(txt);
            clientOuts.forEach((out) -> out.println(txt));
        } catch (Exception e) {
            System.out.println("Error fetching msgs");
            e.printStackTrace();
        }
    }
}