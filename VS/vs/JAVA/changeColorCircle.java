import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;

public class changeColorCircle {
    public static void main(String[] args) {
        String c[] = {"red", "green", "blue", "yellow", "black", "white"};

        MyFrame f = new MyFrame("Cerchi");
        MyPanel p = new MyPanel();
        
        final JComboBox<String> cb = new JComboBox<String>(c);
        cb.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println(cb.getSelectedItem().toString());
                f.repaint();
                f.refresh();
                System.out.println("repaint");
            }
        });
        
        f.add(p);
        p.add(cb);
        f.refresh();
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

class MyPanel extends JPanel{
    
    public MyPanel() {
        super();
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        JComboBox<String> cb = (JComboBox<String>) this.getComponent(0);
        String color = cb.getSelectedItem().toString();
        System.out.println(Color.getColor(color));
        g.setColor(Color.getColor(color));
        g.fillOval(100, 100, 100, 100);
    }
}
