#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 80


int main(){
    int ctr,n;
    n=0;
    ctr=0;
    char path[DIM];
    FILE* out = fopen("Output.txt","w");

    do{
        printf("\nPercorso FILE output: ");
        gets(path);
        fflush(stdin); 
        out = fopen(path,"r");
        if (out==NULL){
            fclose(out);
            out = fopen(path,"w");          //"Output.txt"
            n=-1;
        }else{
            printf("\nFile gia' esistente, sei sicuro di usarlo (y/n): ");
            n=getchar();
            fflush(stdin);
            if (n=='y'){
                fclose(out);
                out = fopen(path,"w");
                n=-1;
            }
        }
    }while(n!=-1);

    do{
        fputc('C',out);
        ctr++;
    } while (ctr<DIM);

    fclose(out);

    return 0;
}
