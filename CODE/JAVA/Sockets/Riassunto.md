import java.net.*;

# UDP

## Client

final int PORT = 4000;
final InetAddress IP = InetAddress.getByName("localhost");

DatagramPacket dp;
Scanner scn;
DatagramSocket ds;

ds = new DatagramSocket();
scn = new Scanner(System.in);

String msg = scn.nextLine();
byte[] buf = msg.getBytes();

dp = new DatagramPacket(buf, buf.length, IP, PORT);
ds.send(dp);
ds.close();
scn.close();

## Server

final int PORT = 4000;
DatagramSocket socket = new DatagramSocket(PORT);

byte[] buffer = new byte[1024];
DatagramPacket packet = new DatagramPacket(buffer, buffer.length);

socket.receive(packet);
String receivedData = new String(packet.getData(), 0, packet.getLength());

System.out.println("Received data: " + receivedData);
socket.close();

# Classic

import java.net.*;

## Client

### Main

final int PORT = 5862;
ServerSocket ss;
ss = new ServerSocket(PORT);
Worker w;

while(True){
    w = new Worker(ss.accept();)
}

### Worker

//ClientSocket passato con costruttore//

PrintWriter clientStreamOut = new PrintWriter(clientSocket.getOutputStream(), true);
BufferedReader clientStreamIn = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

...

## Server

final String IP = "127.0.0.1";
final int PORT = 5862;
Socket serverSocket;
PrintWriter serverStreamOut;
BufferedReader serverStreamIn;

serverSocket = new Socket(IP, PORT);
serverStreamOut = new PrintWriter(serverSocket.getOutputStream(), true);
serverStreamIn = new BufferedReader(new InputStreamReader(serverSocket.getInputStream()));

//IMPORTANTE, quando compari delle stringhe in un if usa sempre 'x.equals(y)'//

...

# File

## Client

final int PORT = 5862;
Socket socket;

socket = new Socket("localhost", PORT);

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

## Server

final int PORT = 5862;
ServerSocket serverSocket;
Socket clientSocket;

serverSocket = new ServerSocket(PORT);

clientSocket = serverSocket.accept();

DataInputStream dis;
FileOutputStream fos;
File file;

byte[] buffer;
int read;
int remaining;

String fileName;
long fileSize;

buffer = new byte[4096];
dis = new DataInputStream(csock.getInputStream());

fileName = dis.readUTF();
fileSize = dis.readLong();
remaining = (int) fileSize;
read = 0;

file = new File(directory + fileName);
fos = new FileOutputStream(file);

while ((read = dis.read(buffer, 0, Math.min(buffer.length, remaining))) > 0) {
    remaining -= read;
    fos.write(buffer, 0, read);
}

# XML

<?xml version="1.0" encoding="UTF-8" ?>