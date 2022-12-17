/*69&gt; Algoritmo ricorsivo per la visualizzazione di un vettore di interi
*/
#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;time.h&gt;
#define DIM 10
int visualizza(int [],int );
int main(){
	int v[DIM]={2,45,1,8,0,43,6,67,49,61};
	visualizza(v,0);
	return 0;
}
int visualizza(int v[DIM],int i){
	if(i==DIM){
		return 0;
	}else{
		printf("%4d",v[i]);
		return visualizza(v,i+1);
	}
}
