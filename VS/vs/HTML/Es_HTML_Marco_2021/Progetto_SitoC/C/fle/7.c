/*81> Fare l'operazione contraria: sostituire la stringa "effe" con il carattere 'f'.
es: caeffeeffettiera -> caffettiera 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fp,*fp2;
	fp=fopen("prova.txt","r");
	fp2=fopen("prova_new.txt","w");
	if(fp==NULL || fp2==NULL){
		perror("Errore");
		exit(1);
	}
	char buffer[100];
	int ctr,i,j;
	char s[]="effe";
	while(fscanf(fp,"%s",buffer)!=EOF){
		ctr=i=0;
		while(i<strlen(buffer)){
			if(buffer[i]==s[j]){
				ctr++;
				i++;
				j++;
				if(ctr%4==0){
					fputc('f',fp2);
					j=0;
					ctr=0;
				}
			}else{
				i=i-ctr;
				for(j=0;j<=ctr;j++){
					fputc(buffer[i],fp2);
					i++;
				}
				ctr=0;
				j=0;
			}
		}
	}
	printf("modifica avvenuta correttamente");
	fclose(fp);
	fclose(fp2);
	return 0;
}
