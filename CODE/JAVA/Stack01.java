import java.util.Stack;
import java.util.Random;

//Tardiani Simone 

public class Stack01{

	public static void main(String args[]){
		Stack<Integer> P1 = new Stack<Integer>();
		Stack<Integer> P2 = new Stack<Integer>();
		Random rnd = new Random();
		int n1=0;
		int n2=0;

		for(int i=0;i<10;i++){ P1.push(rnd.nextInt(10)+1); }
		System.out.println("P1 : " + P1);
		
		while(!P1.empty()){ P2.push(P1.pop()); }
		System.out.println("P2 : " + P2);
		
		n1=P2.pop();
		P1.push(n1);
		
		while(!P2.empty()){ P1.push(P2.pop()); }
		
		n2=P1.pop();
		P2.push(n2);
		
		while(!P1.empty()){ P2.push(P1.pop()); }
		P2.push(n1+n2);
		System.out.println("P2-v2 : " + P2);
	} 
}