package Sockets;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.net.*;
import java.util.*;

public class ServerServer {
    public static void main(String[] args) {
        final int PORT = 5862;
        ServerSocket ServerSocket;

        System.out.println("Server started ...");

        try {
            // Server port setup
            ServerSocket = new ServerSocket(PORT);

            // Run Manager thread
            Manager manager = new Manager(ServerSocket);
            manager.start();

            for (;;) {
                manager.ReadAndSendMsg();
            }
        } catch (Exception e) {
            System.out.println("Errore Server");
            e.printStackTrace();
        }
        // TODO:
        // EXIT
    }
}

class Manager extends Thread {
    ServerSocket serverSocket;
    ArrayList<Dictionary<String, Object>> clientsList;

    Manager(ServerSocket serverSocket) {
        this.serverSocket = serverSocket;
        this.clientsList = new ArrayList<Dictionary<String, Object>>();
    }

    @Override
    public void run() {
        for (;;) {
            try {
                Socket clientSocket = serverSocket.accept();
                PrintWriter clientStreamOut = new PrintWriter(clientSocket.getOutputStream(), true);
                BufferedReader clientStreamIn = new BufferedReader(
                        new InputStreamReader(clientSocket.getInputStream()));
                String name = clientStreamIn.readLine();

                Dictionary<String, Object> client = new Hashtable<String, Object>();
                client.put("name", name);
                client.put("socket", clientSocket);
                client.put("out", clientStreamOut);
                client.put("in", clientStreamIn);

                clientsList.add(client);

                System.out.println("{[[" + name + " connected !]]}");
                clientsList.forEach((c) -> {
                    PrintWriter pw = (PrintWriter) c.get("out");
                    pw.println("{[[" + name + " connected !]]}");

                });

            } catch (Exception e) {
                System.out.println("Errore Server");
            }
        }

    }

    public void ReadAndSendMsg() {
        ArrayList<Dictionary<String, Object>> clientsListCopy = new ArrayList<>(this.clientsList);

        clientsListCopy.forEach(client -> {
            try {
                BufferedReader in = (BufferedReader) client.get("in");
                PrintWriter out = (PrintWriter) client.get("out");
                String name = (String) client.get("name");
                Socket s = (Socket) client.get("socket");
                String txt = "";

                if (in.ready()) {
                    txt = in.readLine();
                    if (txt.equals("exit")) {
                        txt = "{[[" + name + " disconnected !]]}";
                        s.close();
                        in.close();
                        out.close();

                        this.clientsList.remove(client);
                    } else {
                        txt = ("[" + name + "]: " + txt);
                    }
                    System.out.println(txt);

                    final String ftxt = txt;
                    clientsListCopy.forEach((c) -> {
                        if ((String) c.get("name") != name) {
                            PrintWriter pw = (PrintWriter) c.get("out");
                            pw.println(ftxt);
                            pw.flush();
                        }
                    });
                }
            } catch (Exception e) {
                System.out.println("Error fetching msgs");
                e.printStackTrace();
            }
        });
    }
}