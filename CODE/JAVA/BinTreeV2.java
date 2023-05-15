import java.util.*;

public class BinTreeV2 {
    private class Node {
        
        int data;
        Node left;
        Node right;

        public Node(int val) {
            data = val;
            left = null;
            right = null;
        }

        public Node find(int val) {
            if (data == val) {
                return this;
            } else if (val > data && right != null) {
                return right.find(val);
            } else if (left != null) {
                return left.find(val);
            }
            return null;
        }

        static public void delete(Node node) {
            Queue<Node> q = new LinkedList<Node>();
            Node tmp;
            if(node.left == null && node.right == null){
                node = null;
                return;
            }
            if(node.left != null){
                q.add(node.left);
                node.left = null;
            }
            if(node.right != null){
                q.add(node.right);
                node.right = null;
            }
            tmp = q.remove();
            node.data = tmp.data;

            node.insert(tmp);
            while(!q.isEmpty()){
                node.insert(q.remove());
            }
        }
        public void insert(int val) {
            if (data > val) {
                if (left == null) {
                    left = new Node(val);
                } else {
                    left.insert(val);
                }
            } else if (data < val) {
                if (right == null) {
                    right = new Node(val);
                } else {
                    right.insert(val);
                }
            }
            return;
        }

        public void insert(Node val) {
            if (data > val.data) {
                if (left == null) {
                    left = val;
                } else {
                    left.insert(val);
                }
            } else if (data < val.data) {
                if (right == null) {
                    right = val;
                } else {
                    right.insert(val);
                }
            }
            return;
        }

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

    public BinTreeV2() {
        root = null;
    }

    public BinTreeV2(int rootdata) {
        root = new Node(rootdata);
    }

    public Node find(int data) {
        if(root!=null){
            return root.find(data);
        }
        return null;
    }

    public void delete(int data) {
        Node.delete(root.find(data));
    }

    public void insert(int data) {
        if(root!=null){
            root.insert(data);
        }else{
            root = new Node(data);
        }
        return;
    }

    public void insert(Node data) {
        if(root!=null){
            root.insert(data);
        }else{
            root = data;
        }
        return;
    }

    public void visitaSimmetrica() {
        root.visitaSimmetrica();
    }

    public void visitaAnticipata() {
        root.visitaAnticipata();
    }

    public void visitaPosticipata() {
        root.visitaPosticipata();
    }

    public void stampaLinee() {
        root.stampaLinee(root, 0);
    }
}
