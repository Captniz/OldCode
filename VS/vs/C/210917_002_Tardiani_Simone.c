//210717_002_Tardiani_Simone.c
//Inerire 10 num esternamente e dire se la loro somma e' maggiore di 100
#include<stdio.h>

int main(){
	
	int Somma=0;
	int Num=0;
	int i=0;
	
	while(i<10){		
	
		printf("Numero?:");
		scanf("%d",&Num);
		
		Somma=Somma+Num;
		
		i++;
		
		}
	
	if (Somma>100)
	{
		printf("La somma e' maggiore di 100");

	}else if (Somma=100)
	{
		printf("La somma e' uguale a 100");

	}else if (Somma<100)
	{
		printf("La somma e' minore di 100");
		
	}
	
	return 0;
}