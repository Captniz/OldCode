import java.net.*;

public class UdpServer {
    public static void main(String[] args) throws Exception {
        final int PORT = 4000;
        final InetAddress IP = InetAddress.getByName("localhost");
        DatagramSocket socket = new DatagramSocket(PORT, IP);

        System.out.println("Server started");

        byte[] buffer = new byte[1024];
        DatagramPacket packet = new DatagramPacket(buffer, buffer.length);

        socket.receive(packet);

        String receivedData = new String(packet.getData(), 0, packet.getLength());
        System.out.println("Received data: " + receivedData);

        socket.close();
    }
}
