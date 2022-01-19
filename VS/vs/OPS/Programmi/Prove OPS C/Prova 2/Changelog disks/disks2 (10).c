#include <stdio.h>

int possible(FILE *input){
    int N; // number of the days
    int t; // hours of work
    int n_hours; // freetime
    int limits[2];
    int i;

    // input general data
    fscanf(input, "%d", &N);
    fscanf(input, "%d", &t);
    fscanf(input, "%d", &limits[0]);
    for(i=0; i<N; i++){
        fscanf(input, "%d", &limits[0]);
        fscanf(input, "%d", &limits[1]);
        n_hours=24-limits[0]+limits[1];

        if(n_hours>t) return 2;
    }

    return -1;
}

int main(){
    FILE *input=fopen("input1.txt", "r");
    FILE *output=fopen("output.txt", "w");
    fprintf(output, "%d", possible(input));
    fclose(input);
    fclose(output);
    return 0;
}
