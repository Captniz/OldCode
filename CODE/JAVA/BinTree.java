import java.util.*;

public class BinTree {
    /*
     * Tree model -> L - ROOT - R : (Standard)
     * Primitive methods:
     * - find(int) : Object -> Returns the node with the specified value.
     * - insert(int) : void -> Inserts a node with the specified value.
     * - insert(Node) : void -> Inserts a node, (Must have aleady a value assigned).
     * - delete(void) : void -> Deletes the node and re-attaches his child nodes.
     *
     * Non-primitive methods:
     * - visitaSimmetrica() : void -> Prints the tree in ascending order.
     **/

    // ##############################################
    // # ATTRIBUTES #
    // ##############################################

    Node root;

    // ##############################################
    // # CONSTRUCTORS #
    // ##############################################

    /*
     * Empty constructor
     */
    public BinTree() {
        root = new Node();
    }

    /*
     * Parametered constructor
     * Summary:
     * Gives a value to the root.
     * Parameters:
     * - int val -> Value of the root
     */
    public BinTree(int rootValue) {
        root = new Node(rootValue, null);
    }

    // ##############################################
    // # PRIMITIVES #
    // ##############################################

    /*
     * Method Find()
     * Summary:
     * Find a node given the specified value, does not support multiple nodes with
     * the same value.
     * Parameters:
     * - int val -> Value to find in the tree
     * Returns:
     * - Node tmp -> Node found in the tree with the value in input
     * Exceptions:
     * - NoSuchElementException -> If the value is not found
     */
    public Node find(int value) {
        return root.find(value);
    }

    /*
     * Method Delete()
     * Summary:
     * Deletes a node given its value and re-attaches his child nodes to
     * the tree, does not support multiple nodes with the same value.
     * Exceptions:
     * - NoSuchElementException -> If the node is the root and it has no childs
     */
    public void delete(int value) {
        root.find(value).delete();
    }

    /*
     * Method Insert() -> Value
     * Summary:
     * Insert a node in the tree giving only the value of the node.
     * If a node is already present it will do nothing.
     * Parameters:
     * - int val -> Value of the node to insert in the tree
     */
    public void insert(int value) {
        root.insert(value);
    }

    /*
     * Method Insert() -> Node
     * Summary:
     * Insert a node in the tree, the node must aleady have a value assigned.
     * If a node is already present it will do nothing.
     * !SHOULDN'T BE USED! Use the other Insert() method instead.
     * Parameters:
     * - Node val -> Node to insert in the tree
     */
    public void insert(Node value) {
        root.insert(value);
    }

    // ##############################################
    // # NOT-PRIMITIVES #
    // ##############################################

    /*
     * Method visitaSimmetrica()
     * Summary:
     * Print the tree starting from the left side to the right, resulting in an
     * ascending ordered print.
     */
    public void visitaSimmetrica() {
        root.visitaSimmetrica();
    }

    /*
     * Method visitaAnticipata()
     * Summary:
     * Prints first the root node, then the left node and finally the right node.
     */
    public void visitaAnticipata() {
        root.visitaAnticipata();
    }

    /*
     * Method visitaPosticipata()
     * Summary:
     * Prints first the left node, then the right node and finally the root node.
     */
    public void visitaPosticipata() {
        root.visitaPosticipata();
    }
}

class Node {
    /*
     * Summary:
     * Single node of the tree.
     * Primitive methods:
     * - find(int) : Object -> Returns the node with the specified value.
     * - insert(int) : void -> Inserts a node with the specified value.
     * - insert(Node) : void -> Inserts a node, (Must have aleady a value assigned).
     * - delete(void) : void -> Deletes the node and re-attaches his child nodes.
     *
     * Non-primitive methods:
     * - visitaSimmetrica() : void -> Prints the tree in ascending order.
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
    // The father node
    Node father;

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
        father = null;
    }

    /*
     * Parametered constructor
     * Summary:
     * Gives a value to the node.
     * Parameters:
     * - int val -> Value of the node
     */
    public Node(int val, Node fath) {
        value = val;
        lx = null;
        rx = null;
        self = this;
        father = fath;
    }

    // ##############################################
    // # PRIMITIVES #
    // ##############################################

    /*
     * Method Find()
     * Summary:
     * Find a node given the specified value, does not support multiple nodes with
     * the same value.
     * Can be used on any node but bare in mind that it will only search the node
     * and
     * its childs, so its always better to use it on the root.
     * Parameters:
     * - int val -> Value to find in the tree
     * Returns:
     * - Node tmp -> Node found in the tree with the value in input
     * Exceptions:
     * - NoSuchElementException -> If the value is not found
     */
    public Node find(int val) {
        // If the value of this node is equal to the value we are searching for, return
        // the node itself.
        if (value == val) {
            return self;
        } else if (val > getValue() && getRx() != null) {
            try {
                return rx.find(val);
            } catch (NoSuchElementException e) {
            }
        } else if (getLx() != null) {
            try {
                return lx.find(val);
            } catch (NoSuchElementException e) {
            }
        }
        throw new NoSuchElementException("Node not found");
    }

    /*
     * Method Delete()
     * Summary:
     * Deletes the node and re-attaches his child nodes to
     * the tree, does not support multiple nodes with
     * the same value.
     * Can be used on any node, including the root.
     * Exceptions:
     * - NoSuchElementException -> If the node is the root and it has no childs
     */
    public void delete() {
        if (rx != null) {
            // Get the value of the branch to the right and put it in this node
            setValue(rx.getValue());

            Queue<Node> queue = new LinkedList<Node>();
            if (rx.getRx() != null) {
                queue.add(rx.getRx());
            }
            if (rx.getLx() != null) {
                queue.add(rx.getLx());
            }
            if (lx != null) {
                queue.add(lx);
            }
            rx = null;
            lx = null;

            while (!queue.isEmpty()) {
                insert(queue.remove());
            }
            return;
        } else if (lx != null) {
            // Get the value of the branch to the left and put it in this node
            setValue(lx.getValue());

            Queue<Node> queue = new LinkedList<Node>();
            if (lx.getRx() != null) {
                queue.add(lx.getRx());
            }
            if (lx.getLx() != null) {
                queue.add(lx.getLx());
            }
            rx = null;
            lx = null;

            while (!queue.isEmpty()) {
                insert(queue.remove());
            }
            return;
        } else {
            if (father != null) {
                if (father.getRx().getValue() == getValue()) {
                    father.setRx(null);
                } else {
                    father.setLx(null);
                }
                return;
            }
            throw new NoSuchElementException("Cannot delete last root node");
        }
    }

    /*
     * Method Insert() -> Value
     * Summary:
     * Insert a node in the tree giving only the value of the node.
     * If a node is already present it will do nothing.
     * !SHOULD BE USED ONLY ON THE ROOT! Using this method on other nodes will
     * result in the node possibly being inserted in the wrong place.
     * Parameters:
     * - int val -> Value of the node to insert in the tree
     */
    public void insert(int val) {
        // Check the value of the current node, and determine if it should go to the
        // left ( lesser ) or to the right ( greater ).
        if (value > val) {
            // If the child node of the side determined is not present, insert the node.
            if (lx == null) {
                setLx(new Node(val, self));
            } else {
                lx.insert(val);
            }
        } else if (value < val) {
            if (rx == null) {
                setRx(new Node(val, self));
            } else {
                rx.insert(val);
            }
        }
        return;
    }

    /*
     * Method Insert() -> Node
     * Summary:
     * Insert a node in the tree, the node must aleady have a value assigned.
     * If a node is already present it will do nothing.
     * !SHOULDN'T BE USED! Use the other Insert() method instead.
     * !SHOULD BE USED ONLY ON THE ROOT! Using this method on other nodes will
     * result in the node possibly being inserted in the wrong place.
     * Parameters:
     * - Node val -> Node to insert in the tree
     */
    public void insert(Node val) {
        // Check the value of the current node, and determine if it should go to the
        // left ( lesser ) or to the right ( greater ).
        if (value > val.getValue()) {
            // If the child node of the side determined is not present, insert the node.
            if (lx == null) {
                setLx(val);
            } else {
                lx.insert(val);
            }
        } else if (value < val.getValue()) {
            if (rx == null) {
                setRx(val);
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
     * Method visitaSimmetrica()
     * Summary:
     * Print the tree starting from the left side to the right, resulting in an
     * ascending ordered print.
     * Can be used on any node but bare in mind that it will only print the node and
     * its childs, so its always better to use it on the root.
     */
    public void visitaSimmetrica() {
        if (lx != null) {
            lx.visitaSimmetrica();
        }
        System.out.print(value + " ");
        if (rx != null) {
            rx.visitaSimmetrica();
        }
        return;
    }

    /*
     * Method visitaAnticipata()
     * Summary:
     * Prints first the root node, then the left node and finally the right node.
     * Can be used on any node but bare in mind that it will only print the node and
     * its childs, so its always better to use it on the root.
     */
    public void visitaAnticipata() {
        System.out.print(value + " ");
        if (lx != null) {
            lx.visitaAnticipata();
        }
        if (rx != null) {
            rx.visitaAnticipata();
        }
        return;
    }

    /*
     * Method visitaPosticipata()
     * Summary:
     * Print the tree starting from the left side to the right, resulting in an
     * ascending ordered print.
     * Can be used on any node but bare in mind that it will only print the node and
     * its childs, so its always better to use it on the root.
     * 
     */
    public void visitaPosticipata() {
        if (lx != null) {
            lx.visitaPosticipata();
        } else {
            System.out.print(value + " ");
            return;
        }
        if (rx != null) {
            rx.visitaPosticipata();
        } else {
            System.out.print(value + " ");
            return;
        }
        System.out.print(value + " ");
    }

    // ##############################################
    // # GETTERS & SETTERS #
    // ##############################################

    public int getValue() {
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
