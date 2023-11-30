import java.net.*;
import java.util.*;

public class UdpClient {

    public static void main(String[] args) throws Exception {

        final int PORT = 4000;
        final InetAddress IP = InetAddress.getByName("localhost");

        DatagramPacket dp;
        Scanner scn;
        DatagramSocket ds;

        ds = new DatagramSocket();
        scn = new Scanner(System.in);

        System.out.println("Msg:");
        String msg = scn.nextLine();
        byte[] buf = msg.getBytes();

        dp = new DatagramPacket(buf, buf.length, IP, PORT);
        ds.send(dp);
        dp = new DatagramPacket(buf, buf.length, IP, PORT);
        ds.send(dp);
        ds.close();
        scn.close();
    }
}
