package Sockets.XmlServer;

import java.io.*;
import java.util.*;
import java.net.*;
import javax.xml.parsers.*;
import org.w3c.dom.*;
import org.xml.sax.*;

//Servizio streaming
public class ProgettoServerXML {
    static final int PORT = 5566;
    public static ArrayList<ClientManager> clients = new ArrayList<ClientManager>();

    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(PORT);

            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Client connected");

                clients.add(new ClientManager(clientSocket));
                // TODO: start client manager
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void clearClients(String name) {
        for (ClientManager c : clients) {
            if (c.getName().equals(name)) {
                clients.remove(c);
                break;
            }
        }
    }
}

class XMLmanager {
    DocumentBuilder db;
    Document doc;
    File file;

    public Node root;

    XMLmanager(String nomeFile) throws Exception {
        file = new File(nomeFile);
        db = DocumentBuilderFactory.newInstance().newDocumentBuilder();
        doc = db.parse(file);

        root = doc.getDocumentElement();
    }

    ArrayList<Node> findNodes(String nomeNodo) {
        NodeList l = doc.getElementsByTagName(nomeNodo);
        ArrayList<Node> nodes = new ArrayList<Node>();

        for (int i = 0; i < l.getLength(); i++) {
            if (l.item(i).getNodeType() == Node.ELEMENT_NODE) {
                nodes.add(l.item(i));
            }
        }

        return nodes;
    }

    ArrayList<Node> findChildNodes(Node nodo) {
        NodeList l = nodo.getChildNodes();
        ArrayList<Node> nodes = new ArrayList<Node>();

        for (int i = 0; i < l.getLength(); i++) {
            if (l.item(i).getNodeType() == Node.ELEMENT_NODE) {
                nodes.add(l.item(i));
            }
        }

        return nodes;
    }

    ArrayList<ArrayList<String>> getGroupData() {
        /**
         * Returns data like name and followers, as well as the image path for a group
         * in the streaming service.
         * 
         * [0] = name / [1] = imgPath / [2] = followers
         * 
         * @return data ArrayList<ArrayList<String>> containing in each row a group and
         *         each column one of the pieaces of data
         */

        ArrayList<Node> gruppi = findNodes("group");
        ArrayList<ArrayList<String>> dati = new ArrayList<ArrayList<String>>();
        ArrayList<Node> tmp2;
        NamedNodeMap attr;

        ArrayList<String> tmp;

        for (Node n : gruppi) {
            tmp = new ArrayList<String>();

            attr = n.getAttributes();
            tmp.add(attr.item(0).getNodeValue());

            tmp2 = findChildNodes(n);
            tmp.add(tmp2.get(0).getTextContent());
            tmp.add(tmp2.get(1).getTextContent());

            dati.add(tmp);
        }

        return dati;
    }
}

class ClientManager extends Thread {
    Socket clientSocket;
    PrintWriter out;
    BufferedReader in;
    XMLmanager xml;

    ClientManager(Socket clientSocket) {
        try {
            this.clientSocket = clientSocket;
            out = new PrintWriter(clientSocket.getOutputStream(), true);
            in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            xml = new XMLmanager("Streamers.xml");
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    @Override
    public void run() {
        try {
            String req;

            for (;;) {
                req = in.readLine();

                switch (req) {
                    case "#EXIT":
                        killClient();
                        return;

                    case "#LIST GROUP":
                        ArrayList<ArrayList<String>> dati = xml.getGroupData();

                        break;

                    case "#LIST STREAM":
                        break;

                    case "#SHOW STREAM":
                        break;
                    default:
                        break;
                }

                // TODO: implementare le funzioni + finisci xml
            }
        } catch (Exception e) {
            System.out.println("Errore ClientManager");
            e.printStackTrace();
            killClient();
            return;
        }
    }

    void killClient() {
        try {
            clientSocket.close();
            out.close();
            in.close();
            ProgettoServerXML.clearClients(this.getName());
        } catch (IOException e) {
            e.printStackTrace();
        }
        return;
    }
}