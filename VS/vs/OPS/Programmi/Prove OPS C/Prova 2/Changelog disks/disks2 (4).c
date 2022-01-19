#include <stdio.h>

long int possible(FILE *input){
    long int N; // number of the days
    int t; // hours of work
    int n_hours; // freetime
    int limits[2]; // times range
    long int i; // counter

    // input general data
    fscanf(input, "%ld", &N);
    fflush(stdin);
    fscanf(input, "%d", &t);
    fflush(stdin);
    fscanf(input, "%d", &limits[0]);
    fflush(stdin);

    // scraping times
    for(i=0; i<N-2; i++){
        fscanf(input, "%d", &limits[0]);
        fflush(stdin);
        fscanf(input, "%d", &limits[1]);
        fflush(stdin);
        if(limits[0]<limits[1]){
			n_hours=limits[1]-limits[0];
        }else if(limits[0]==limits[1]){
            n_hours=24;
        }else{
			n_hours=(24-limits[0])+limits[1];
            if(limits[0]==24 && n_hours>=t){
                return ++i;
            }
        }
        if(n_hours>=t) return i;
    }

    fscanf(input, "%d", &limits[1]);
    fflush(stdin);
    n_hours=24-limits[1];
    if(n_hours>=t) return N-1;

    i=-1;
    return i;
}

int main(){
    FILE *input=fopen("input.txt", "r");
    FILE *output=fopen("output.txt", "w");
    fprintf(output, "%ld", possible(input));
    fclose(input);
    fclose(output);
    return 0;
}
