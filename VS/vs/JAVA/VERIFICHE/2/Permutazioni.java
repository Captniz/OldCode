import java.util.Random;
public class Permutazioni{
	public static void main(String[] args){
		Random rnd= new Random();
		int tmp;
		boolean flag;
		int v[] = new int [10];
		for(int i=0; i<10;i++){
			for(int j=0; j<10;j++){
				do{
					flag=false;
					tmp=rnd.nextInt(10)+1;
					for(int k=0;k<j;k++){
						if(tmp==v[k]){
							flag=true;
						}
					}
				}while(flag);
				v[j]=tmp;
			}
			
			for(int j=0;j<10;j++){
				System.out.print(v[j] + " ");
			}
			System.out.print("\n\n");
		}
		
	}
}
