import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class VerificaEs1 {

    public static void main(String[] args) {
        Fin f = new Fin("Tabellone");
        JPanel p = new JPanel();
        JLabel a = new JLabel("0");
        a.setFont(new Font("Courier new", Font.BOLD, 30));
        JLabel b = new JLabel("0");
        b.setFont(new Font("Courier new", Font.BOLD, 30));
        p.setLayout(new GridLayout(3, 2));
        p.add(new JLabel("Punti squadra A:"));
        p.add(new JLabel("Punti squadra B:"));
        p.add(a);
        p.add(b);
        p.add(new But("SEGNA", "A", a, b, f));
        p.add(new But("SEGNA", "B", a, b, f));
        f.add(p);

        f.refresh();
    }

}

class Fin extends JFrame {
    public Fin(String s) {
        super(s);
        setSize(500, 500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setVisible(true);
    }

    public void refresh() {
        this.setVisible(false);
        this.setVisible(true);
    }

}

class But extends JButton {
    String sq;
    JLabel a;
    JLabel b;
    Fin f;

    public But(String s, String sq, JLabel a, JLabel b, Fin f) {
        super(s);
        this.sq = sq;
        this.a = a;
        this.b = b;
        this.f = f;
        addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                int score = 0;
                if ((Integer.parseInt(a.getText()) != 5) && (Integer.parseInt(b.getText()) != 5)) {
                    if (sq.equals("A")) {
                        score = Integer.parseInt(a.getText());
                        score++;
                        if (score == 5) {
                            JOptionPane.showMessageDialog(null, "La squadra A vince");
                        }
                        a.setText(score + "");
                    } else {
                        score = Integer.parseInt(b.getText());
                        score++;
                        if (score == 5) {
                            JOptionPane.showMessageDialog(null, "La squadra B vince");
                        }
                        b.setText(score + "");
                    }
                }
                f.refresh();
            }
        });

    }

}