import java.util.*;
import java.io.*;

class uno{
	public static void main(String args[]){
		String tmp = "";
		BufferedReader r;
		try{
			r = new BufferedReader(new FileReader("numeri.txt"));
			
			try{
				Stack<Integer> P1 = new Stack<Integer>();
				tmp = r.readLine();
				P1.push(Integer.parseInt(tmp));
				
				tmp = r.readLine();
				
				while(tmp!=null){
					P1.push(Integer.parseInt(tmp));
					tmp = r.readLine();
				}
				
				stampa(P1);
				moltiplica(P1,2);
				stampa(P1);
				
				
			}catch(Exception e){
				System.out.print("File vuoto");
				return;
			}
		}catch(Exception e){
			System.out.print("File inesistente");
			return;
		}
	}
	
	public static void stampa(Object o){
		System.out.println(o);
	}
	
	public static void moltiplica(Stack<Integer> P1, int n){
		Stack<Integer> P2 = new Stack<Integer>();
		
		while(!P1.isEmpty()){
			P2.push(P1.pop());
		}
		
		while(!P2.isEmpty()){
			P1.push((P2.pop() * n));
		}
		
	}
}
