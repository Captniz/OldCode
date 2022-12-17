/*65&gt;
Dato un numero n inserito esternamente calcolare la somma dei primi N numeri pari (&gt;0) 
positivi in maniera ricorsiva.
*/
#include&lt;stdio.h&gt;
int somma_pari(int );
int main(){
	int n,som;
	printf("inserisci un numero: ");
	scanf("%d",&n);
	fflush(stdin);
	printf("la somma dei primi %d numeri pari e': %d",n,somma_pari(n));
	return 0;
}
int somma_pari(int n){
	if(n==1)
		return n*2;
	else
		return (n*2+somma_pari(n-1));
	
}
