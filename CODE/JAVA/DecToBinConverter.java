import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class DecToBinConverter {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Converter");
        JPanel panel = new JPanel();
        JButton convert = new JButton("Convert");
        JTextField input = new JTextField(10);
        JLabel label = new JLabel("");

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500, 100);
        frame.setLocationRelativeTo(null);
        frame.add(panel);
        convert.addActionListener(new Converter(label, input));
        panel.add(input);
        panel.add(convert);
        panel.add(label);

        frame.setVisible(true);

    }
}

class Converter implements ActionListener {
    private JLabel label;
    private JTextField input;

    public Converter(JLabel label, JTextField input) {
        this.label = label;
        this.input = input;
    }
    
    @Override
    public void actionPerformed(ActionEvent e) {
        try {
            int dec = Integer.parseInt(input.getText());
            String bin = Integer.toBinaryString(dec);
            label.setText(bin);
        } catch (NumberFormatException ex) {
            label.setText("Invalid input");
        }
    }
}