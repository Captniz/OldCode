public class Fusione{
	Fusione(){
	}
	
	public void sort(int v[]){
		int tmp=0;
		for(int i=0; i<(v.length-1);i++){
			for(int j=(i+1); j<v.length;j++){
				if(v[i]>v[j]){
					tmp=v[i];
					v[i]=v[j];
					v[j]=tmp;
				}
			}
		}	
	}
	
	
	public void printA(int v[]){
		for(int i=0; i<(v.length);i++){
			if(v[i]!=0){
			System.out.print(v[i] + " ");
			}
		}	
	}
	
	public void merge(int v1[], int v2[], int v3[]){
		int ctr1=0;
		int ctr2=0;
		int ctr3=0;
		int tmp1=0;
		int tmp2=0;
			
			while(ctr1!=v1.length && ctr2!=v2.length ){
				if(v1[ctr1]<v2[ctr2]){
					v3[ctr3]=v1[ctr1];
					ctr1++;
					ctr3++;
				} else if(v1[ctr1]>v2[ctr2]){
					v3[ctr3]=v2[ctr2];
					ctr2++;
					ctr3++;
				}else {
					tmp1=0;
					tmp2=0;
					while((ctr1+tmp1)<v1.length && v1[(ctr1+tmp1)]==v2[ctr2] ){
						tmp1++; 
						
					}
					while((ctr2+tmp2)<v2.length && v2[(ctr2+tmp2)]==v1[ctr1] ){
						tmp2++; 
					}
					if(tmp1>tmp2){
						for(int i=0; i<tmp1;i++){
							v3[ctr3]=v1[ctr1];
							ctr3++;
						}
					}else{
						for(int i=0; i<tmp2;i++){
							v3[ctr3]=v1[ctr1];	
							ctr3++;
						}
					}
					ctr1+=(tmp1);
					ctr2+=(tmp2);
					}
			}
		if(ctr1==v1.length){
			while(ctr2<v2.length){
				v3[ctr3]=v2[ctr2];
				ctr2++;
				ctr3++;
			}
		}else{
			while(ctr1<v1.length){
				v3[ctr3]=v1[ctr1];
				ctr1++;
				ctr3++;
			}
		}
	}
}
