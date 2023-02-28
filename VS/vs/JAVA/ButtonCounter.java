import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ButtonCounter {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Button Counter");
        JPanel panel = new JPanel();
        JButton add = new JButton("Add");
        JButton res = new JButton("Reset");
        JLabel label = new JLabel("0");

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 100);
        frame.add(panel);
        panel.add(add);
        add.addActionListener(new Adder(label));
        res.addActionListener(new Resetter(label));
        panel.add(res);
        panel.add(label);
        frame.setVisible(true);

    }
}

class Adder implements ActionListener {
    private JLabel label;

    public Adder(JLabel label) {
        this.label = label;
    }
    
    @Override
    public void actionPerformed(ActionEvent e) {
        int count = Integer.parseInt(label.getText());
        count++;
        label.setText("" + count);
    }
}

class Resetter implements ActionListener {
    private JLabel label;

    public Resetter(JLabel label) {
        this.label = label;
    }
    
    @Override
    public void actionPerformed(ActionEvent e) {
        label.setText("0");
    }
}