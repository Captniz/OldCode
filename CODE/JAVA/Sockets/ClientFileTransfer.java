import java.net.Socket;
import java.io.*;

public class ClientFileTransfer {
    public static void main(String[] args) {
        final int PORT = 5862;
        Socket socket;

        try {
            socket = new Socket("localhost", PORT);
            System.out.println("Client connected!" + PORT);

            // Send file to server
            File file = new File("./input.txt");
            FileInputStream fis = new FileInputStream(file);
            DataOutputStream dos = new DataOutputStream(socket.getOutputStream());
            dos.writeUTF(file.getName());
            dos.writeLong(file.length());
            byte[] buffer = new byte[4096];
            int read = 0;

            while ((read = fis.read(buffer)) > 0) {
                dos.write(buffer, 0, read);
            }

            fis.close();
            dos.close();
            socket.close();
            System.out.println("File sent: " + file.getName());

        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
