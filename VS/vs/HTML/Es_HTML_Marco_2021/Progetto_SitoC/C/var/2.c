/*2&gt; inserire 10 numeri esternamente
dire se la loro somma e' maggiore/minore/uguale di 100    
n=numero s=somma c=contatore*/
#include &lt;stdio.h&gt;
int main()
{
	int n,s,c;
	for(c=0;c&lt;10;c++){
		printf("Inserisci numero: ");
		scanf("%d", &n);
		fflush(stdin);
		s=s+n;
	}	
	if(s&gt;100){
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
