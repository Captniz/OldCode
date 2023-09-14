
/*Riflessi. Scrivi un programma che disegni una griglia 3x3 di quadrati dove un solo quadrato si illumina di rosso. Una volta che l’utente ha cliccato un altro quadrato della griglia si illumina. Lo scopo del gioco è testare i riflessi dell’utente il quale deve cliccare piu’ velocemente possibile i vari quadrati illuminati.
Dopo 10 click dell’utente il gioco finisce e deve essere detto all’utente quanto ha impiegato.

Devi inoltre prevedere due bottoni: uno per far partire il gioco, un altro per dire la classifica del gioco. Nella classifica del gioco viene memorizzato il nome dell’utente e il suo “record” di tempo del gioco.*/
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class Riflessi {
    public static void main(String[] args) {
        Fin f = new Fin();
        JButton reset = new JButton("Reset");
        reset.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                Random rnd = new Random();
                for (Bot bottone : f.getB()) {
                    bottone.setBackground(Color.white);
                }
                f.getB()[rnd.nextInt(9)].setBackground(Color.red);
                f.setCtr(0);
                f.setTime(System.currentTimeMillis());
                f.refresh();
            }
        });
        JButton classifica = new JButton("Classifica");
        classifica.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String s = "Classifica partite:\n\n";
                for (Partita p : f.getPartite()) {
                    s += p.toString() + "\n";
                }

                JOptionPane.showMessageDialog(null, s);

            }
        });
        Pan mp = new Pan(new GridLayout(2, 1));
        Pan cp = new Pan(new GridLayout(2, 1));
        cp.add(reset);
        cp.add(classifica);
        Pan p = new Pan(new GridLayout(3, 3));
        for (Bot bottone : f.getB()) {
            p.add(bottone);
        }

        mp.add(cp);
        mp.add(p);
        f.add(mp);

        f.refresh();
    }

}

class Fin extends JFrame {
    Bot[] b;
    int ctr;
    double time;
    ArrayList<Partita> partite;

    public Fin() {
        super("Riflessi");
        Random rnd = new Random();
        setSize(500, 1000);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);

        b = new Bot[9];
        for (int i = 0; i < 9; i++) {
            b[i] = new Bot();
            b[i].setBackground(Color.white);
        }
        b[rnd.nextInt(9)].setBackground(Color.red);

        time = System.currentTimeMillis();
        ctr = 0;
        partite = new ArrayList<Partita>();
    }

    public void refresh() {
        setVisible(true);
    }

    public Bot[] getB() {
        return b;
    }

    public int getCtr() {
        return ctr;
    }

    public void setB(Bot[] b) {
        this.b = b;
    }

    public void setCtr(int ctr) {
        this.ctr = ctr;
    }

    public double getTime() {
        return time;
    }

    public void setTime(double time) {
        this.time = time;
    }

    public ArrayList<Partita> getPartite() {
        return partite;
    }

    public void setPartite(ArrayList<Partita> partite) {
        this.partite = partite;
    }
}

class Pan extends JPanel {
    public Pan(LayoutManager layout) {
        super();
        setLayout(layout);
    }
}

class Bot extends JButton {
    public Bot() {
        super();
        addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                Fin f = (Fin) SwingUtilities.getWindowAncestor(Bot.this);
                if (getBackground() == Color.red && f.getCtr() < 10) {
                    Random rnd = new Random();
                    setBackground(Color.white);
                    f.setCtr(f.getCtr() + 1);

                    if (f.getCtr() == 10) {
                        f.setTime(System.currentTimeMillis() - f.getTime());
                        JOptionPane.showMessageDialog(null, "Hai impiegato " + f.getTime() + " millisecondi");
                        Partita p = new Partita(JOptionPane.showInputDialog("Inserisci il tuo nome"), f.getTime());
                        f.getPartite().add(p);
                        return;
                    }

                    Bot[] b = f.getB();
                    b[rnd.nextInt(9)].setBackground(Color.red);
                    f.setB(b);

                    System.out.println(f.getCtr());
                    f.refresh();
                }
            }
        });
    }
}

class Partita {

    private String nome;
    private Double tempo;

    public Partita(String nome, Double tempo) {
        this.nome = nome;
        this.tempo = tempo;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Double getTempo() {
        return tempo;
    }

    public void setTempo(Double tempo) {
        this.tempo = tempo;
    }

    @Override
    public String toString() {
        return "Giocatore: " + nome + ", Tempo: " + tempo + "ms";
    }
}