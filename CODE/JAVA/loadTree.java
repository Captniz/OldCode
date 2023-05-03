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

class Node {
    // Tree model -> L - ROOT - R : (Standard)
    /*
     * Primitive methods:
     * - find(int) : Object -> Returns the node with the specified value.
     * - insert(int) : void -> Inserts a node with the specified value.
     * - insert(Node) : void -> Inserts a node, (Must have aleady a value assigned).
     * - delete(void) : void -> Deletes the node and re-attaches his child nodes.
     *
     * Non-primitive methods:
     * - print() : void -> Prints the tree in order.
     **/

    // ##############################################
    // # ATTRIBUTES #
    // ##############################################

    // Value of the node
    int value;
    // Child node to the left
    Node lx;
    // Child node to the right
    Node rx;
    // The node itself
    Node self;

    // ##############################################
    // # CONSTRUCTORS #
    // ##############################################

    /*
     * Empty constructor
     */
    public Node() {
        value = 0;
        lx = null;
        rx = null;
        self = this;
    }

    /*
     * Parametered constructor
     * Summary:
     * Gives a value to the node.
     * Parameters:
     * - int val -> Value of the node
     */
    public Node(int val) {
        value = val;
        lx = null;
        rx = null;
        self = this;
    }

    // ##############################################
    // # PRIMITIVES #
    // ##############################################

    /*
     * Method Find()
     * Summary:
     * Find a node given the specified value, does not support multiple nodes with
     * the same value.
     * Can be used on any node but bare in mind that it will only search the node and
     * its childs, so its always better to use it on the root.
     * Parameters:
     * - int val -> Value to find in the tree
     * Returns:
     * - Node tmp -> Node found in the tree with the value in input
     */
    public Node find(int val) {
        Node tmp;
        // If the value of this node is equal to the value we are searching for, return
        // the node itself.
        if (this.value == val) {
            return self;
        }
        // If there is a node to the left, search it with the find method ( Recursive )
        if (this.lx != null) {
            tmp = lx.find(val);
            if (tmp != null) {
                return tmp;
            }
        }
        // Once there are no more nodes to the left check each right branch
        if (this.rx != null) {
            tmp = rx.find(val);
            if (tmp != null) {
                return tmp;
            }
        }
        // Return null if failed
        return null;
    }

    /*
     * Method Delete()
     * Summary:
     * Deletes the node and re-attaches his child nodes to
     * the tree, does not support multiple nodes with
     * the same value.
     * Can be used on any node, including the root.
     */
    public void delete() {
        // Get the value of the branch to the right and put it in this node
        this.setValue(this.rx.getValue());
        // !Da qui in poi fa talmente shifo che ho vergogna ha spiegarlo, funziona
        Node[] attachments = { this.rx.getRx(), this.rx.getLx(), this.lx };
        this.rx = null;
        this.lx = null;

        for (Node node : attachments) {
            this.insert(node);
        }
        return;
    }

    /*
     * Method Insert() -> Value
     * Summary:
     * Insert a node in the tree giving only the value of the node.
     * !SHOULD BE USED ONLY ON THE ROOT! Using this method on other nodes will
     * result in the node possibly being inserted in the wrong place.
     * Parameters:
     * - int val -> Value of the node to insert in the tree
     */
    public void insert(int val) {
        // Check the value of the current node, and determine if it should go to the
        // left ( lesser ) or to the right ( greater ).
        if (this.value > val) {
            // If the child node of the side determined is not present, insert the node.
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
        // This is the only case where the node is not inserted, because it already
        // exists.
        return;
    }

    /*
     * Method Insert() -> Node
     * Summary:
     * Insert a node in the tree, the node must aleady have a value assigned.
     * !SHOULD BE USED ONLY ON THE ROOT! Using this method on other nodes will
     * result in the node possibly being inserted in the wrong place.
     * Parameters:
     * - Node val -> Node to insert in the tree
     */
    public void insert(Node val) {
        // Check the value of the current node, and determine if it should go to the
        // left ( lesser ) or to the right ( greater ).
        if (this.value > val.getValue()) {
            // If the child node of the side determined is not present, insert the node.
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
        // This is the only case where the node is not inserted, because it already
        // exists.
        return;
    }

    // ##############################################
    // # NOT-PRIMITIVES #
    // ##############################################

    /*
     * Method Print()
     * Summary:
     * Print the tree starting from the left side to the right, resulting in an
     * ascending ordered print.
     * Can be used on any node but bare in mind that it will only print the node and
     * its childs, so its always better to use it on the root.
     */
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

    // ##############################################
    // # GETTERS & SETTERS #
    // ##############################################

    private int getValue() {
        return value;
    }

    private void setValue(int value) {
        this.value = value;
    }

    private Node getLx() {
        return lx;
    }

    private void setLx(Node lx) {
        this.lx = lx;
    }

    private Node getRx() {
        return rx;
    }

    private void setRx(Node rx) {
        this.rx = rx;
    }
}