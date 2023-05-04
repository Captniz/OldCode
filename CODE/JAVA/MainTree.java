import java.util.*;

public class MainTree {
    public static void main(String[] args) {
        Random rnd = new Random();
        BinTree tree = new BinTree(rnd.nextInt(100));
        Scanner in = new Scanner(System.in);

        for (int i = 0; i < 10; i++) {
            tree.insert(rnd.nextInt(100));
        }

        tree.print();
        System.out.print("\nValore da trovare: ");
        
        try {
            tree.find(in.nextInt());
            System.out.println("Numero trovato\n\n");
        }catch (Exception e) {
            System.out.println("Numero non trovato\n\n");
        }

        System.out.print("Valore da cancellare: ");
        try {
            tree.delete(in.nextInt());
            tree.print();            
        }catch (Exception e) {
            System.out.println("Numero non trovato");
        }
        in.close();
    }
}