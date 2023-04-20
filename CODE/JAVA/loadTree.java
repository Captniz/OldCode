import java.io.*;
import java.util.*;

public class loadTree {
    public static void main(String[] args) {
        int[] num = { 6, 13, 4, 8, 1, 5, 7, 9 };
        Node tree = new Node(10);

        for (int i = 0; i < 8; i++) {
            tree.insert(num[i]);
        }

        tree.print();
        System.out.println();
        tree.find(6).delete();
        tree.print();
    }
}

// Modello L - root - R : standard

/*
 * Metodi primitivi:
 * - find(int) : Object -> Restituisce o il nodo in se o il livello del nodo
 * - insert(?) : ? -> Aggiunge un nodo
 * - delete(?) : ? -> Rimuove un nodo e mantiene l'ordine
 *
 * Metodi non primitivi:
 * - print(Node) : void -> Stampa l'albero con il modello "L - Root - R"
 * - printCool(Node) : void -> Stampa l'albero con il modello "L - Root - R",
 * con una grafica decente.
 **/

class Node {
    int value;
    Node lx;
    Node rx;
    Node self;

    public Node() {
        value = 0;
        lx = null;
        rx = null;
        self = this;
    }

    public Node(int val) {
        value = val;
        lx = null;
        rx = null;
        self = this;
    }

    public Node find(int val) {
        Node tmp;
        if (this.value == val) {
            return self;
        }
        if (this.lx != null) {
            tmp = lx.find(val);
            if (tmp != null) {
                return tmp;
            }
        }
        if (this.rx != null) {
            tmp = rx.find(val);
            if (tmp != null) {
                return tmp;
            }
        }
        return null;
    }

    public void delete() {
        this.setValue(this.rx.getValue());
        Node[] attachments = { this.rx.getRx(), this.rx.getLx(), this.lx };
        this.rx = null;
        this.lx = null;

        for (Node node : attachments) {
            this.insert(node);
        }
    }

    public void insert(int val) {
        // Used only on the root
        if (this.value > val) {
            if (this.lx == null) {
                this.setLx(new Node(val));
            } else {
                lx.insert(val);
            }
        } else if (this.value < val) {
            if (this.rx == null) {
                this.setRx(new Node(val));
            } else {
                rx.insert(val);
            }
        }
        return;
    }

    public void insert(Node val) {
        // Used only on the root
        if (this.value > val.getValue()) {
            if (this.lx == null) {
                this.setLx(val);
            } else {
                lx.insert(val);
            }
        } else if (this.value < val.getValue()) {
            if (this.rx == null) {
                this.setRx(val);
            } else {
                rx.insert(val);
            }
        }
        return;
    }

    public void print() {
        if (this.lx != null) {
            this.lx.print();
        }
        System.out.print(this.value + " ");
        if (this.rx != null) {
            this.rx.print();
        }
        return;
    }

    public void printCool(Queue<Node> queue) {
        // Print in a pyramid the binTree
        // TODO:
        Queue<Node> nextQueue = new LinkedList<Node>();
        Node tmp;
        while (!queue.isEmpty()) {
            tmp = queue.remove();
            System.out.print(tmp.getValue() + " ");
            if (tmp.lx != null) {
                nextQueue.add(tmp.lx);
            }
            if (tmp.rx != null) {
                nextQueue.add(tmp.rx);
            }
        }
        if (!nextQueue.isEmpty()) {
            System.out.println();
            printCool(nextQueue);
        }
        return;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    public Node getLx() {
        return lx;
    }

    public void setLx(Node lx) {
        this.lx = lx;
    }

    public Node getRx() {
        return rx;
    }

    public void setRx(Node rx) {
        this.rx = rx;
    }
}