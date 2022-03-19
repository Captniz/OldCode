/*
2> Puntatori e strutture: 220316_2_Cognome_Nome.c (3,50 pt)
Considera la seguente struttura:
struct persona{
char *nome;
char *cognome;
char *codice;
int eta;
}; 
Sviluppare la seguente funzione:
struct persona eta(struct persona [ ]);
in modo che restituisca lo studente con maggiore età (a parità di età restituisce il
primo) 

Nel main:
• Creare un array di 9 persone inserendo nome, cognome ed età di 9 alunni. Il
codice non viene inserito ma è composto dai primi 3 char del nome + 3 char
del cognome + progressivo numerico, es: Luca Rinaldi -> LucRin1
• Visualizzare quindi lo studente più anziano richiamando la funzione
*/
#include<stdio.h>
#include<string.h>
#define DIM 2

struct persona{
	char *nome;
	char *cognome;
	char *codice;
	int eta;
	
};

struct persona eta(struct persona [ ]);

//Non so come passare al puntatore una stringa senza crearne tante quante i nomi, cognomi e codici

int main(){
	struct persona classe[DIM];
	char st[20];
	int i,j;
	i=0;
	j=0;
	
	for(i=0;i<DIM;i++){
		
		printf("\nNome:");
		gets(st);
		fflush(stdin);
		for(j=0; st[j-1] != '\0';j++){
			classe[i].nome[j] == st[j];
		}
		
		printf("\nCognome:");
		gets(st);
		fflush(stdin);
		for(j=0; st[j-1]!= '\0';j++){
			classe[i].cognome[j] == st[j];
		}
		
		printf("\nEta:");
		scanf("%d",&classe[i].eta);
		fflush(stdin);
		
		for(j=0;j<3;j++){
		classe[i].codice[j] == classe[i].nome[j];
		}
		for(j=3;j<6;j++){
		classe[i].codice[j] == classe[i].nome[j];
		}
		classe[i].codice[6] == (i+1);

		printf("---------");
	}
	
	printf("Alunno piu anziano: %s",eta(classe).nome);
	
}

struct persona eta(struct persona classe[DIM]){
	int i,max;
	i=0;
	max=0;
	
	for(i=0;i<DIM;i++){
		if(classe[i].eta > classe[max].eta){
			max=i;
		}
	}
	
	return classe[max];
}
















