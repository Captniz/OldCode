#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	char lettera;
	int pos_inizio,pos_fine,c;
	char nome_file[]="prova.txt";
	fp=fopen(nome_file,"r+");
	if(fp==NULL){ perror("Errore"); exit(1); }
	c=0;
	pos_inizio=ftell(fp);
	while(fread(&lettera,sizeof(char),1,fp)!=0){
		//printf("%c",lettera);
		lettera='!';
		pos_fine=ftell(fp);
		fseek(fp,pos_inizio+c,SEEK_SET);
		fwrite(&lettera,1,1,fp);
		fseek(fp,pos_fine,SEEK_SET);
		c++;
	}
	
	fclose(fp);
	return 0;
}
