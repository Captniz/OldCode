import java.awt.*;
import java.util.Random;
import javax.swing.*;
public class InterfacceGrafiche {
    public static void main(String[] args) {
        Finestra f = new Finestra();
        JPanel p = new JPanel();

        p.add(new JLabel("Ciao"));
        f.add(p);
    }
}

class Finestra extends JFrame{
    public Finestra(){
        super("Ciao");
        setLocation(0,0);
        setSize(100,100);
        setResizable(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }
}
