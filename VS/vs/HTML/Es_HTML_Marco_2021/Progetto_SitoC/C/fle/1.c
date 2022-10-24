/*74> leggere un file "prova.txt" e visualizzarlo 
*/
#include<stdio.h>
#include<string.h>
int main()
{
	FILE *fp;
	char car;
	fp=fopen("prova.txt","r");
	if(fp==NULL){
		printf("File non esistente");
	}else{
		while((car=fgetc(fp))!=EOF){
			putchar(car);
		}
	}
	fclose(fp);
	return 0;
}
