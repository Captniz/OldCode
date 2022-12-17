/*57&gt; 
Switch case (menu)
0. Carica
1. Visualizza
2. Bubble sort
3. Selection sort
4. Insertion sort
5. exit
*/
#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;time.h&gt;
#define DIM 10
void carica(int []);
void visualizza(int []);
void bubblesort(int []);
void selectionsort(int []);
void insertionsort(int []);
int main()
{
	srand(time(NULL));
	int v[DIM];
	int c,flag;
	flag=1;
	while(1){
		printf("Scegliere un'opzione (ma prima caricare)\n\n");
		printf("1. Carica\n");
		printf("2. Visualizza\n");
		printf("3. Bubble Sort\n");
		printf("4. Selection Sort\n");
		printf("5. Insertion Sort\n");
		printf("0. Exit\n\n");
		printf("Scelta : ");
		scanf("%d",&c);
		fflush(stdin);
		putchar('\n');
		switch(c)
		{
			case 1:
				carica(v);
			break;
			case 2:
				visualizza(v);
			break;
			case 3:
				bubblesort(v);
				visualizza(v);
			break;
			case 4:
				selectionsort(v);
				visualizza(v);
			break;
			case 5:
				insertionsort(v);
				visualizza(v);
			break;
			case 0:
				return 0;
			break;
		}
	}
	return 0;
}
void carica(int v[DIM]){
	int i;
	for(i=0;i&lt;DIM;i++){
		v[i]=rand()%50+1;
	}
}
void visualizza(int v[DIM]){
	int i;
	for(i=0;i&lt;DIM;i++){
		printf("%3d",v[i]);
	}
	putchar('\n');
	putchar('\n');
}
void bubblesort(int v[DIM]){
	int i,j,box;
	for(i=0;i&lt;DIM-1;i++){
		for(j=i+1;j&lt;DIM;j++){
			if(v[i]&gt;v[j]){
				box=v[i];
				v[i]=v[j];
				v[j]=box;
			}
		}
	}
}
void selectionsort(int v[DIM]){
	int i, j, imin;
	int box;
	for(i=0; i&lt;(DIM-1); i++){
		imin=i;
		for(j=i+1;j&lt;DIM; j++){
			if(v[imin]&gt;v[j]){
				imin=j;
			}
		}
		if(i!=imin){
			box=v[i];
			v[i]=v[imin];
			v[imin]=box;
		}
	}
}
void insertionsort(int v[DIM]){
	int i,j,min;
	for(i=1;i&lt;DIM;i++){
		min=v[i];
		j=i-1;
		while(min&lt;v[j] && j&gt;=0){
			v[j+1]=v[j];
			j=j-1;
		}
		v[j+1]=min;
	}
}
