import java.util.*;
import java.io.*;

class due{
	public static void main(String args[]){
		String tmp = "";
		BufferedReader r;
		try{
			r = new BufferedReader(new FileReader("numeri.txt"));
			
			try{
				Queue<Integer> C1 = new LinkedList<Integer>();
				tmp = r.readLine();
				C1.add(Integer.parseInt(tmp));
				
				tmp = r.readLine();
				
				while(tmp!=null){
					C1.add(Integer.parseInt(tmp));
					tmp = r.readLine();
				}
				
				stampa(C1);
				moltiplica(C1,2);
				stampa(C1);
				
				
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
	
	public static void moltiplica(Queue<Integer> C1, int n){
		Queue<Integer> C2 = new LinkedList<Integer>();
		
		while(!C1.isEmpty()){
			C2.add(C1.remove() * n);
		}
		
		while(!C2.isEmpty()){
			C1.add(C2.remove());
		}
	}
}
