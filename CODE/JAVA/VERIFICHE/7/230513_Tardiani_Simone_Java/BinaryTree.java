import java.io.IOException;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.BufferedReader;
import java.io.FileReader;

public class BinaryTree {
    private static class Node {
        int data;
        Node left;
        Node right;
        public Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
        
        public void insert(int data){
			if(data<this.data ){
				if(this.left!=null){
					this.left.insert(data);
				}else{
					this.left = new Node(data);
				}
			}else if(data>this.data){
				if(this.right!=null){
					this.right.insert(data);
				}else{
					this.right = new Node(data);
				}
			}
			return;
		}
		
		public int sommaFoglie(){
			int sum = 0;
			if(this.left==null && this.right==null){
				return data;
			}
			if(this.left!=null){
				sum = sum + left.sommaFoglie();
			}
			if(this.right!=null){
				sum = sum + right.sommaFoglie();
			}
			return sum;
		}
		
		public int somma(){
			int sum = 0;
			if(this.left==null && this.right==null){
				return data;
			}
			if(this.left!=null){
				sum = sum + left.sommaFoglie();
			}
			if(this.right!=null){
				sum = sum + right.sommaFoglie();
			}
			return sum + this.data;
		}
		
		public boolean find(int data){
			if(data<this.data){
				if(this.left !=null){
					return this.left.find(data);
				}else{
					return false;
				}
			}else if(data>this.data){
				if(this.right !=null){
					return this.right.find(data);
				}else{
					return false;
				}
			}else{
				return true;
			}
		}
    
		public void cancellaFoglie(){
			Node tmp;
			if(this.left!=null){
				tmp = this.left;
				if(tmp.left == null && tmp.right == null){
					this.left = null;
				}else{
					tmp.cancellaFoglie();
				}
			}
			if(this.right!=null){
				tmp = this.right;
				if(tmp.left == null && tmp.right == null){
					this.right = null;
				}else{
					tmp.cancellaFoglie();
				}
			}
			return;
		}
    
		public int alberoDue(){
			if(this.left!=null && this.right!=null){
				if((this.left.alberoDue() == 1) && (this.right.alberoDue() == 1)){
					return 1;
				}else{
					return 0;
				}
			}else if(this.left==null && this.right==null){
				return 1;
			}
			return 0;
		}
    }
    
    Node root; 
    
    public BinaryTree() {
        root = null;
    }
    
    public void insertFile(String filename) {
		try{
            BufferedReader in = new BufferedReader(new FileReader(filename));
            String line;
            if((line = in.readLine()) == null){
                System.out.println("Errore file vuoto");
                return;
            }
            do{
                insert(Integer.parseInt(line));
            }while((line = in.readLine()) != null);
        }catch(FileNotFoundException ex){
            System.out.println("Errore apertura file (File non trovato)");
			System.exit(1);
        }catch(IOException ex){
            System.out.println("Errore lettura file");
            System.exit(1);
        }
    }
    
    private void printNode(Node node, String prefix, boolean isTail) { 
                                                                     
        if (node == null) { 
            return;
        }
        if (node.right != null) { 
                                 
            printNode(node.right, prefix + (isTail ? "-   " : "    "), false);
        }
        System.out.print(prefix);
        System.out.print(isTail ? "--- " : "--- "); 
        System.out.println(node.data); 
        if (node.left != null) {
                                
            printNode(node.left, prefix + (isTail ? "    " : "-   "), true);
        }
    }
    
    public void print() { 
        printNode(root, "", true); 
    }
    
    public void insert(int data){
		if(root != null){
			root.insert(data);
		}else{
			root = new Node(data);
		}
		return;
	}
	
	public int sommaFoglie(){
		if(root != null){
			return root.sommaFoglie();
		}
		return 0;
	}

	public void cancellaFoglieSinistra(){
		if(root != null && root.left!=null){
			root.left.cancellaFoglie();
		}
		return;
	}
	
	public int sinistraInside(){
		if(root!=null && root.left != null && root.right != null){
			if(root.right.find(root.left.somma())){
				return 1;
			}
		}
		return 0;
	}

	public int alberoDue(){
		if(root!=null){
			return root.alberoDue();
		}
		return 0;
	}
}
