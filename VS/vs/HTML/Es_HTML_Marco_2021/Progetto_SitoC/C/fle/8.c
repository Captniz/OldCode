/*82> dato un file "numeri.num" 
contare quante cifre ci sono e attaccarle a fine file.
(NB: il numero va scomposto nelle sue cifre prima di convertirlo in testo)
es: "prova di 12345 scrittura 123123 alla 0 fine."
-> "prova di 12345 scrittura 123123 alla 0 fine.12"
*/
#include<stdio.h>
#include<string.h>
#define DIM 100
int main()
{
	FILE *fp;
	fp=fopen("numeri.num","r+");
	char car;
	int ctr,temp,i;
	char s[DIM];
	ctr=0;
	while((car=fgetc(fp))!=EOF){
		if(car>='0' && car<='9'){
			ctr++;
		}
	}
	fseek(fp,0,2);
	i=0;
	while(ctr>0){
		temp=ctr%10;
		ctr=ctr/10;
		s[i]=temp+'0';
		i++;
	}
	for(i=strlen(s)-1;i>=0;i--){
		fputc(s[i],fp);
	}
	fclose(fp);
	return 0;
}
