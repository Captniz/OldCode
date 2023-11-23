    FileManager(Socket csock, String directory) {
        buffer = new byte[4096];

        try {
            dis = new DataInputStream(csock.getInputStream());

            fileSize = dis.readLong();
            fileName = dis.readUTF();
            remaining = (int) fileSize;
            read = 0;

            file = new File(directory + fileName);
            fos = new FileOutputStream(file);

        } catch (IOException e) {
            System.out.println("Error: 2");
            e.printStackTrace();
        }
    }