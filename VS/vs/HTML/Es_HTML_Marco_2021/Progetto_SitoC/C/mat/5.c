/*023> Scrivere un programma che inizializzi e quindi 
visualizzi una matrice m di ROW=8 e COL=11 di int in cui ciascun 
elemento è dato dalla somma dei propri indici.
*/
#include <stdio.h>
#define ROW 8
#define COL 11
int main(){
	int m[ROW][COL],i,j;
	//load
	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
			m[i][j]=i+j;
		}
	}
	//vis
	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
			printf("%3d",m[i][j]);
		}
		putchar('\n');
	}
}
