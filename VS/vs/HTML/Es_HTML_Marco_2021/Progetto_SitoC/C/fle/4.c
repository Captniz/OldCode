/*77&gt; leggere un file "numeri.txt" e vedere quante cifre [0..9] ci sono 
*/
#include&lt;stdio.h&gt;
int main()
{
	FILE *fp;
	char car;
	int ctr;
	ctr=0;
	fp=fopen("numeri.txt","r");
	if(fp==NULL){
		printf("ERRORE: file non trovato");
	}else{
		while((car=fgetc(fp))!=EOF){
			if(car&gt;='0' && car&lt;='9'){
				ctr++;
			}
		}
		printf("Lettura avvenuta correttamente");
		printf("\nCifre presenti nel file %s: %d","numeri.txt",ctr);
	}
	fclose(fp);
}
