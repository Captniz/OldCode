/*2> inserire 10 numeri esternamente
dire se la loro somma e' maggiore/minore/uguale di 100    
n=numero s=somma c=contatore*/
#include <stdio.h>
int main()
{
	int n,s,c;
	for(c=0;c<10;c++){
		printf("Inserisci numero: ");
		scanf("%d", &n);
		fflush(stdin);
		s=s+n;
	}	
	if(s>100){
		printf("La somma = %d e' maggiore di 100!", s);
	}else{
		if(s==100){
			printf("La somma = %d e' uguale 100!", s);
		}else{
			printf("La somma = %d e' minore a 100!", s);	
		}
	}
	return 0;
}
