//FAi una mtrice DIM a scelta che gira 90 gradi in senoso orario in un file

#include<stdio.h>
#define DIM 10
int main()
{
    int i,j,m[DIM][DIM];
    i=0;
    j=0;

    FILE* input = fopen("Input.txt", "r");
    FILE* output = fopen("Output.txt", "w");

    //array input
    for ( i = 0; i < DIM; i++)
    {
        for ( j = 0; j < DIM; j++)
        {
            fscanf(input, "%d",&m[i][j]);
        }
    }

    //VIS primo array
    for (i=0;i<DIM;i++){
        for (j=0;j<DIM;j++){
            printf("%4d",m[i][j]);
        }
        putchar('\n');
    }

    
    for (i=0;i<DIM;i++){
        for (j=0;jDIM;j++){
            fprintf(output,"%4d",m[i][j]);
        }
        fprintf(output,"\n");
    }


    //TODO: NON FARE SCHIFO
    fclose(input);
    fclose(output);
    printf("Belandi");
    fprintf(output,"Belandi");
    return 0;
}