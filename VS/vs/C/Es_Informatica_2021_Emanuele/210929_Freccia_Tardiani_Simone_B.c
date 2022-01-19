//210921_Freccia_Tardiani_Simone.c
//Crea una figura se il numero inserito e' >=3 ed e' dispari

#include<stdio.h>

int main(){
	
	int n,i,j,c;
	i=0;	
	j=0;	
	c=1;
	n=0;
	
	do{
		printf("Numero:");
		scanf("%d",&n);
	}while(n<3 || n%2==0);

	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{	                              
			if (i==(n-1)/2 || j==(n-1)/2 || (	j>((n-1)/2) && j<=((n-1)/2)+i && i<((n-1)/2)+1 && j<((n-1)/2)+1)	)
			{//TODO:non fare schifo
				putchar('*');
			}else{
				putchar('0');
			}
		}
		printf("\n");
	} 
	return 0;
}