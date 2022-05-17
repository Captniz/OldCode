#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 10

int main(){
    int i,j,dim;
    j=0;
    i=0;
    dim=0;
    char v[DIM][80],box[80];
    FILE* in = fopen("Input.txt","r");
    FILE* out = fopen("Output.txt","w");

    i=0;
    while(i<DIM && (fscanf(in, "%s",&v[i]))!=EOF){
        i++;
    }
    dim=i;

    for(i=0;i<dim-1;i++){
        for(j=i+1;j<dim;j++){
            if(strcmp(v[i],v[j])>0){
                strcpy(box,v[i]);
                strcpy(v[i],v[j]);
                strcpy(v[j],box);
            }
        }
    }

    j=0;
    while (j<dim){
        fprintf(out, "%s ",v[j]);
        j++;
    }
    
    fclose(in);
    fclose(out);
}