/*68&gt; Scrivere una funzione ricorsiva che, dati due numeri interi n1 ed n2, 
restituisca la somma di tutti gli interi compresi tra n1 ed n2 estremi esclusi.
*/
#include&lt;stdio.h&gt;
int somma(int ,int ,int );
int main(){
	int n1,n2;
	printf("inserisci il primo numero: ");
	scanf("%d",&n1);
	fflush(stdin);
	do{
		printf("inserisci il secondo numero: ");
		scanf("%d",&n2);
		fflush(stdin);
	}while(n2&lt;=n1);
	n1++;
	printf("somma = %d",somma(n1,n2,0));
	return 0;
}
int somma(int n1,int n2,int sum){
	if(n1&gt;=n2){
		return sum;
	}else{
		sum=sum+n1;
		n1++;
		return somma(n1,n2,sum);
	}
}
