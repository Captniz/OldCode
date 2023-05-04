import java.io.*;
import java.util.*;

public class loadTree {
    public static void main(String[] args) {
        int[] num = { 5, 7, 2, 15 };
        BinTree tree = new BinTree(10);

        for (int i = 0; i < num.length; i++) {
            tree.insert(num[i]);
        }

        tree.print();
        System.out.println();
        tree.find(5);
        // delete ogni cosa che non sia una foglia da un exception strana
        // CONTROLLA QUANDOAGGIUNGI A GLI ATTACHMENTS
        tree.print();
    }
}