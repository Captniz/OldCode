import java.util.*;
import java.io.*;

class tre{
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
				progressivo(P1);
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
	
	public static void progressivo(Stack<Integer> P1){
		Stack<Integer> P2 = new Stack<Integer>();
		int ctr=0;
		int tmp=0;
		
		while(!P1.isEmpty()){
			P2.push(P1.pop());
		}
		
		while(!P2.isEmpty()){
			tmp=P2.pop();
			P1.push(tmp);
			ctr+=tmp;
			P1.push(ctr);
		}
		
	}
}
