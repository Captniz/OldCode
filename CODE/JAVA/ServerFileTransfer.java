import java.net.ServerSocket;
import java.net.Socket;
import java.io.*;

public class ServerFileTransfer {
    public static void main(String[] args) {
        final int PORT = 5862;
        ServerSocket serverSocket;
        Socket clientSocket;
        FileManager fileManager;

        try {
            serverSocket = new ServerSocket(PORT);
            System.out.println("Server started on port " + PORT);

            while (true) {
                clientSocket = serverSocket.accept();
                System.out.println("Client connected");

                fileManager = new FileManager(clientSocket, "./FileTransfer/");
                fileManager.saveFile();

                clientSocket.close();
                fileManager.close();
            }

        } catch (IOException e) {
            System.out.println("Error: ");
            e.printStackTrace();
        }
    }
}

class FileManager {
    DataInputStream dis;
    FileOutputStream fos;
    File file;

    byte[] buffer;
    int read;
    int remaining;

    String fileName;
    long fileSize;

    FileManager(Socket csock, String directory) {
        buffer = new byte[4096];

        try {
            dis = new DataInputStream(csock.getInputStream());

            fileName = dis.readUTF();
            fileSize = dis.readLong();
            remaining = (int) fileSize;
            read = 0;

            file = new File(directory + fileName);
            fos = new FileOutputStream(file);

        } catch (IOException e) {
            System.out.println("Error: 2");
            e.printStackTrace();
        }
    }

    public void saveFile() {
        try {
            while ((read = dis.read(buffer, 0, Math.min(buffer.length, remaining))) > 0) {
                remaining -= read;
                fos.write(buffer, 0, read);
            }

            System.out.println("File saved: " + fileName);
        } catch (IOException e) {
            System.out.println("Error: ");
            e.printStackTrace();
        }
    }

    public void close() {
        try {
            fos.close();
            dis.close();
        } catch (IOException e) {
            System.out.println("Error: ");
            e.printStackTrace();
        }
    }
}