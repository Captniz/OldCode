/*10> caricare un vettore let con DIM=10 con lettere maiuscole (HELP: dichiarare quindi  char let[DIM])
- visualizzare il numero complessivo delle vocali presenti nel vettore.
*/
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 10
int main()
{
	char let[DIM],i;
	int voc=0;
	srand(time(NULL));
	for(i=0;i<DIM;i++){
		let[i]=rand()%25+65;
		printf("%c ", let[i]); 
		if(let[i]=='A' || let[i]=='E' || let[i]=='I' || let[i]=='O' || let[i]=='U'){
			voc++;
		}
	}
	printf("\nVocali: %d", voc);
	return 0;
}
