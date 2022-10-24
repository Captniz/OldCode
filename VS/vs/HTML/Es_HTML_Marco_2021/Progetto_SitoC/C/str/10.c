/*36> Scrivere una funzione che visualizzi un rettangolo di row righe per col colonne di *.
---------
void rettangolo(int, int);
*/
#include<stdio.h>
void rettangolo(int, int);
int main()
{
	int row,col;
	printf("inserire le righe: ");
	scanf("%d",&row);
	fflush(stdin);
	printf("inserire le colonne: ");
	scanf("%d",&col);
	fflush(stdin);
	rettangolo(row,col);
	return 0;
}
void rettangolo(int row, int col){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf("* ");
		}
		putchar('\n');
	}
}
