/*58&gt;
Benchmark tra sorting: bubble, selection, insertion
int swap_count = 0;
int comp_count = 0;
void incSwap() { swap_count++; }
void incComp() { comp_count++; }
void resetCounters(){
	swap_count = 0;
	comp_count = 0;
}
void printCounters(){
	printf("Confronti effettuati: %d\n", comp_count);
	printf("Scambi effettuati: %d\n", swap_count);
}
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
void copia(int [], int []);
void printCounters();
void resetCounters();
void incSwap();
void incComp();

int swap_count=0;
int comp_count=0;
int main()
{
	srand(time(NULL));
	int v[DIM],v2[DIM];
	int c,flag;
	flag=1;
	while(1){
		printf("Scegliere un'opzione (ma prima caricare)\n\n");
		printf("1. Carica\n");
		printf("2. Bubble Sort\n");
		printf("3. Selection Sort\n");
		printf("4. Insertion Sort\n");
		printf("5. Exit\n\n");
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
				copia(v,v2);
				resetCounters();
				visualizza(v2);
				bubblesort(v2);
				visualizza(v2);
				printCounters();
			break;
			case 3:
				copia(v,v2);
				resetCounters();
				visualizza(v2);
				selectionsort(v2);
				visualizza(v2);
				printCounters();
			break;
			case 4:
				copia(v,v2);
				resetCounters();
				visualizza(v2);
				insertionsort(v2);
				visualizza(v2);
				printCounters();
			break;
			case 5:
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
void copia(int v[DIM], int v2[DIM]){
	int i;
	for(i=0;i&lt;DIM;i++){
		v2[i]=v[i];
	}
}
void bubblesort(int v[DIM]){
	int i,j,box;
	for(i=0;i&lt;DIM-1;i++){
		for(j=i+1;j&lt;DIM;j++){
			if(v[i]&gt;v[j]){
				box=v[i];
				v[i]=v[j];
				v[j]=box;
				incSwap();
			}
			incComp();
		}
	}
}
void selectionsort(int v[DIM]){
	int i, j, imin;
	int box;
	for(i=0; i&lt;(DIM-1); i++){
		imin=i;
		for(j=i+1; j&lt;DIM; j++){
			if(v[imin]&gt;v[j]){
				imin=j;
			}
			incComp();
		}
		if(i!=imin){
			box=v[i];
			v[i]=v[imin];
			v[imin]=box;
			incSwap();
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
			incComp();
			incSwap();
		}
		incComp();
		v[j+1]=min;
	}
}
void resetCounters(){
	swap_count = 0;
	comp_count = 0;
}
void printCounters(){
	printf("Confronti effettuati: %d\n", comp_count);
	printf("Scambi effettuati: %d\n", swap_count);
}
void incSwap(){
	swap_count++;
}
void incComp(){
	comp_count++;
}
