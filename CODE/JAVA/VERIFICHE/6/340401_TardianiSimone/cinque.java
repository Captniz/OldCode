import java.util.*;
import java.io.*;

class cinque{
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
				ordina(P1);
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
	
	public static void ordina(Stack<Integer> P1){
		Stack<Integer> P2 = new Stack<Integer>();
		Stack<Integer> P3 = new Stack<Integer>();
		int tmp = 0;
		int n=0;
		
		P2.push(P1.pop());
		while(!P1.isEmpty()){
			n = P1.pop();
			
			tmp = P2.pop();
			while(n>tmp && !P2.isEmpty()){
				P3.add(tmp);
				tmp = P2.pop();
			}
			if(n>tmp){
				P2.push(n);
				P3.add(tmp);	
			}else{
				P2.push(tmp);
				P3.add(n);
			}
			while(!P3.isEmpty()){
				P2.push(P3.pop());
			}
		}
		
		while(!P2.isEmpty()){
			P1.push(P2.pop());
		}
	}
}

