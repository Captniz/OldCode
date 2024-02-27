package Sockets.XmlServer;
import java.io.*;
import java.util.*;
import java.net.*;
import javax.swing.*;
import java.awt.*;
import javax.xml.parsers.*;
import org.w3c.dom.*;
import org.xml.sax.*;

public class ProgettoClientXML {
    //Playlist online + immagine e suono
    public static void main(String[] args) {
        try {
            //XMLmanager xml = new XMLmanager("pass");
            Window w = new Window("ProgettoServerXML");
            w.add(new Panel());
            

        } catch (Exception e) {
            e.printStackTrace();
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
}

class Window extends JFrame {
    public Window(String title) {
        super(title);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 300);
        setLocationRelativeTo(null);
        setVisible(true);
    }
}

class Panel extends JPanel {
    public Panel() {
        super();
        setBackground(Color.white);
    }

    public void paint(Graphics g) {
        super.paint(g);
        Graphics2D g2 = (Graphics2D) g;
        g2.setColor(Color.red);
        g2.drawLine(10, 10, 100, 100);
        g2.setColor(Color.blue);
        g2.drawRect(10, 10, 100, 100);
        g2.setColor(Color.green);
        g2.fillOval(10, 10, 100, 100);
    }
}