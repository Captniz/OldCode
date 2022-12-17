/*27&gt;  Caricare una matrice quadrata m con DIM=10 con tutti 0.
Visualizzare la matrice.
Sovrascivere sulla matrice numeri progressivi, in senso orario, a partire
dalla prima riga, ultima colonna, ultima riga e prima colonna.
.......
azzera(m);
visualizza(m);
spirale(m);
visualizza(m);
*/
#include&lt;stdio.h&gt;
#define DIM 10
void azzera(int [][DIM]);
void visualizza(int [][DIM]);
void spirale(int [][DIM]);
int main()
{
	int m[DIM][DIM];
	azzera(m);
	visualizza(m);
	spirale(m);
	putchar('\n');
	visualizza(m);
	return 0;
}
void azzera(int m[DIM][DIM]){
	int i,j;
	for(i=0;i&lt;DIM;i++){
		for(j=0;j&lt;DIM;j++){
			m[i][j]=0;
		}
	}
}
void visualizza(int m[DIM][DIM]){
	int i,j;
	for(i=0;i&lt;DIM;i++){
		for(j=0;j&lt;DIM;j++){
			printf("%4d",m[i][j]);
		}
		putchar('\n');
	}
}
void spirale(int m[DIM][DIM]){
	int i;
	for(i=0;i&lt;DIM;i++){
		m[0][i]=i+1;
		m[i][DIM-1]=i+DIM;
		m[DIM-1][i]=(DIM-1)*3-i+1;
		m[i+1][0]=(DIM-1)*4-i;
	}
}
