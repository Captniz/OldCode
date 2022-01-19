#include <stdio.h>
int interseca(){
    int N;
    int A,B;
    int max,min;
    int i;
    FILE* in=fopen("input.txt","r");
    fscanf(in, "%d",&N);
    fflush(stdin);
    fscanf(in,"%d",&min);
    fflush(stdin);
    fscanf(in,"%d",&max);
    fflush(stdin);
    for(i=1;i<N;i++){
        fscanf(in,"%d",&A);
        fflush(stdin);
        fscanf(in,"%d",&B);
        fflush(stdin);
    	if( (A>max || B<min) )
            return 0;
        min=A;
        max=B;
	}

    return 1;
    fclose(in);
    return 0;
}

int main(){
    FILE* out=fopen("output.txt", "w");
    if(interseca())
        fprintf(out,"YES");
    else
        fprintf(out,"NO");
    fclose(out);
    return 0;
}
