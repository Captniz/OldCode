/*12&gt; Caricare un vettore v dimensionato 15 con in primi 15 numeri primi.
*/
#include &lt;stdio.h&gt;
#define DIM 15
int main(){
	int v[DIM],i,c=1,cdiv=0,flag=0,j;
	for(i=0;i&lt;DIM;i++)	{
		flag=0;
		do{
			cdiv=0;
			for(j=2;j&lt;=c;j++){
				if(c%j==0){
					cdiv++;
				}
			}
			if(cdiv==1){
				v[i]=c;
				flag=1;
			}
			c++;
		}while(flag==0);
	}
	for(i=0; i&lt;DIM; i++){
		printf("%3d\n", v[i]);
	}
	return 0;
}
