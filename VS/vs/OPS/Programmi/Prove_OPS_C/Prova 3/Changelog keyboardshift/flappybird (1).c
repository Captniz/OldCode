#include <stdio.h>
#include <stdlib.h>
int op(){
    long int N;
    long int A,B;
    long int max,min;
    long int i;
    FILE*in=fopen("input.txt","r");
    fscanf(in, "%ld",&N);
    fflush(stdin);
    fscanf(in,"%ld",&min);
    fflush(stdin);
    fscanf(in,"%ld",&max);
    fflush(stdin);
    for(i=1;i<N;i++){
        fscanf(in,"%ld",&A);
        fflush(stdin);
        fscanf(in,"%ld",&B);
        fflush(stdin);
    	if(max<A||min>B||min==(max-1))
            return 0;
        if(A>min)
            min=A;
        if(B<max)
            max=B;
    }
    /*
	if(max<A||min>B||min==(max-1))
        return 0;
    */
    fclose(in);
    return 1;
}


int main(){
    FILE*out=fopen("output.txt", "w");
    if(op())
        fprintf(out,"YES");
    else
        fprintf(out,"NO");
    fclose(out);
    return 0;
}
