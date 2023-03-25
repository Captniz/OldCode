import java.awt.*;
import javax.swing.*;

import org.w3c.dom.css.RGBColor;

import java.awt.event.*;
import java.util.*;
public class drawCircle {
    public static void main(String[] args) {
        MyFrame f = new MyFrame("Cerchi");
        MyPanel p = new MyPanel();
        //create a button with action listener
        JButton b = new JButton("Cambia colore");
        f.add(p);
    }
}

class Cerchio{
    Random r = new Random();
    public int x;
    public int y;
    Cerchio(){
        x = r.nextInt();
        y = r.nextInt();
    }
} 

class MyFrame extends JFrame{
    public MyFrame(String s) {
        super(s);
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

class MyButton extends JButton{
    JFrame f;
    JButton b;

    public MyButton(String s, JFrame f, JButton b) {
        super(s);
        this.f = f;
        this.b = b;
        this.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                
                f.repaint();
            }
        });
    }
}

class MyPanel extends JPanel{
    ArrayList<Cerchio> cerchi = new ArrayList<Cerchio>();
    public MyPanel() {
        super();
        setBackground(Color.blue);
    }
    public void paint(Graphics g) {
        super.paint(g);
        Graphics2D g2 = (Graphics2D) g;
        g2.setColor(Color.orange);
        for (Cerchio c : cerchi) {
            g2.fillOval(c.x, c.y, 100, 100);
        }
    }
}