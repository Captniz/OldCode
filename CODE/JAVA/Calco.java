import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Calco {
    public static void main(String args[]){
        Fin f = new Fin("Calcolatrice");
        JPanel pv = new JPanel();
        JPanel pn = new JPanel();
        JPanel pm = new JPanel();
        JLabel jl = new JLabel();
        pn.setLayout(new GridLayout(4, 4));
        pm.setLayout(new GridLayout(2, 1));

        f.add(pm);
        pm.add(pv);
        pm.add(pn);

        pv.add(jl);
        pn.add(new But("1",  jl,  f));
        pn.add(new But("2",  jl,  f));
        pn.add(new But("3",  jl,  f));
        pn.add(new But("+",  jl,  f));
        pn.add(new But("4",  jl,  f));
        pn.add(new But("5",  jl,  f));
        pn.add(new But("6",  jl,  f));
        pn.add(new But("-",  jl,  f));
        pn.add(new But("7",  jl,  f));
        pn.add(new But("8",  jl,  f));
        pn.add(new But("9",  jl,  f));
        pn.add(new But("*",  jl,  f));
        pn.add(new But("0",  jl,  f));
        pn.add(new But("/",  jl,  f));
        pn.add(new But("=",  jl,  f));
        f.refresh();
    }
}

class Fin extends JFrame {
    public int num;
    public String sim;

    public Fin(String s) {
        super(s);
        setSize(500, 500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
        num = 0;
        sim = "";
    }

    public void refresh(){
        setVisible(false);
        setVisible(true);
    }
}

class But extends JButton {
    String cha;
    JLabel jl;
    Fin f;
    JButton jb;

    public But(String s, JLabel jl, Fin f) {
        super(s);
        cha = s;
        jb = this;
        addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.out.println("BUTTON: " + jb.getText());
                if (cha.equals("+") || cha.equals("-") || cha.equals("*") || cha.equals("/")) {
                    f.num = Integer.parseInt(jl.getText());
                    f.sim = cha;
                    jl.setText("");
                } else if (cha.equals("=")) {
                    if (f.sim.equals("+")) {
                        jl.setText(Integer.toString(f.num + Integer.parseInt(jl.getText())));
                    } else if (f.sim.equals("-")) {
                        jl.setText(Integer.toString(f.num - Integer.parseInt(jl.getText())));
                    } else if (f.sim.equals("*")) {
                        jl.setText(Integer.toString(f.num * Integer.parseInt(jl.getText())));
                    } else if (f.sim.equals("/")) {
                        jl.setText(Integer.toString(f.num / Integer.parseInt(jl.getText())));
                    }
                } else {
                    jl.setText(jl.getText() + cha);
                }
            }
        });
    }
}