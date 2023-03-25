import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class Dado{
    public static void main(String[] args) {
        MyFrame frame = new MyFrame();
        JPanel panel = new JPanel();
        JButton button = new JButton("Tira");
        
        panel.add(button);
        button.addActionListener(new Tiro(frame));
        frame.add(panel);

        frame.setVisible(true);
    }
}

class Tiro implements ActionListener{
    MyFrame frame;

    public Tiro(MyFrame frame) {
        super();
        this.frame = frame;
    }
    
    @Override
    public void actionPerformed(ActionEvent e) {
        Random random = new Random();
        int num = random.nextInt(6) + 1;
        MyPanel panel = new MyPanel(num);
        frame.add(panel);
        frame.refresh();
    }
}

class MyPanel extends JPanel{
    int num;

    public MyPanel(int num) {
        super();
        this.num = num;
        setBackground(Color.blue);
    }

    @Override   
    public void paint(Graphics g) {
        super.paint(g);
        System.out.println("Disegnanado dado...");
        Graphics2D g2 = (Graphics2D) g;
        g2.setColor(Color.orange);
        g2.fillRoundRect(250, 250, 300, 300, 50, 50);
        g2.setColor(Color.blue);
        switch (num) {
            case 1:
                g2.fillOval(250, 250, 50, 50);
                System.out.println("Response 1");
                break;
            case 2:
                g2.fillOval(50, 50, 50, 50);
                g2.fillOval(450, 450, 50, 50);
                System.out.println("Response 2");
                break;
            case 3:
                g2.fillOval(50, 50, 50, 50);
                g2.fillOval(450, 450, 50, 50);
                g2.fillOval(250, 250, 50, 50);
                System.out.println("Response 3");
                break;  
            case 4:
                g2.fillOval(50, 50, 50, 50);
                g2.fillOval(450, 450, 50, 50);
                g2.fillOval(450, 50, 50, 50);
                g2.fillOval(50, 450, 50, 50);
                System.out.println("Response 4");
                break;
            case 5:
                g2.fillOval(50, 50, 50, 50);
                g2.fillOval(450, 450, 50, 50);
                g2.fillOval(450, 50, 50, 50);
                g2.fillOval(50, 450, 50, 50);
                g2.fillOval(250, 250, 50, 50);
                System.out.println("Response 5");
                break;
            case 6:
                g2.fillOval(50, 50, 50, 50);
                g2.fillOval(450, 50, 50, 50);

                g2.fillOval(50, 250, 50, 50);
                g2.fillOval(450, 250, 50, 50);

                g2.fillOval(50, 450, 50, 50);
                g2.fillOval(450, 450, 50, 50);
                System.out.println("Response 6");
                break;
            default:
                break;
        }
    }
}

class MyFrame extends JFrame{
    public MyFrame() {
        super("Dado");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(500, 500);
        setLocationRelativeTo(null);
        setVisible(true);
    }
    public void refresh(){
        setVisible(false);
        setVisible(true);
    }
}