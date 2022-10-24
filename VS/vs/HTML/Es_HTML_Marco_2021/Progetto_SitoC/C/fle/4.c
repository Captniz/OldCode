/*77> leggere un file "numeri.txt" e vedere quante cifre [0..9] ci sono 
*/
#include<stdio.h>
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
			if(car>='0' && car<='9'){
				ctr++;
			}
		}
		printf("Lettura avvenuta correttamente");
		printf("\nCifre presenti nel file %s: %d","numeri.txt",ctr);
	}
	fclose(fp);
}
