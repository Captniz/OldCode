/*80&gt; Dato un file si testo "prova.txt" riversare il file su un secondo file "prova2.txt",
ma al posto della 'f' va scritta la stringa "effe".
es: caffettiera -&gt; caeffeeffettiera
*/
#include&lt;stdio.h&gt;
int main()
{
	FILE *fp,*fp2;
	fp=fopen("prova.txt","r");
	fp2=fopen("prova_new.txt","w");
	if(fp==NULL){
		perror("Errore: File non trovato");
	}else{
		int car;
		while((car=fgetc(fp))!=EOF){
			if(car=='f'){
				fprintf(fp2,"%s","effe");
			}else{
				fputc(car,fp2);
			}
		}
		printf("modifica vvenuta correttamente");
		fclose(fp);
		fclose(fp2);
	}
	return 0;
}
