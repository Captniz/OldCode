import java.util.*;
import java.io.*;

class quattro{
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
				minMax(C1);
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
	
	public static void minMax(Queue<Integer> C1){
		Queue<Integer> C2 = new LinkedList<Integer>();
		int min = 0;
		int max = 0;
		int tmp = 0;
		
		try{
			min = C1.remove();
			C2.add(min);
			max = C1.remove();
			C2.add(max);
		}catch(Exception e){
			System.out.println("Coda troppo corta per applicare questo metodo");
			return;
		}
		
		while(!C1.isEmpty()){
			tmp = C1.remove();
			if(tmp>max){
				max = tmp;
			}
			if(tmp<min){
				min = tmp;
			}
			C2.add(tmp);
		}
		
		while(!C2.isEmpty()){
			tmp = C2.remove();
			
			if(tmp == max){
				tmp = min;
			}else if(tmp == min){
				tmp = max;
			}
			C1.add(tmp);
		}
	}
}
