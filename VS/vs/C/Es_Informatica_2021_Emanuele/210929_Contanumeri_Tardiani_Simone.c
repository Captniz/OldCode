//210929_Contanumeri_Tardiani_Simone.c
//Analizza una sequenza di numeri interi: Letti un numero N di numeri a schermo si stampa:
//Quanti sono i numeri positivi, nulli e negativi
//Quanti sono i numeri pari e dispari
#include<stdio.h>

int main () {
	int NInput=0, i, N, Npari, Ndispari, Nneg, Nnul, Npos;
	i=0;
	N=0;
	Npari=0;
	Ndispari=0;
	Nneg=0;
	Nnul=0;
	Npos=0;
	
	printf("Numeri da mettere in input:");
	scanf("%d",&NInput);
	while(getchar()!='\n');
	
	for(i=0;i<NInput;i++){
		printf("Numero %d:",i+1);
		scanf("%d",&N);
		while(getchar()!='\n');
		
		if(N%2==0 && N!=0){
			Npari++;
		}else{
			if(N%2!=0 && N!=0){
				Ndispari++;
			}else{
				Nnul++;
			}
		}
		
		if(N<0){
			Nneg++;
		}else{
			if(N>0){
				Npos++;
			}
		}
	}
		printf("\n");
		printf("N pari:%d",Npari);
		printf("\nN dispari:%d",Ndispari);
		printf("\nN positivi:%d",Npos);
		printf("\nN negativi:%d",Nneg);
		printf("\nN nulli:%d",Nnul);
		return 0;
}
