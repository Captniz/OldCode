import java.io.*;

public class es_uno {
    public static void main(String[] args) {
        try {
            FileReader in = new FileReader("magazzino.txt");
            int r = in.read();
            int tot = 0;
            int qnt = 0;
            int prc = 0;
            String tmp = "";
            while (r != -1) {
                if ((char) r == '#') {
                    r = in.read();
                    while ((char) r != '@') {
                        tmp += (char) r;
                        r = in.read();
                    }
                    prc = Integer.parseInt(tmp);
                    tmp = "";
                    r = in.read();
                    while (r <= '9' && r >= '0') { // !CORREZZIONE
                        tmp += (char) r;
                        r = in.read();
                    }
                    qnt = Integer.parseInt(tmp);
                    tot += prc * qnt;
                    tmp = "";
                    prc = 0;
                    qnt = 0;
                }
                r = in.read();
            }
            in.close();
            FileWriter out = new FileWriter("out.txt", true);
            out.write(tot + ""); // !CORREZZIONE
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
