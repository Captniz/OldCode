
public class MainTree {
    public static void main(String[] args) {
        BinTree tree = new BinTree(10);
        tree.insert(15);
        tree.insert(12);
        tree.insert(17);
        tree.insert(5);
        tree.insert(3);
        tree.insert(7);

        tree.visitaPosticipata();

    }
}