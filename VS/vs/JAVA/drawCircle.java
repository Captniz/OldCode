import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.*;
public class drawCircle {
    public static void main(String[] args) {
        
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
    public MyFrame() {
        super("Dado");
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