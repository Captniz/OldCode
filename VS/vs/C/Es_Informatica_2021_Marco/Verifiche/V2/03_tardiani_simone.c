/*3> Scrivere solo le istruzioni da inserire nel ciclo for per fare il reverse di un arrayes: 
1 2 3 4 5 6   --->  6 5 4 3 2 1 


#define DIM 10
int v[DIM],i,box; 
//Inverti il vettore dimensionato DIM senza l'utilizzo di un vettore ausiliario 
for (i = 0; i < DIM/2; i++) {
    box=v[i];
    v[i]=v[DIM-1-i];
    v[DIM-1-i]=box;
}
*/