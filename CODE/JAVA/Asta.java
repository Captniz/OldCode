import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.net.*;
import java.util.*;

public class Asta {
    final static String IP = "127.0.0.1";
    final static int PORT = 5862;

    public static void main(String[] args) {
        Server server = new Server();
        Client client;
        server.start();

        for (int i = 0; i < 3; i++) {
            client = new Client();
            client.start();
        }
    }
}

class Client extends Thread {
    Socket clientSocket;
    PrintWriter clientStreamOut;
    BufferedReader clientStreamIn;
    int budget;
    int bias;

    public Client() {
        try {
            Random rand = new Random();

            clientSocket = new Socket(Asta.IP, Asta.PORT);
            clientStreamOut = new PrintWriter(clientSocket.getOutputStream(), true);
            clientStreamIn = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            this.budget = rand.nextInt(1000);
            this.bias = rand.nextInt(100);
        } catch (Exception e) {
            System.out.println("Errore Server");
            e.printStackTrace();
        }
    }

    @Override
    public void run() {
        System.out.println(this.getName() + " - Budget: " + budget);
        System.out.println(this.getName() + " - Bias: " + bias);
        for (;;) {
            try {
                String txt = clientStreamIn.readLine();
                if (txt.equals("ready")) {
                    clientStreamOut.println("offer");
                    txt = clientStreamIn.readLine();
                    int offer = Integer.parseInt(txt);
                    if (offer + bias < budget) {
                        clientStreamOut.println(offer + bias);
                        System.out.println(this.getName() + " - Offerto: " + (offer + bias));
                    } else {
                        clientStreamOut.println("exit");
                        System.out.println(this.getName() + " - Non posso offrire");
                        return;
                    }
                } else {
                    System.out.println(this.getName() + " - " + clientStreamIn.readLine());
                    return;
                }
            } catch (Exception e) {
                System.out.println("Errore Server");
                e.printStackTrace();
            }
        }
    }
}

class Server extends Thread {
    ServerSocket serverSocket;
    int offer;

    Server() {
        try {
            this.serverSocket = new ServerSocket(Asta.PORT);
            this.offer = 10;
        } catch (Exception e) {
            System.out.println("Errore Server");
            e.printStackTrace();
        }
    }

    @Override
    public void run() {
        try {
            serverConnectionManager manager = new serverConnectionManager(this.serverSocket);
            ArrayList<Dictionary<String, Object>> clientsListCopy;
            manager.start();

            while (manager.getClientLength() < 3) {
                System.out.println("Aspettando i client...");
                Thread.sleep(1000);
            }

            for (;;) {
                clientsListCopy = new ArrayList<>(manager.getClientsList());

                clientsListCopy.forEach(client -> {
                    try {
                        BufferedReader in = (BufferedReader) client.get("in");
                        PrintWriter out = (PrintWriter) client.get("out");
                        Socket s = (Socket) client.get("socket");
                        String txt = "";

                        if (manager.getClientLength() == 1) {
                            out.println("Hai vinto l'asta");
                            return;
                        } else {
                            out.println("ready");
                            Thread.sleep(400);
                        }

                        if (in.ready()) {
                            txt = in.readLine();
                            if (txt.equals("offer")) {
                                out.println(offer);
                                txt = in.readLine();
                                if (txt.equals("exit")) {
                                    s.close();
                                    in.close();
                                    out.close();
                                    manager.removeClient(client);
                                } else {
                                    offer = Integer.parseInt(txt);
                                }
                            }
                        }
                    } catch (Exception e) {
                        System.out.println("Error fetching msgs");
                        e.printStackTrace();
                    }
                });
            }
        } catch (Exception e) {
            System.out.println("Errore Server");
            e.printStackTrace();
        }
    }
}

class serverConnectionManager extends Thread {
    ArrayList<Dictionary<String, Object>> clientsList;
    ServerSocket serverSocket;

    serverConnectionManager(ServerSocket serverSocket) {
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

                Dictionary<String, Object> client = new Hashtable<String, Object>();
                client.put("socket", clientSocket);
                client.put("out", clientStreamOut);
                client.put("in", clientStreamIn);

                clientsList.add(client);

            } catch (Exception e) {
                System.out.println("Errore Server");
            }
        }
    }

    public ArrayList<Dictionary<String, Object>> getClientsList() {
        return clientsList;
    }

    public void removeClient(Dictionary<String, Object> client) {
        this.clientsList.remove(client);
    }

    public int getClientLength() {
        return this.clientsList.size();
    }
}