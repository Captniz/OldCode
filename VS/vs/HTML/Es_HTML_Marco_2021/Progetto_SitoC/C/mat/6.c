/*26> Caricare una matrice quadrata m con DIM=10 con numeri progressivi che partono da 1 e finiscono a 100.
Visualizzare mcon la griglia semplice.
Caricamento per righe.
.......
carica(m)
visualizza-frame(m) */
#include<stdio.h>
#define DIM 10
void carica(int [][DIM]);
void visualizza_frame(int [][DIM]);
int main(){
	int m[DIM][DIM];
	carica(m);
	visualizza_frame(m);
	return 0;
}

void carica(int m[DIM][DIM]){
	int i,j,c;
	c=1;
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++){
			m[i][j]=c;
			c++;
		}
	}
}
void visualizza_frame(int m[DIM][DIM]){
	int i,j;
	for(i=0;i<DIM;i++){
    	printf(" %c%c%c ",196,196,196);
	}
	putchar('\n');
	for(i=0;i<DIM;i++){
		for(j=0;j<=DIM;j++){
			if(j<DIM){
				printf("%c",124);
				printf("%3d ",m[i][j]);
			}else{
				printf("%c",124);
				putchar('\n');
				for(j=0;j<DIM;j++){
    				printf(" %c%c%c ",196,196,196);
				}
			}
		}
		putchar('\n');	
	}
}
