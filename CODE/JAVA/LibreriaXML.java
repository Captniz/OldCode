import java.io.File;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import org.w3c.dom.*;

public class LibreriaXML {
    public static void main(String[] args) {
        try {
            File file = new File("../XML/Catalogo_libri.xml");

            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = factory.newDocumentBuilder();
            Document document = builder.parse(file);

            // 1
            Element rootElement = document.getDocumentElement();
            System.out.println("Elemento radice: " + rootElement.getNodeName());

            // 2
            NodeList l = document.getElementsByTagName("libro");
            System.out.println("\nNumero di libri: " + l.getLength());

            // 3
            for (int i = 0; i < l.getLength(); i++) {
                System.out.println("\nLibro " + (i + 1) + ":");
                System.out.println("Titolo: " + l.item(i).getChildNodes().item(1).getTextContent());
                System.out.println("Autore: " + l.item(i).getChildNodes().item(3).getTextContent());
            }

            // 4
            System.out.println("\n\nLibri di Fantasy:\n");
            String genere = "Fantasy";
            for (int i = 0; i < l.getLength(); i++) {
                if (l.item(i).getChildNodes().item(5).getTextContent().equals(genere)) {
                    System.out.println("Libro " + (i + 1) + ":");
                    System.out.println("Titolo: " + l.item(i).getChildNodes().item(1).getTextContent());
                    System.out.println("Autore: " + l.item(i).getChildNodes().item(3).getTextContent());
                }
            }

            // 5
            System.out.println("\n\nGeneri:\n");
            RicRic(l, "genere");

            // 6
            System.out.println("Nodi:");
            NodeList lc = document.getDocumentElement().getChildNodes();
            for (int i = 0; i < lc.getLength(); i++) {
                if (lc.item(i).getNodeName().equals("#comment")) {
                    System.out.print(lc.item(i).getTextContent());
                }
            }
            // 7
            System.out.println("\n\nLibro piu nuovo:\n");
            int min = 0;
            Node libromin = l.item(0);
            for (int i = 0; i < l.getLength(); i++) {
                if (Integer.parseInt(l.item(i).getChildNodes().item(7).getTextContent()) > min) {
                    min = Integer.parseInt(l.item(i).getChildNodes().item(7).getTextContent());
                    libromin = l.item(i);
                }
            }
            System.out.println("Titolo: " + libromin.getChildNodes().item(1).getTextContent());
            System.out.println("Data: " + libromin.getChildNodes().item(7).getTextContent());

            // END
            file = null;

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void RicRic(NodeList l, String tit) {
        for (int i = 0; i < l.getLength(); i++) {
            if (l.item(i).getNodeName().equals(tit)) {
                System.out.println("Nodo trovato: " + l.item(i).getTextContent());
            }
            if (l.getLength() == 0) {
                return;
            }
            RicRic(l.item(i).getChildNodes(), tit);
        }
    }
}