import java.awt.*;
import java.util.Random;
import javax.swing.*;

public class InterfacceGrafiche {
    public static void main(String[] args) {
        try {
            Finestra f = new Finestra();
            JPanel p = new JPanel();

            p.add(new JLabel("zfssf"));
            f.add(p);

            Thread.sleep(1000);
            f.setSize(2000, 2000);
            System.out.println("Ciao");
            Thread.sleep(1000);

            f.setVisible(false);
            f.setVisible(true);
        } catch (Exception e) {

            // TODO: handle exception
        }

    }
}

class Finestra extends JFrame {
    public Finestra() {
        super("Ciao");
        setLocation(0, 0);
        setSize(100, 100);
        setResizable(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }
}
