import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.Random;

public class PreVerifica1 {
    public static void main(String[] args) {
        ArrayList<Hit> hits = new ArrayList<Hit>();
        Window w = new Window("PreVerifica1");
        JLabel xl = new JLabel("x");
        JLabel yl = new JLabel("y");
        JLabel dl = new JLabel("d");
        Button b = new Button("Hit", w, xl, yl, dl, hits);
        JPanel mp = new JPanel();
        mp.setLayout(new BoxLayout(mp, BoxLayout.Y_AXIS));
        Pane p = new Pane(hits);
        mp.add(b);
        mp.add(xl);
        mp.add(yl);
        mp.add(dl);
        mp.add(p);
        w.add(mp);
        w.refresh();
    }
}

class Window extends JFrame {
    public Window(String s) {
        super(s);
        setSize(500, 500);
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

    ArrayList<Hit> hits;

    public Pane(ArrayList<Hit> hits) {
        super();
        this.hits = hits;
        setBackground(Color.gray);
    }
    public void paint(Graphics g) {
        super.paint(g);
        Graphics2D g2 = (Graphics2D) g;
        g2.drawRect(0, 0, 300, 300);
        g2.setColor(Color.blue);
        g2.fillOval(0,0,300,300);
        g2.setColor(Color.red);
        g2.fillOval(50,50,200,200);
        g2.setColor(Color.yellow);
        g2.fillOval(100,100,100,100);
        g2.setColor(Color.green);
        for (Hit hit : hits) {
            g2.fillOval(hit.x, hit.y, 5, 5);
        }
    }
}

class Button extends JButton {

    Window w;   
    ArrayList<Hit> hits;
    JLabel xl;
    JLabel yl;
    JLabel dl;

    public Button(String s, Window w,JLabel xl,JLabel yl,JLabel dl, ArrayList<Hit> hits) {
        super(s);
        this.w = w;
        this.hits = hits;
        this.xl = xl;
        this.yl = yl;
        this.dl = dl;
        addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                hits.add(new Hit());
                w.repaint();
                xl.setText("X: " + hits.get(hits.size()-1).x);
                yl.setText("Y: " + hits.get(hits.size()-1).y);
                dl.setText("Distance: " + Math.sqrt(Math.pow(hits.get(hits.size()-1).x-150,2)+Math.pow(hits.get(hits.size()-1).y-150,2)));
                w.refresh();
            }
        });
    }


}

class Hit {
    public int x;
    public int y;
    Random r = new Random();

    Hit(){
        x = r.nextInt(300);
        y = r.nextInt(300);
    }
}