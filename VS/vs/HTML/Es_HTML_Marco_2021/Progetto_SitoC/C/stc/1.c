/*73> In una classe sono memorizzati 10 studenti:
- cognome;
- nome;
- voto_info
- voto_condotta
Realizza un programma che implementi le seguenti funzionalità:
1. Inserimento dei dati dgli alunni;
2. dato il nominativo di un alunno permetta di modificare solo il voto di condotta
3. modifichi (incrementando o decrementando di un punto il voto di informatica di tutti gli alunni)
0. Esc
*/
#include<stdio.h>
#include<string.h>
#define DIM 3
struct classe{
	char cognome[80];
	char nome[80];
	int voto_info;
	int voto_condotta;
};
void carica(struct classe []);
void visualizza(struct classe []);
void modifica_condotta(struct classe []);
void modifica_info(struct classe []);
int main()
{
	struct classe v[DIM];
	int n;
	while(1){
		printf("1. Inserimento dei dati degli alunni;\n");
		printf("2. Dato il nominativo di un alunno permetta di modificare voto di condotta\n");
		printf("3. Modifichi (incrementando o decrementando di 1 il voto di informatica di tutti gli alunni)\n");
		printf("0. Esc\n");
		printf("Scelta: ");
		scanf("%d",&n);
		fflush(stdin);
		switch(n){
			case 1:
				carica(v);
				visualizza(v);
				break;
			case 2:
				modifica_condotta(v);
				visualizza(v);
				break;
			case 3:
				modifica_info(v);
				visualizza(v);
				break;
			case 0:
				return 0;
				break;
			default:
				printf("inserimento errato\n");
				break;
		}
	}
	return 0;
}
void carica(struct classe v[DIM]){
	int i;
	for(i=0;i<DIM;i++){
		printf("inserire il cognome del %d alunno: ",i+1);
		gets(v[i].cognome);
		fflush(stdin);
		printf("inserire il nome del %d alunno: ",i+1);
		gets(v[i].nome);
		fflush(stdin);
		printf("inserire il voto di info del %d alunno: ",i+1);
		scanf("%d",&v[i].voto_info);
		fflush(stdin);
		printf("inserire il voto di condotta del %d alunno: ",i+1);
		scanf("%d",&v[i].voto_condotta);
		fflush(stdin);
		putchar('\n');
		putchar('\n');
	}
}
void visualizza(struct classe v[DIM]){
	int i;
	for(i=0;i<DIM;i++){
		printf("%d studente",i+1);
		printf("\ncognome: ");
		puts(v[i].cognome);
		printf("nome: ");
		puts(v[i].nome);
		printf("voto info: %d",v[i].voto_info);
		printf("\nvoto condotta: %d",v[i].voto_condotta);
		putchar('\n');
		putchar('\n');
	}
}
void modifica_condotta(struct classe v[DIM]){
	int i;
	char nome_temp[80];
	char cognome_temp[80];
	int flag;
	flag=0;
	printf("inserire nominativo");
	printf("\nnome: ");
	gets(nome_temp);
	fflush(stdin);
	printf("\ncognome: ");
	gets(cognome_temp);
	fflush(stdin);
	for(i=0;i<DIM;i++){
		if(strcmp(v[i].nome,nome_temp)==0 && strcmp(v[i].cognome,cognome_temp)==0){
			printf("Alunno trovato\n");
			flag++;
			do{
				printf("inserire il nuovo voto: ");
				scanf("%d",&v[i].voto_condotta);
				fflush(stdin);
			}while(v[i].voto_condotta<1 || v[i].voto_condotta>10);
		}
	}
	if(flag==0){
		printf("\nAlunno non trovato\n");
	}
}
void modifica_info(struct classe v[DIM]){
	char c;
	int i;
	printf("\nIncrementare o decrementare");
	printf("\ni. incrementare");
	printf("\nd. decrementare");
	printf("\nScelta: ");
	scanf("%c",&c);
	switch(c){
		case 'i':
			for(i=0;i<DIM;i++){
				if(v[i].voto_info<10){
					v[i].voto_info=v[i].voto_info+1;
				}
			}
			break;
		case 'd':
			for(i=0;i<DIM;i++){
				if(v[i].voto_info>=2){
					v[i].voto_info=v[i].voto_info-1;
				}
			}
			break;
		default:
			printf("\nInserimento errato");
			break;	
	}
}
