//Primo.java
import java.util.*;
public class MainVettore{
	public static void main(String args[]){
		int DIM=10;
		int v[] = new int [DIM];
		//int v[] = {1,2,3,5,6,7,8,9,4,10};
		Random rnd = new Random();
		
		for(int i=0;i<DIM;i++){
			v[i]=rnd.nextInt(10)+1;
			System.out.print(v[i] + " " );
		}
		System.out.print("\nOutput: ");
		getMaggiore(v);
	}
	
	static void getMaggiore(int v[]){
		int prevlen=0;
		int prevaddr=0;
		int len=1;
		int addr=0;

		for(int i=1;i<v.length;i++){
			if(v[i]==(v[(i-1)]+1)){
				len++;
			}else{
				if(len>prevlen){
					prevlen=len;
					prevaddr=addr;
				}
				len=1;
				addr=i;
			}
		}

		//Check finale per evitare errori con seq fino a fine array
		if(len>prevlen){
			prevlen=len;
			prevaddr=addr;
		}
		
		for(int i=prevaddr;i<(prevlen+prevaddr);i++){
			System.out.print(v[i] + " " );
		}
	}
}
//lista (lineare e non),grafo,coda,pila,tree,bin-tree, diff tra concrete e abstract DT