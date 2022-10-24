/*64> dato un array dimensionato DIM=10 di stringhe con lunghezza L=80 inserite esternamente
preparare il seguente menu
0 - escape
n - ordina le stringhe per nome in modo crescente
d - ordina le stringhe per lunghezza in modo crescente
v - ordina le stringhe contenenti piu' vocali in modo crescente 
*/
#include<stdio.h>
#include<string.h>
#define DIM 10
#define L 80
void carica(char [][L]);
void visualizza(char [][L]);
void sort1(char [][L]);
void sort2(char [][L]);
void sort3(char [][L]);
int main()
{
	char s[DIM][L],c;
	carica(s);
	visualizza(s);
	while(1){
		printf("0 - escape\n");
		printf("n - ordina le stringhe per nome in modo crescente\n");
		printf("d - ordina le stringhe per lunghezza in modo crescente\n");
		printf("v - ordina le stringhe contenenti piu' vocali in modo crescente\n");
		printf("inserire scelta: ");
		scanf("%c",&c);
		fflush(stdin);
		switch(c){
			case 'n':
				sort1(s);
				visualizza(s);
				break;
			case 'd':
				sort2(s);
				visualizza(s);
				break;
			case 'v':
				sort3(s);
				visualizza(s);
				break;
			case '0':
				return 0;
				break;
			default:
				printf("inserimento errato\n");
				break;
		}
	}
	return 0;
}
void carica(char s[DIM][L]){
	int i;
	for(i=0;i<DIM;i++){
		printf("inserire %d stringa: ",i+1);
		gets(s[i]);
	}
}
void visualizza(char s[DIM][L]){
	int i;
	for(i=0;i<DIM;i++){
		puts(s[i]);
	}
	putchar('\n');
}
void sort1(char s[DIM][L]){
	int i,j;
	char box[L];
	for(i=0;i<DIM;i++){
		for(j=i+1;j<DIM;j++){
			if(strcmp(s[i],s[j])>0){
				strcpy(box,s[i]);
				strcpy(s[i],s[j]);
				strcpy(s[j],box);
			}
		}
	}
}
void sort2(char s[DIM][L]){
	int i,j;
	char box[L];
	for(i=0;i<DIM;i++){
		for(j=i+1;j<DIM;j++){
			if(strlen(s[i])>strlen(s[j])){
				strcpy(box,s[i]);
				strcpy(s[i],s[j]);
				strcpy(s[j],box);
			}
		}
	}
}
void sort3(char s[DIM][L]){
	int i,j;
	int voc[DIM];
	char box[L];
	for(i=0;i<DIM;i++){
		voc[i]=0;
	}
	for(i=0;i<DIM;i++){
		j=0;
		while(j<strlen(s[i])){
			if(s[i][j]=='a' || s[i][j]=='e' || s[i][j]=='i' || s[i][j]=='o' || s[i][j]=='u' ||
		      s[i][j]=='A' || s[i][j]=='E' || s[i][j]=='I' || s[i][j]=='O' || s[i][j]=='U'){
		      	voc[i]++;
			}
			j++;
		}
	}
	int temp;
	for(i=0;i<DIM;i++){
		for(j=i+1;j<DIM;j++){
			if(voc[i]>voc[j]){
				strcpy(box,s[i]);
				strcpy(s[i],s[j]);
				strcpy(s[j],box);
				temp=voc[i];
				voc[i]=voc[j];
				voc[j]=temp;
			}
		}
	}
}
