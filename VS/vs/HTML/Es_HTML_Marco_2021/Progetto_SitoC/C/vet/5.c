/*11&gt; Dichiarare un vettore v dimensionato DIM 10.
caricamento esterno: richiesto un elemento controlli, prima di inserirlo nel vettore, 
se e' gia' presente, nel qual caso chieda che l'elemento sia digitato di nuovo.
LEGENDA:
v1=numeri inseriti, v2=copia per controllo, i,j=contatori
*/
#include &lt;stdio.h&gt;
#define DIM 10
int main()
{
	int v1[DIM],v2[DIM],i,j,flag;
	i=0;
	while(i&lt;DIM){ 	//for iniziale //mai toccare la i
			printf("Inserisci n %d: ", i);	//input
			scanf("%d", &v1[i]);
			fflush(stdin);	
			v2[i]=v1[i];	//copia in v2 per controllo
			flag=1;
			for(j=0;j&lt;i && flag==1;j++){	//ciclo controllo		
				if(v1[i]==v2[j]){	//condizione controllo
					flag=0;
					//j=DIM+1; 	Controllo non necessario
				}
			}
			if(flag==1){
				i++;
			}	
	}
	//ciclo di visulizzazione
	for(i=0;i&lt;DIM;i++){
		printf("%d ", v1[i]);
	}
	return 0;
}
