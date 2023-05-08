
/*Dato un file di testo numeri.txt carica un binTree e stabilisci se è maggiore la somma delle foglie di sinistra o di destra o uguali*/
import java.io.*;

public class EsTree {
    public static void main(String[] args) {
        String tmp = "";
        BufferedReader r;
        try {
            r = new BufferedReader(new FileReader("input.txt"));

            try {
                TreeCounter tree = new TreeCounter();
                tmp = r.readLine();
                tree.insert(Integer.parseInt(tmp));

                tmp = r.readLine();

                // Load
                while (tmp != null) {
                    tree.insert(Integer.parseInt(tmp));
                    tmp = r.readLine();
                }

                // Main
                int sums[] = tree.sum();

                tree.stampaLinee();
                System.out.println();
                if (sums[0] > sums[1]) {
                    System.out.println("Left is greater");
                } else if (sums[0] < sums[1]) {
                    System.out.println("Right is greater");
                } else {
                    System.out.println("The branches are Equal");
                }

            } catch (Exception e) {
                System.out.print("File vuoto");
                return;
            }
        } catch (Exception e) {
            System.out.print("File inesistente");
            return;
        }
    }
}

class TreeCounter {
    public class Node {
        int data;
        Node left;
        Node right;

        Node(int data) {
            this.data = data;
        }

        public void insert(int data) {
            if (data > this.data) {
                if (right == null) {
                    right = new Node(data);
                } else {
                    right.insert(data);
                }
            } else if (data < this.data) {
                if (left == null) {
                    left = new Node(data);
                } else {
                    left.insert(data);
                }
            }
            return;
        }

        public int[] sum() {
            int[] sums = { 1, 0 };
            if (left != null) {
                sums[0] = left.branchSum();
            }

            if (right != null) {
                sums[1] = right.branchSum();
            }

            return sums;
        }

        public int branchSum() {
            int sum = 0;
            if (left != null) {
                sum = sum + left.branchSum();
            }
            if (right != null) {
                sum = sum + right.branchSum();
            }
            return sum + data;
        }

        public void stampaLinee(Node curr, int space) {
            System.out.print(space + "| ");
            for (int i = 0; i < space; i++) {
                System.out.print(" ");
            }
            System.out.print("└");
            System.out.print(curr.data + "\n");
            if (curr.left != null) {
                stampaLinee(curr.left, space + 1);
            }
            if (curr.right != null) {
                stampaLinee(curr.right, space + 1);
            }
        }
    }

    private Node root;

    TreeCounter() {
        root = null;
    }

    public void insert(int data) {
        if (root == null) {
            root = new Node(data);
        } else {
            root.insert(data);
        }
        return;
    }

    public void stampaLinee() {
        root.stampaLinee(root, 0);
    }

    public int[] sum() {
        return root.sum();
    }

    public int getRoot() {
        return root.data;
    }
}