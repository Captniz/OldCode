import java.util.*;

public class BinaryTree {
    class Node {
        /*
         * Summary:
         * Single node of the tree.
         * Primitive methods:
         * - find(int) : Object -> Returns the node with the specified data.
         * - insert(int) : void -> Inserts a node with the specified data.
         * - insert(Node) : void -> Inserts a node, (Must have aleady a data assigned).
         * - delete(void) : void -> Deletes the node and re-attaches his child nodes.
         *
         * Non-primitive methods:
         * - visitaSimmetrica() : void -> Prints the tree in ascending order.
         **/
    
        // ##############################################
        // # ATTRIBUTES #
        // ##############################################
    
        // data of the node
        int data;
        // Child node to the left
        Node left;
        // Child node to the right
        Node right;
        // The father node
        Node father;
    
        // ##############################################
        // # CONSTRUCTORS #
        // ##############################################
    
        /*
         * Empty constructor
         */
        public Node() {
            data = 0;
            left = null;
            right = null;
            father = null;
        }
    
        /*
         * Parametered constructor
         * Summary:
         * Gives a data to the node.
         * Parameters:
         * - int val -> data of the node
         */
        public Node(int val, Node fath) {
            data = val;
            left = null;
            right = null;
            father = fath;
        }
    
        // ##############################################
        // # PRIMITIVES #
        // ##############################################
    
        /*
         * Method Find()
         * Summary:
         * Find a node given the specified data, does not support multiple nodes with
         * the same data.
         * Can be used on any node but bare in mind that it will only search the node
         * and
         * its childs, so its always better to use it on the root.
         * Parameters:
         * - int val -> data to find in the tree
         * Returns:
         * - Node tmp -> Node found in the tree with the data in input
         * Exceptions:
         * - NoSuchElementException -> If the data is not found
         */
        public Node find(int val) {
            // If the data of this node is equal to the data we are searching for, return
            // the node itself.
            if (data == val) {
                return this;
            } else if (val > data && right != null) {
                try {
                    return right.find(val);
                } catch (NoSuchElementException e) {
                }
            } else if (left != null) {
                try {
                    return left.find(val);
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
         * the same data.
         * Can be used on any node, including the root.
         * Exceptions:
         * - NoSuchElementException -> If the node is the root and it has no childs
         */
        // !NON PENSO SIA IL METODO MIGLIORE MA VA!
        public void delete() {
            if (right != null) {
                // Get the data of the branch to the right and put it in this node
                data = right.data;
    
                Queue<Node> queue = new LinkedList<Node>();
                if (right.right != null) {
                    queue.add(right.right);
                }
                if (right.left != null) {
                    queue.add(right.left);
                }
                if (left != null) {
                    queue.add(left);
                }
                right = null;
                left = null;
    
                while (!queue.isEmpty()) {
                    insert(queue.remove());
                }
                return;
            } else if (left != null) {
                // Get the data of the branch to the left and put it in this node
                data = left.data;
    
                Queue<Node> queue = new LinkedList<Node>();
                if (left.right != null) {
                    queue.add(left.right);
                }
                if (left.left != null) {
                    queue.add(left.left);
                }
                right = null;
                left = null;
    
                while (!queue.isEmpty()) {
                    insert(queue.remove());
                }
                return;
            } else {
                if (father != null) {
                    if (father.right.data == data) {
                        father.right = null;
                    } else {
                        father.left = null;
                    }
                    return;
                }
                throw new NoSuchElementException("Cannot delete last root node");
            }
        }
    
        /*
         * Method Insert() -> data
         * Summary:
         * Insert a node in the tree giving only the data of the node.
         * If a node is already present it will do nothing.
         * !SHOULD BE USED ONLY ON THE ROOT! Using this method on other nodes will
         * result in the node possibly being inserted in the wrong place.
         * Parameters:
         * - int val -> data of the node to insert in the tree
         */
        public int insert(int val) {
            // Check the data of the current node, and determine if it should go to the
            // left ( lesser ) or to the right ( greater ).
            if (data > val) {
                // If the child node of the side determined is not present, insert the node.
                if (left == null) {
                    left = new Node(val, this);
                    return 1;
                } else {
                    return left.insert(val) + 1;
                }
            } else if (data < val) {
                if (right == null) {
                    right = new Node(val, this);
                    return 1;
                } else {
                    return right.insert(val) + 1;
                }
            }
            return 1;
        }
    
        /*
         * Method Insert() -> Node
         * Summary:
         * Insert a node in the tree, the node must aleady have a data assigned.
         * If a node is already present it will do nothing.
         * !SHOULDN'T BE USED! Use the other Insert() method instead.
         * !SHOULD BE USED ONLY ON THE ROOT! Using this method on other nodes will
         * result in the node possibly being inserted in the wrong place.
         * Parameters:
         * - Node val -> Node to insert in the tree
         */
        public int insert(Node val) {
            // Check the data of the current node, and determine if it should go to the
            // left ( lesser ) or to the right ( greater ).
            if (data > val.data) {
                // If the child node of the side determined is not present, insert the node.
                if (left == null) {
                    left = val;
                    return 1;
                } else {
                    return left.insert(val) + 1;
                }
            } else if (data < val.data) {
                if (right == null) {
                    right = val;
                    return 1;
                } else {
                    return right.insert(val) + 1;
                }
            }
            // This is the only case where the node is not inserted, because it already
            // exists.
            return 1;
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
            if (left != null) {
                left.visitaSimmetrica();
            }
            System.out.print(data + " ");
            if (right != null) {
                right.visitaSimmetrica();
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
            System.out.print(data + " ");
            if (left != null) {
                left.visitaAnticipata();
            }
            if (right != null) {
                right.visitaAnticipata();
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
            if (left != null) {
                left.visitaPosticipata();
            } else {
                System.out.print(data + " ");
                return;
            }
            if (right != null) {
                right.visitaPosticipata();
            } else {
                System.out.print(data + " ");
                return;
            }
            System.out.print(data + " ");
        }
    
        /*
         * Method stampaLinee()
         * Summary:
         * Prints the tree in an ordered pyramid.
         */
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
    /*
     * Tree model -> L - ROOT - R : (Standard)
     * Primitive methods:
     * - find(int) : Object -> Returns the node with the specified data.
     * - insert(int) : void -> Inserts a node with the specified data.
     * - insert(Node) : void -> Inserts a node, (Must have aleady a data assigned).
     * - delete(void) : void -> Deletes the node and re-attaches his child nodes.
     *
     * Non-primitive methods:
     * - visitaSimmetrica() : void -> Prints the tree in ascending order.
     **/

    // ##############################################
    // # ATTRIBUTES #
    // ##############################################

    private Node root;
    private int height;

    // ##############################################
    // # CONSTRUCTORS #
    // ##############################################

    /*
     * Empty constructor
     */
    public BinaryTree() {
        root = new Node();
    }

    /*
     * Parametered constructor
     * Summary:
     * Gives a data to the root.
     * Parameters:
     * - int val -> data of the root
     */
    public BinaryTree(int rootdata) {
        root = new Node(rootdata, null);
    }

    // ##############################################
    // # PRIMITIVES #
    // ##############################################

    /*
     * Method Find()
     * Summary:
     * Find a node given the specified data, does not support multiple nodes with
     * the same data.
     * Parameters:
     * - int val -> data to find in the tree
     * Returns:
     * - Node tmp -> Node found in the tree with the data in input
     * Exceptions:
     * - NoSuchElementException -> If the data is not found
     */
    public Node find(int data) {
        return root.find(data);
    }

    /*
     * Method Delete()
     * Summary:
     * Deletes a node given its data and re-attaches his child nodes to
     * the tree, does not support multiple nodes with the same data.
     * Exceptions:
     * - NoSuchElementException -> If the node is the root and it has no childs
     */
    public void delete(int data) {
        root.find(data).delete();
    }

    /*
     * Method Insert() -> data
     * Summary:
     * Insert a node in the tree giving only the data of the node.
     * If a node is already present it will do nothing.
     * Parameters:
     * - int val -> data of the node to insert in the tree
     */
    public void insert(int data) {
        height = root.insert(data);
        return;
    }

    /*
     * Method Insert() -> Node
     * Summary:
     * Insert a node in the tree, the node must aleady have a data assigned.
     * If a node is already present it will do nothing.
     * !SHOULDN'T BE USED! Use the other Insert() method instead.
     * Parameters:
     * - Node val -> Node to insert in the tree
     */
    public void insert(Node data) {
        height = root.insert(data);
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

    /*
     * Method stampaPiramide()
     * Summary:
     * Prints the tree in an ordered pyramid.
     */
    public void stampaPiramide() {
        Queue<Node> queue = new LinkedList<Node>();
        queue.add(root);
        int ctr = 1;
        int ctrh = 0;
        for (int i = 0; i < height; i++) {
            System.out.print(" ");
        }
        while (!queue.isEmpty()) {
            ctr--;
            Node tmp = queue.remove();

            System.out.print(tmp.data + " ");
            for (int i = 0; i < (height - ctrh); i++) {
                System.out.print(" ");
            }

            if (tmp.left != null) {
                queue.add(tmp.left);
            }
            if (tmp.right != null) {
                queue.add(tmp.right);
            }

            if (ctr == 0) {
                ctrh++;
                ctr = queue.size();
                System.out.println();
                for (int i = 0; i < (height - ctrh); i++) {
                    System.out.print(" ");
                }
            }
        }
    }

    /*
     * Method stampaLinee()
     * Summary:
     * Prints the tree in an ordered pyramid.
     */
    public void stampaLinee() {
        root.stampaLinee(root, 0);
    }
}
