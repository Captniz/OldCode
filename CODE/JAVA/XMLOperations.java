import java.io.File;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import org.w3c.dom.*;
import java.util.ArrayList;
import java.util.List;


public class XMLOperations {
    public static void main(String[] args) {
        GetNodeAttr("fermata");
    }

    static void FatherNode(){
        try {
            // Apri il file XML
            File file = new File("../XML/trasporti.xml");

            // Crea un oggetto DocumentBuilder
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = factory.newDocumentBuilder();

            // Parsa il file XML e ottieni il documento
            Document document = builder.parse(file);

            // Ottieni l'elemento radice
            Element rootElement = document.getDocumentElement();

            // Stampa il nome dell'elemento radice
            System.out.println("Elemento radice: " + rootElement.getNodeName());
            file = null;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    static void ChildNodes(){
        try {
            // Apri il file XML
            File file = new File("../XML/trasporti.xml");

            // Crea un oggetto DocumentBuilder
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = factory.newDocumentBuilder();

            // Parsa il file XML e ottieni il documento
            Document document = builder.parse(file);

            // Ottieni l'elemento radice
            Element rootElement = document.getDocumentElement();

            // Ottieni la lista dei figli diretti dell'elemento radice
            NodeList childNodes = rootElement.getChildNodes();

            // Stampa il numero di elementi figli diretti dell'elemento radice
            System.out.println("Numero di elementi figli dell'elemento radice: " + childNodes.getLength());

            file = null;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void ChildNodesName(){
        try {
            // Apri il file XML
            File file = new File("../XML/trasporti.xml");

            // Crea un oggetto DocumentBuilder
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = factory.newDocumentBuilder();

            // Parsa il file XML e ottieni il documento
            Document document = builder.parse(file);

            // Ottieni l'elemento radice
            Element rootElement = document.getDocumentElement();

            // Ottieni la lista dei figli diretti dell'elemento radice
            NodeList childNodes = rootElement.getChildNodes();

            // Stampa i nomi dei nodi figli diretti dell'elemento radice
            for (int i = 0; i < childNodes.getLength(); i++) {
                if (childNodes.item(i).getNodeType() == Node.ELEMENT_NODE) {
                    Element childElement = (Element) childNodes.item(i);
                    System.out.println("Nome del nodo figlio diretto: " + childElement.getNodeName());
                }
            }

            file = null;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void FindNode(String elementName){
        try {
            // Apri il file XML
            File file = new File("../XML/trasporti.xml");

            // Crea un oggetto DocumentBuilder
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = factory.newDocumentBuilder();

            // Parsa il file XML e ottieni il documento
            Document document = builder.parse(file);

            // Trova il primo elemento con il nome specificato
            NodeList nodeList = document.getElementsByTagName(elementName);
            if (nodeList.getLength() > 0) {
                Node firstElement = nodeList.item(0);
                String textContent = firstElement.getTextContent();
                System.out.println("Contenuto del primo elemento '" + elementName + "': " + textContent);
            } else {
                System.out.println("Nessun elemento con il nome '" + elementName + "' trovato.");
            }

            file = null;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void GetNodeAttr(String elementName){
        try{
            // Apri il file XML
            File file = new File("../XML/trasporti.xml");

            // Crea un oggetto DocumentBuilder
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = factory.newDocumentBuilder();

            // Parsa il file XML e ottieni il documento
            Document document = builder.parse(file);

            // Trova il primo elemento con il nome specificato
            NodeList nodeList = document.getElementsByTagName(elementName);
            String attrStringList="";
            
            if (nodeList.getLength() > 0) {
                Node firstElement = nodeList.item(0);
                NamedNodeMap attrs = firstElement.getAttributes();
                String attrString = "";
                
                for (int i = 0; i < attrs.getLength(); i++) {
                    Node attr = attrs.item(i);
                    String attrName = attr.getNodeName();
                    String attrValue = attr.getNodeValue();
                    attrString += attrName + "=\"" + attrValue + "\", ";
                }
                
                System.out.println("Attributi del primo elemento: " +attrString);
            }

            file = null;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}