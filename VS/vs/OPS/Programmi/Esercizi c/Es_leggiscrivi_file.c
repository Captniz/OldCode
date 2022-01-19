#include<stdio.h>
#include<stdlib.h>
#define DIM 10

int main()
{   
    int somma, max, min,v[DIM],i;
    somma=0;
    max=0;
    min=0;
    i=0;
    //Apertura file
    FILE* input = fopen("Input.txt", "r");
    FILE* output = fopen("Output.txt", "w");
    //Scan del file
    if(input){
        for (i = 0; i < DIM; i++)
        {
            fscanf(input, "%d",&v[i]);  //Lo fscanf del file cambia riga
        }                               //ogni volta che lo esegui "For reasons"
    }
    printf("lettura eseguita");
    max=v[0];
    min=v[0];

    for ( i = 0; i < DIM; i++)
    {
        if (v[i]>max)
        {
            max=v[i];
        }
        if (v[i]<min)
        {
            min=v[i];
        }
        somma+=v[i];
    }

    printf("analisi eseguita");
    fprintf(output,"%d\n",somma);
    fprintf(output,"%d\n",max);     
    fprintf(output,"%d\n",min);     

    fclose(input);
    fclose(output);
    return 0;
}
