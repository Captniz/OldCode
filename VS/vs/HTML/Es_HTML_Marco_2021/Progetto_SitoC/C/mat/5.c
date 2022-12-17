/*023&gt; Scrivere un programma che inizializzi e quindi 
visualizzi una matrice m di ROW=8 e COL=11 di int in cui ciascun 
elemento � dato dalla somma dei propri indici.
*/
#include &lt;stdio.h&gt;
#define ROW 8
#define COL 11
int main(){
	int m[ROW][COL],i,j;
	//load
	for(i=0;i&lt;ROW;i++){
		for(j=0;j&lt;COL;j++){
			m[i][j]=i+j;
		}
	}
	//vis
	for(i=0;i&lt;ROW;i++){
		for(j=0;j&lt;COL;j++){
			printf("%3d",m[i][j]);
		}
		putchar('\n');
	}
}
