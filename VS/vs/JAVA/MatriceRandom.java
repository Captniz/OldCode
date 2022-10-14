import java.util.Random;
class MatriceRandom{
	public static void main(String[] args){
		int v[][] = new int [10][10];
		int min[]= {0,0};
		Random rnd = new Random();
		
		for(int i=0; i<10;i++){
			for(int j=0; j<10;j++){
				v[i][j]=rnd.nextInt(1000)+1;
				if(v[i][j]<v[min[0]][min[1]]){
					min[0]=i;
					min[1]=j;
				}
			}
		}

		for(int i=0; i<10;i++){
			for(int j=0; j<10;j++){
				if((v[i][j]/1000)!=0){
					System.out.print(v[i][j]);
				}else if((v[i][j]/100)!=0){
					System.out.print(" " + v[i][j]);
				}else if((v[i][j]/10)!=0){
					System.out.print("  " + v[i][j]);
				}else{
					System.out.print("   " + v[i][j]);
				}
			}
			System.out.print("\n");
		}
		System.out.print("\n\n");
		
		for (int i = 0; i < 10; i++) {
			v[min[0]][i]=0;
		}
		
		for(int i=0; i<10;i++){
			for(int j=0; j<10;j++){
				if((v[i][j]/1000)!=0){
					System.out.print(v[i][j]);
				}else if((v[i][j]/100)!=0){
					System.out.print(" " + v[i][j]);
				}else if((v[i][j]/10)!=0){
					System.out.print("  " + v[i][j]);
				}else{
					System.out.print("   " + v[i][j]);
				}
			}
			System.out.print("\n");
		}
	}
}