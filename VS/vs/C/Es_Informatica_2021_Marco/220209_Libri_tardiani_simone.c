/* fare una struttura libro codice e numero intero numero pagine e costo  inserire 7 libri calcolare
 il costo medio per pagina per libro visualizzare i dfati in ordine crescenmte di costo per pagina*/
#include<stdio.h>
#include<stdlib.h>
#define DIM 7

struct Libro{
    int ID;
    int Npagine;
    float Costo;
};

typedef struct Libro lib;

void InputDati( lib [] );
float MediaCostoPagine( lib [] );
void OrdinaXCosto( lib [], int [] );
void VisStruct( lib [], int [] );

int main(){
    lib libri[DIM];
    int v[DIM],i;
    i=0;

    for ( i = 0; i < DIM; i++){
        v[i]=i;
    }

    InputDati(libri);
    printf("\n---------\n\nLa media del costo per pagina e' %f\n",MediaCostoPagine(libri));
    OrdinaXCosto( libri,v);
    VisStruct( libri,v);

    return 0;
}

void InputDati( lib libri[] ){
    int i=0;

    for ( i = 0; i < DIM; i++){
        putchar('\n');
        printf("ID libro %d:",i+1);
        scanf("%d",&libri[i].ID);     

        printf("Numero pagine libro %d:",i+1);
        scanf("%d",&libri[i].Npagine);

        printf("Costo libro %d:",i+1);
        scanf("%f",&libri[i].Costo);       
    }
}

float MediaCostoPagine( lib libri[] ){
    float media = 0;
    int i = 0;

    for ( i = 0; i < DIM; i++){
        media=media+(libri[i].Costo/libri[i].Npagine);
    }
    
    return media/DIM;
}

void OrdinaXCosto( lib libri[], int v[] ){
    int i,j,imin,temp;
    i=0;
    j=0;
    imin=0;
    temp=0;
    
    for(i=0;i<(DIM-1);i++){
		imin=i;
		for(j=i+1;j<DIM;j++){
			if((libri[imin].Costo/libri[imin].Npagine)>(libri[j].Costo/libri[j].Npagine)){
				imin=j;
			}
		}
		if(i!=imin){
            temp=v[i];
            v[i]=v[imin];
            v[imin]=temp;
		}
	}
}

void VisStruct( lib libri[], int v[] ){
    int i=0;

    printf("\n---------\n");
    for ( i = 0; i < DIM; i++){
        printf("\nID libro:%d\n",libri[v[i]].ID);
        printf("Costo libro:%f\n",libri[v[i]].Costo);
        printf("Numero pagine libro:%d\n",libri[v[i]].Npagine);
        printf("Costo x pagine libro:%f\n",(libri[v[i]].Costo/libri[v[i]].Npagine));
    }
}