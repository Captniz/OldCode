package Sockets.XmlServer;

import java.io.*;
import java.util.*;
import java.net.*;

import javax.xml.parsers.*;
import org.w3c.dom.*;

/**
 * Server for a streaming service. It manages the clients and the data they
 * request.
 */
public class ProgettoServerXML {

    // Static & Global variables
    static final int PORT = 5566;
    public static ArrayList<ClientManager> clients = new ArrayList<ClientManager>();

    public static void main(String[] args) {
        try {
            // Create server socket
            ServerSocket serverSocket = new ServerSocket(PORT);
            Socket clientSocket;
            ClientManager clientmanager;
            System.out.println("Server started . . .");

            // Accept and manage clients
            while (true) {
                clientSocket = serverSocket.accept();
                clientmanager = new ClientManager(clientSocket);
                System.out.println("Client connected");

                clients.add(clientmanager);
                clientmanager.start();
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * Removes a client from the list of active clients in the streaming service.
     * 
     * @param name <code>String</code> containing the name of the client to be
     *             removed
     */
    public static void clearClients(String name) {

        for (ClientManager c : clients) {
            if (c.getName().equals(name)) {
                clients.remove(c);
                break;
            }
        }
    }
}

/**
 * Manages the XML file containing the data for the streaming service.
 */
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

    /**
     * Returns all the ELEMENT nodes with the given name in the XML file.
     * 
     * @param nomeNodo <code>String</code> containing the name of the node to be
     *                 searched
     * @return <code>ArrayList<Node></code> containing all the nodes with the given
     *         name
     */
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

    /**
     * Returns the first ELEMENT node with the given name that is a child of the
     * given node.
     * 
     * @param nodo     <code>Node</code> containing the node to be searched
     * @param nomeNodo <code>String</code> containing the name of the node to be
     *                 searched
     * @return <code>Node</code> containing the first node with the given name that
     *         is a child of the given node
     */
    Node findChildNode(Node nodo, String nomeNodo) {
        NodeList l = nodo.getChildNodes();
        Node n = null;

        for (int i = 0; i < l.getLength(); i++) {
            if (l.item(i).getNodeType() == Node.ELEMENT_NODE && l.item(i).getNodeName().equals(nomeNodo)) {
                n = l.item(i);
                break;
            }
        }

        return n;
    }

    /**
     * Returns all the ELEMENT nodes that are children of the given node.
     * 
     * @param nodo <code>Node</code> containing the node to be searched
     * @return <code>ArrayList<Node></code> containing all the children of the given
     *         node
     */
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

    /**
     * Returns data like name and followers, as well as the image path for a group
     * in the streaming service.
     * 
     * @return <code>ArrayList &lt ArrayList &lt String &gt &gt</code> containing in
     *         each row a group and
     *         each column one of the pieces of data : <code>[ name , followers ,
     *         imgPath ]</code>
     */
    ArrayList<ArrayList<String>> getGroupData() {

        ArrayList<Node> gruppi = findNodes("group");
        ArrayList<ArrayList<String>> dati = new ArrayList<ArrayList<String>>();
        ArrayList<Node> tmp2;
        NamedNodeMap attr;

        ArrayList<String> tmp;

        for (Node n : gruppi) {
            tmp = new ArrayList<String>();

            attr = n.getAttributes();
            tmp.add(attr.item(2).getNodeValue());

            tmp2 = findChildNodes(n);
            tmp.add(tmp2.get(1).getTextContent());
            tmp.add(tmp2.get(0).getTextContent());

            dati.add(tmp);
        }

        return dati;
    }

    /**
     * Returns a list of all the streams in a given group.
     * 
     * @param groupName <code>String</code> containing the name of the group to be
     *                  searched
     * @return <code>ArrayList &lt String &gt</code> containing the names of the
     *         streams in the given group
     */
    ArrayList<String> getStreams(String groupName) {
        ArrayList<Node> gruppi = findNodes("group");
        ArrayList<Node> streams;
        ArrayList<String> dati = new ArrayList<String>();

        for (Node n : gruppi) {
            if (n.getAttributes().item(2).getNodeValue().equals(groupName)) {
                streams = findChildNodes(n);
                for (Node s : streams) {
                    dati.add(findChildNode(s, "name").getTextContent());
                }
                break;
            }
        }
        return dati;
    }

    /**
     * Returns the data for a given stream in a given group.
     * 
     * @param groupName  <code>String</code> containing the name of the group to be
     *                   searched
     * @param streamName <code>String</code> containing the name of the stream to be
     *                   searched
     * @return <code>ArrayList &lt String &gt</code> containing the data for the
     *         given stream in the given group : <code>[ name , content , followers
     *         , language , streamPath , imagePath ]</code>
     */
    ArrayList<String> getStreamData(String groupName, String streamName) {
        ArrayList<Node> gruppi = findNodes("group");
        ArrayList<Node> streams;
        ArrayList<String> dati = new ArrayList<String>();

        for (Node n : gruppi) {
            if (n.getAttributes().item(2).getNodeValue().equals(groupName)) {
                streams = findChildNodes(n);
                for (Node s : streams) {
                    if (findChildNode(s, "name").getTextContent().equals(streamName)) {
                        dati = new ArrayList<String>();
                        dati.add(findChildNode(s, "name").getTextContent());
                        dati.add(findChildNode(s, "content").getTextContent());
                        dati.add(findChildNode(s, "followers").getTextContent());
                        dati.add(findChildNode(s, "language").getTextContent());
                        dati.add(findChildNode(findChildNode(s, "metadata"), "streamPath").getTextContent());
                        dati.add(findChildNode(findChildNode(s, "metadata"), "imagePath").getTextContent());
                        break;
                    }
                }
                break;
            }
        }
        return dati;
    }
}

/**
 * Manages the clients connected to the server.
 */
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
        String req;
        String tmp;

        try {
            for (;;) {
                req = in.readLine();

                switch (req) {
                    case "#EXIT":
                        killClient();
                        return;

                    case "#LIST GROUP":
                        ArrayList<ArrayList<String>> dati = xml.getGroupData();

                        for (ArrayList<String> s : dati) {
                            tmp = s.get(0) + " " + s.get(1);
                            out.println(tmp);
                        }

                        tmp="";

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

    /**
     * Sends an image to the client.
     * 
     * @param path <code>String</code> containing the path of the image to be sent
     */
    void sendImage(String path) {
        try {
            File file = new File(path);
            FileInputStream fis = new FileInputStream(file);
            byte[] data = new byte[(int) file.length()];
            fis.read(data);
            fis.close();

            out.println(data);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * Kills the client and removes it from the list of active clients in the
     * streaming service.
     * Calls the <code>clearClients</code> method in <code>ProgettoServerXML</code>.
     */
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

    /**
     * Returns the data relative to the request made by the client.
     * 
     * @return <code>String</code> containing the data of the request
     */
    String[] getRequestData(String req) {
        String[] tmp = req.split(" ");
        String[] data = new String[tmp.length - 2];
        for (int i = 2; i < tmp.length; i++) {
            data[i - 2] = tmp[i];
        }

        return data;
    }
}