/*66&gt; Calcolare il massimo di un vettore v dimensionato DIM con procedimento ricorsivo.
*/
#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;time.h&gt;
#define DIM 5
void carica(int []);
void visualizza(int []);
int massimo(int [],int ,int );
int main()
{
	srand(time(NULL));
	int v[DIM];
	int max,i;
	carica(v);
	visualizza(v);
	max=v[0];
	i=0;
	printf("\nil valore massimo dell'array e': %d",massimo(v,max,i));
	return 0;
}
void carica(int v[DIM]){
	int i;
	for(i=0;i&lt;DIM;i++){
		v[i]=rand()%50+1;
	}
}
void visualizza(int v[DIM]){
	int i;
	for(i=0;i&lt;DIM;i++){
		printf("%4d",v[i]);
	}
}
int massimo(int v[DIM], int max, int i){
	if(i==DIM){
		return max;
	}else{
		if(v[i]&gt;max){
			max=massimo(v,v[i],i+1);
		}else{
			max=massimo(v,max,i+1);
		}
	}
}
