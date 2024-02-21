import java.io.*;
import java.util.*;
import java.net.*;
import javax.swing.*;
import java.awt.*;
import javax.xml.parsers.*;
import org.w3c.dom.*;
import org.xml.sax.*;

public class ProgettoServerXML {
    public static void main(String[] args) {
        try {
            XMLmanager xml = new XMLmanager("pass");


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

    XMLmanager( String nomeFile ) throws Exception {
        file = new File(nomeFile);
        db = DocumentBuilderFactory.newInstance().newDocumentBuilder();
        doc = db.parse(file);

        root = doc.getDocumentElement();
    }

    ArrayList<Node> findNodes( String nomeNodo ) {
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
