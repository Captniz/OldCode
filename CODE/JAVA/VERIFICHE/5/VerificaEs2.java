import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class VerificaEs2 {
    public static void main(String[] args) {
        Fin f = new Fin("Tabellone");
        Pan pm = new Pan(new GridLayout(4,1));
        JTextField tf = new JTextField(); //IMPORTANTE
        JLabel jl = new JLabel(); //IMPORTANTE
        Pan pt = new Pan(new GridLayout(1,1));
        pt.add(new JLabel("INSERISCI ZONA E TIPO BIGLIETTO"));
        Pan pz = new Pan(new GridLayout(1,2));
        pz.add(new JLabel("Numero zona:"));
        pz.add(tf);
        Pan pb = new Pan(new GridLayout(1,3));
        pb.add(new But("GIORNALIERO",f,tf,jl));
        pb.add(new But("SETTIMANALE",f,tf,jl));
        pb.add(new But("MENSILE",f,tf,jl));
        Pan pf = new Pan(new GridLayout(1,3));
        pf.add(new JLabel("Importo:"));
        pf.add(jl);
        pf.add(new ConfirmBut("STAMPA",f,pf,jl));
       
        pm.add(pt);
        pm.add(pz);
        pm.add(pb);
        pm.add(pf); 
        f.add(pm);
        f.refresh();
    }
    
}

class Fin extends JFrame{
    private int zone ;
    private int dur ;
    public Fin(String s){
        super(s);
        setSize(500,500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setVisible(true);
        zone=0;
        dur=0;
    }
    
    public int mdur(){
        return dur;
    }
    public int mdur(int a){
        dur = a;
        return dur;
    }
    
    public int mzone(){
        return zone;
    }
    public int mzone(int a){
        zone = a;
        return zone;
    }
    
    public void refresh(){
        this.setVisible(false);
        this.setVisible(true);
    }
    
}

class But extends JButton{
    Fin f;
    JButton jb; 
    JTextField tf;
    JLabel jl;
    
    float a1[] = {1,9,28};
    float a2[] = {2,17,55};
    float a3[] = {2.5f,25,65};
    float arr[][] = {a1,a2,a3};
    
    public But(String s, Fin f, JTextField tf, JLabel jl){
        super(s);
        this.f  =f;
        jb = this;
        this.tf =tf;
        this.jl = jl;
        addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                float imp =0;
                if(Integer.parseInt(tf.getText()) == 1 || Integer.parseInt(tf.getText()) == 2 || Integer.parseInt(tf.getText()) == 3 ){
                    f.mzone(Integer.parseInt(tf.getText()));
                    if(jb.getText().equals("GIORNALIERO")){
                        f.mdur(1);
                    }else if(jb.getText().equals("SETTIMANALE")){
                        f.mdur(2);
                    }else{
                        f.mdur(3);
                    }
                    imp = arr[f.mzone()-1][f.mdur()-1];
                    jl.setText(imp+"");
                    f.refresh();
                }else{
                    JOptionPane.showMessageDialog(null, "Zona non valida");
                }
            }
        });
        
    }
}

class ConfirmBut extends JButton{
    Fin f;
    Pan p; 
    JLabel jl;
    JTextField tf;
    float a1[] = {1,9,28};
    float a2[] = {2,17,55};
    float a3[] = {2.5f,25,65};
    float arr[][] = {a1,a2,a3};
    public ConfirmBut(String s, Fin f, Pan p, JLabel jl){
        super(s);
        this.f =f;
        this.p = p;
        this.jl = jl;
        this.tf =tf;
        addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                if(f.mdur() != 0 && f.mzone() != 0){
                    p.setBackground(Color.gray);
                    jl.setText("Stampa in corso...");
                    f.refresh();
                }
               
            }
        });
        
    }
}

class Pan extends JPanel{
    public Pan(GridLayout l){
        super();
        setBackground(Color.yellow);
        setLayout(l);
    }
}
