public class MainTree {
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree(10);

        tree.insert(15);
        tree.insert(5);
        tree.insert(2);
        tree.insert(7);
        tree.insert(17);

        tree.find(5);
        tree.stampaLinee();
        tree.delete(5);
        tree.stampaLinee();
    }
}