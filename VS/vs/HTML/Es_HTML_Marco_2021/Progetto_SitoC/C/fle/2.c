/*75&gt; copiare un file "prova.txt" su un altro file "provacopy.txt"
*/
#include&lt;stdio.h&gt;
#include&lt;string.h&gt;
int main()
{
	FILE *fp,*fp2;
	int n,len;
	char buffer[100];
	fp=fopen("prova.txt","r");
	fp2=fopen("provacopy.txt","w");
	if(fp==NULL){
		printf("File non esistente");
	}else{
		do{
			n=fread(buffer,1,100,fp);
			len=strlen(buffer);
			if(n!=0){
				fwrite(buffer,1,len,fp2);
			}
		}while(n!=0);
	}
	fclose(fp);
	fclose(fp2);
	printf("Copia avvenuta correttamente");
	return 0;
}
