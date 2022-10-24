/*79> 
int v[row];
int *pv;
pv=&v[0];
    
int m[row][col];
int *pm;
pm=&m[0][0];
  
caricare, visualizzare e trovare il max
USANDO SOLO ARITMETICA DEI PUNTATORI 
row e col sono chieste all'utente
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void carica_vet(int *, int);
void visualizza_vet(int *, int);
int max_vet(int *, int);
void carica_mat(int *, int , int);
void visualizza_mat(int *, int , int);
int max_mat(int *, int , int);
int main()
{
	srand(time(NULL));
	//caricamento, visualizzazione e valore massimo dell'array
	printf("Array:\n");
	int row,col;
	printf("inserire la dimensione del vettore: ");
	scanf("%d",&row);
	fflush(stdin);
	int v[row];
	int *p_v;
	p_v=v;
	carica_vet(p_v,row);
	visualizza_vet(p_v,row);
	printf("\nil valore massimo nell'array e': %d",max_vet(p_v,row));
	putchar('\n');
	putchar('\n');
	//caricamento, visualizzazione e valore massimo della matrice
	printf("Matrice:\n");
	printf("inserire il numero delle colonne: ");
	scanf("%d",&col);
	fflush(stdin);
	printf("inserire il numero delle righe: ");
	scanf("%d",&row);
	fflush(stdin);
	int m[row][col];
	int *p_m;
	p_m=&m[0][0];
	carica_mat(p_m,row,col);
	visualizza_mat(p_m,row,col);
	max_mat(p_m,row,col);
	printf("\nil valore massimo nella matrice e': %d",max_mat(p_m,row,col));
	return 0;
}
void carica_vet(int *p_v, int row){
	int i;
	for(i=0;i<row;i++){
		*p_v=rand()%50+1;
		*p_v++;
	}
}
void visualizza_vet(int *p_v, int row){
	int i;
	for(i=0;i<row;i++){
		printf("%4d",*p_v);
		*p_v++;
	}
}
int max_vet(int *p_v, int row){
	int i,max;
	max=*p_v;
	for(i=0;i<row;i++){
		if(*p_v>max){
			max=*p_v;
		}
		p_v++;
	}
	return max;
}
void carica_mat(int *p_m, int row, int col){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			*p_m=rand()%20+1;
			p_m++;
		}
	}
}
void visualizza_mat(int *p_m, int row, int col){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf("%4d",*p_m);
			p_m++;
		}
		putchar('\n');
	}
}
int max_mat(int *p_m, int row, int col){
	int i,j,max;
	max=*p_m;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(*p_m>max){
				max=*p_m;
			}
			p_m++;
		}
	}
	return max;
}
