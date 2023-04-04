import java.util.*;
import java.io.*;

class sei{
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
				elimina(C1);
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
	
	public static void elimina(Queue<Integer> C1){
		Queue<Integer> C2 = new LinkedList<Integer>();
		Queue<Integer> C3 = new LinkedList<Integer>();
		int tmp=0;
		int tmp2=0;
		boolean flag = true;
		
		while(!C1.isEmpty()){
			tmp = C1.remove();
			while(!C2.isEmpty()){
				tmp2 = C2.remove();
				if(tmp ==tmp2){
					flag = false;
				}
				C3.add(tmp2);
			}
			while(!C3.isEmpty()){
				C2.add(C3.remove());
			}
			if(flag){
				C2.add(tmp);
			}
			flag = true;
		}
		
		while(!C2.isEmpty()){
			C1.add(C2.remove());
		}
	}
}
