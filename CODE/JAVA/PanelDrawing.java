import javax.swing.*;
import java.awt.*;

public class PanelDrawing{
    public static void main(String[] args) {
        JFrame frame = new JFrame("Panel Drawing");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 300);
        frame.setLocationRelativeTo(null);
        frame.add(new panel());
        frame.setVisible(true);
    }
}

class panel extends JPanel{
    public panel() {
        super();
        setBackground(Color.yellow);
    }

    public void paint(Graphics g) {
        super.paint(g);
        Graphics2D g2 = (Graphics2D) g;
        g2.setColor(Color.red);
        g2.drawLine(10, 10, 100, 100);
        g2.setColor(Color.blue);
        g2.drawRect(10, 10, 100, 100);
        g2.setColor(Color.green);
        g2.fillOval(10, 10, 100, 100);
    }
}