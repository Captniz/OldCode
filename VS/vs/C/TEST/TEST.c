#include<stdio.h>

#include<time.h>

#include<stdlib.h>

#define dim 10


void main(  )
{
srand(time(NULL));

int s = 0;
int t = 0;

int MATRICE[dim][dim];


RANDOMICO(MATRICE);


for ( s = 0; s < dim; s++ ){for ( t = 0; t < dim; t++ ){if (s == t){MATRICE[s][t]=0;MATRICE[(dim-1-s)][(dim-1-t)]=0; t=0;s++;}if((t+s)==(dim-1)){MATRICE[s][t]=0;MATRICE[t][s]=0;t=0;s++;}}}


//DATP CHE IL PéROGRAMMA NON FUNZIONAVA L HO CORRETTO COSì
MATRICE[0][dim-1]=0;
MATRICE[dim-1][0]=0;


VISUALIZZAZIONE(MATRICE);}




int RANDOMICO( int MATRICE[dim][dim] ){
int q;
for ( q = 0; q < dim; q++){ for ( int w = 0; w < dim; w++){ MATRICE[q][w] = rand()%20+1;}}return 20;}






int VISUALIZZAZIONE( int MATRICE[dim][dim] ){
int q;
for ( q = 0; q < dim; q++){ for ( int w = 0; w < dim; w++){ printf("%3d",MATRICE[q][w]);}putchar('\n');}return 100;}