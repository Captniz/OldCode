/*53&gt; Convertire numero decimale a un array dimensionato DIM=8 binario 
es: 7[10]=00000111
*/
#include&lt;stdio.h&gt;
#define DIM 8
int main(){
	int v[DIM],i,n;
	int r=0;
	do{
		printf("inserisci numero da convertire: ");
		scanf("%d",&n);
		fflush(stdin);
	}while(n&lt;0);
	for(i=0;i&lt;DIM;i++){	
		if(n%2==1){
			v[i]=1;
		}else{
			v[i]=0;
		}
		n=n/2;
	}
	for(i=DIM-1;i&gt;=0;i--){
		printf("%d ",v[i]);
	}
	return 0;
}
