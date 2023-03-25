import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.lang.reflect.Array;

public class PreVerifica2 {
    public static void main(String[] args) {
        Window w = new Window("PreVerifica2");
        JLabel m[][] = new JLabel [11][11];
        JLabel r[][] = new JLabel [11][11];
        int ctr=0;
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                ctr++;
                m[i][j] = new JLabel(ctr + "");
                r[i][j] = new JLabel("0");
            }
        }
        Pane mp = new Pane();

        Pane mat = new Pane();
        mat.setBackground(Color.white);
        mat.setLayout(new GridLayout(11, 11));
    
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                mat.add(m[i][j]);
            }
        }
        
        Pane op = new Pane();
        op.setBackground(Color.gray);



        Pane res = new Pane();
        res.setBackground(Color.white);
        res.setLayout(new GridLayout(11, 11));
        
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                res.add(new JLabel("0"));
            }
        }
        
        JButton x = new JButton("X");
        ActionListener xlist = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                for (int i = 0; i < 11; i++) {
                    for (int j = 0; j < 11; j++) {
                        if(i==j || i+j==10){
                            r[i][j].setText(m[i][j].getText());
                        }else{
                            r[i][j].setText("0");
                        }
                        System.out.print(r[i][j].getText()+ " ");
                    }
                    System.out.println();
                }
                res.revalidate();
                res.repaint();
                w.refresh();
            }
        };
        x.addActionListener(xlist);

        JButton l = new JButton("L");
        ActionListener llist = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                for (int i = 0; i < 11; i++) {
                    for (int j = 0; j < 11; j++) {
                        if(j==0 || i==10){
                            r[i][j].setText(m[i][j].getText());
                        }else{
                            r[i][j].setText("0");
                        }
                        System.out.print(r[i][j].getText()+ " ");
                    }
                    System.out.println();
                }
                res.revalidate();
                res.repaint();
                w.refresh();
            }
        };
        l.addActionListener(llist);

        JButton o = new JButton("O");
        ActionListener olist = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                for (int i = 0; i < 11; i++) {
                    for (int j = 0; j < 11; j++) {
                        if(j==0 || j==10 || i==10 || i==0){
                            r[i][j].setText(m[i][j].getText());
                        }else{
                            r[i][j].setText("0");
                        }
                        System.out.print(r[i][j].getText()+ " ");
                    }
                    System.out.println();
                }
                res.revalidate();
                res.repaint();
                w.refresh();
            }
        };
        o.addActionListener(olist);

        op.add(x);
        op.add(l);
        op.add(o);

        mp.setLayout(new GridLayout(1, 3));
        mp.add(mat);
        mp.add(op);
        mp.add(res);
        w.add(mp);
        w.refresh();
    }
}

class Window extends JFrame {
    public Window(String s) {
        super(s);
        setSize(1500, 600);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void refresh(){
        setVisible(false);
        setVisible(true);
    }
}

class Pane extends JPanel {
    public Pane() {
        super();
    }
}
