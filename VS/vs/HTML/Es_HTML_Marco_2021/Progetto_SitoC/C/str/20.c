/*49> Dato un array s dimensionato DIM di stringhe dimensionate L, scrivere una funzione 
int confronta(char [][L])
che ritorna il numero di stringhe uguali.*/
#include<stdio.h>
#include<string.h>
#define DIM 5
#define L 80
void carica(char [][L]);
int confronta(char [][L]);
int main()
{
	char s[DIM][L];
	int ctr;
	carica(s);
	ctr=confronta(s);
	printf("il numero di stringhe uguali e': %d",ctr);
	return 0;
}
void carica(char s[][L]){
	int i;
	for(i=0;i<DIM;i++){
		printf("%d stringa: ",i+1);
		gets(s[i]);
		fflush(stdin);
	}
}
int confronta(char s[DIM][L]){
	int i,j,ctr,c;
	ctr=0;
	for(i=0;i<DIM;i++){
		c=0;
		for(j=0;j<DIM;j++){
			if(strcmp(s[i],s[j])==0){
				c++;
			}
		}
		if(c>=2){
			ctr++;
		}
	}
	putchar('\n');
	return ctr;
}
