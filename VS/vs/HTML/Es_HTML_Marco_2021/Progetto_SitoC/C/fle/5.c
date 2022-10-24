/*78> Creare un file "ricordi.old" tutto minuscolo.
Cambiare il primo carattere di ogni paragrafo in maiuscolo 
(paragrafo: si va a capo dopo il punto).
*/
#include<stdio.h>
int main()
{
	FILE *fp;
	int car;
	fp=fopen("ricordi.old","w");
	if(fp==NULL){
		printf("Errore\n");
	}
	else{
		printf("inserire testo (in minuscolo): ");
		int maiusc=0;
		while((car=getchar())!='\n'){
			if(maiusc==1){
				fputc('\n',fp);
				if(car>='a' && car<='z'){
					car=car-32;
					maiusc=0;
				}
			}
			if(car=='.'){
				maiusc=1;
			}
			fputc(car,fp);//scrittura su file
		}
		printf("scrittura sul file %s avvenuta correttamente","ricordi.old");
		fclose(fp);
	}
	return 0;
}
