/*55&gt; Ci sono 2 gare di 10 atleti con punteggio [1..50] 
ordinate gara1 e gara2 in modo decrescente
scrivere gli atleti che hanno realizzato i 3 migliori tempi tenendo conto delle due gare

es di 2 gare tra 5 atleti: (1 7 sta per atleta1 con punteggio 7)
gara1: 1  7, 2 21, 3 12, 4 45, 5 13
gara2: 1 17, 2 20, 3 12, 4 41,	5 18

ordinamento gara 1
4 45, 2 21, 5 13, 3 12, 1 7

ordinamento gara 2
4 41, 2 20, 5 18, 1 17, 3 12

3 migliori tempi:
4 45, 4 41, 2 21 
(cioe' l'atleta4 si piazza al primo posto con 45 e al secondo posto con 41, terzo l'atleta2 con 21)
*/
#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;time.h&gt;
#define DIM 10
void gara(int [],int []);
void sort(int [],int []);
void top3(int [],int [],int [],int []);
int main(){
	int g1[DIM];
	int g2[DIM];
	int a[DIM];
	int a2[DIM];
	srand(time(NULL));
	gara(g1,a);
	gara(g2,a2);
	putchar('\n');
	sort(g1,a);
	sort(g2,a2);
	putchar('\n');
	top3(g1,g2,a,a2);
	return 0;
}
void gara(int g[DIM], int a[DIM]){
	int i;
	for(i=0;i&lt;DIM;i++){
		g[i]=rand()%50+1;
		a[i]=i+1;
		printf("%2d%3d, ",a[i],g[i]);
	}
	putchar('\n');
}
void sort(int g[DIM],int a[DIM]){
	int i,box,box2,flag,flag2;
	do{
		flag=0;
		for(i=0;i&lt;DIM-1;i++){
			if(g[i]&lt;g[i+1]){
				box=g[i];
				g[i]=g[i+1];
				g[i+1]=box;
				box2=a[i];
				a[i]=a[i+1];
				a[i+1]=box2;	
				flag=1;
			}
		}
	}while(flag==1);
	for(i=0;i&lt;DIM;i++){
		printf("%2d%3d, ",a[i],g[i]);
	}
	putchar('\n');
}
void top3(int g1[DIM],int g2[DIM],int a[DIM],int a2[DIM]){
	int i,j,c;
	int gcomp[DIM];
	int acomp[DIM];
	i=0;
	for(c=0;c&lt;3;c++){
		if(g1[i]&gt;g2[j]){
			gcomp[c]=g1[i];
			acomp[c]=a[i];
			i++;
		}else{
			gcomp[c]=g2[j];
			acomp[c]=a2[j];
			j++;
		}
	}
	for(i=0;i&lt;c;i++){
		printf("%2d%3d, ",acomp[i],gcomp[i]);
	}
}
