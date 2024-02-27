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
            System.out.println("Server started . . .");

            // Accept and manage clients
            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Client connected");

                clients.add(new ClientManager(clientSocket));
                // TODO: start client manager
                //TODO: PER INFO CONTROLLA CHATGPT 26/02
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * Removes a client from the list of active clients in the streaming service.
     * 
     * @param name <code>String<code/> containing the name of the client to be removed
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
     * @param nomeNodo <code>String<code/> containing the name of the node to be searched
     * @return <code>ArrayList<Node><code/> containing all the nodes with the given name
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
     * Returns all the ELEMENT nodes that are children of the given node.
     * 
     * @param nodo <code>Node<code/> containing the node to be searched
     * @return <code>ArrayList<Node><code/> containing all the children of the given node
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
     * @return <code>ArrayList &lt ArrayList &lt String &gt &gt<code/> containing in each row a group and
     *         each column one of the pieces of data : <code>[ name , followers , imgPath ]<code/>
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
     * Returns data like name, followers and the image path for a stream in the
     * streaming service.
     * 
     * @return <code>ArrayList &lt ArrayList &lt String &gt &gt<code/> containing in each row a stream and
     *         each column one of the pieces of data : <code>[ name , content , followers , language ,  , imgPath ]<code/>
     */
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
        
        try {
            for (;;) {
                req = in.readLine();

                switch (req) {
                    case "#EXIT":
                        killClient();
                        return;

                    case "#LIST GROUP":
                        /*
                         * [0] = name / [1] = followers / [2] = imgPath
                         * 
                         * Send data in the format "name;followers" followed by another line with the
                         * image data
                         */
                        ArrayList<ArrayList<String>> dati = xml.getGroupData();

                        for (ArrayList<String> a : dati) {
                            out.println(a.get(0) + ";" + a.get(1));
                            sendImage(a.get(2));
                        }
                        break;

                    case "#LIST STREAM":
                        //TODO: implementare
                        break;

                    case "#SHOW STREAM":
                        //TODO: implementare o delegare a client/webserver
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
     * @param path <code>String<code/> containing the path of the image to be sent
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
     * Kills the client and removes it from the list of active clients in the streaming service.
     * Calls the <code>clearClients<code/> method in <code>ProgettoServerXML<code/>.
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
}

class WindowManager {
    MyWindow window;

    WindowManager() {
        window = new MyWindow();
    }

}

class MyWindow extends javax.swing.JFrame {
    public MyWindow() {
        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Server");
        setResizable(false);
        setSize(new java.awt.Dimension(400, 300));
        setVisible(true);
    }
}