import java.io.*;
import java.util.*;
import java.net.*;

import javax.xml.parsers.*;
import org.w3c.dom.*;

/**
 * Client for a streaming service.
 */
public class ProgettoClientXML {

    // Static & Global variables
    static final int PORT_HTML = 5567;
    static final int PORT_XML = 5566;
    static final String IP = "127.0.0.1";

    public static void main(String[] args) {
        try {
            Socket XMLserver = new Socket(IP, PORT_XML);
            System.out.println("Connected to XMLserver ...");

            ServerSocket HTMLlistener = new ServerSocket(PORT_HTML);
            Socket HTMLserver = HTMLlistener.accept();
            System.out.println("Connected to HTMLserver ...");

            System.out.println("Relay started ...");

            OneWayStream relayHtoX = new OneWayStream(
                new BufferedReader(new InputStreamReader(HTMLserver.getInputStream())),
                new PrintWriter(XMLserver.getOutputStream(), true)
            );

            OneWayStream relayXtoH = new OneWayStream(
                new BufferedReader(new InputStreamReader(XMLserver.getInputStream())),
                new PrintWriter(HTMLserver.getOutputStream(), true)
            );

            relayHtoX.start();
            relayXtoH.start();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

class OneWayStream extends Thread {
    BufferedReader in;
    PrintWriter out;

    OneWayStream(BufferedReader in, PrintWriter out) {
        this.in = in;
        this.out = out;
    }

    @Override
    public void run() {
        for (;;) {
            try {
                out.println(in.readLine());
            } catch (Exception e) {
                System.out.println("Errore Server");
                return;
            }
        }
    }
}
