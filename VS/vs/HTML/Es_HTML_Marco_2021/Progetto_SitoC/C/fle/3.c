/*76> appendere "file2.txt" a "file1.txt" in un "fileall.txt" 
*/
#include<stdio.h>
#include<string.h>
int main()
{
	FILE *fp1,*fp2,*fp3;
	char car;
	fp1=fopen("file1.txt","r");
	fp2=fopen("file2.txt","r");
	fp3=fopen("fileall.txt","a");
	if(fp1==NULL || fp2==NULL || fp3==NULL){
		printf("ERRORE: file non trovato");
	}else{
		while((car=fgetc(fp1))!=EOF){
			fputc(car,fp3);
		}
		while((car=fgetc(fp2))!=EOF){
			fputc(car,fp3);
		}
		printf("Append avvenuto correttamente");
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	return 0;
}
