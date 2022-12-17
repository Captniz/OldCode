/*74&gt; leggere un file "prova.txt" e visualizzarlo 
*/
#include&lt;stdio.h&gt;
#include&lt;string.h&gt;
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
