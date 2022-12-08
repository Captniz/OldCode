#include<stdio.h>
#include<stdlib.h>
#define DIM 100

int main(){
    char buf[DIM];
    int n;
    int ctr = 0;
    int i;
    FILE* in = fopen("Input.txt", "r");

    if (in == NULL){
        printf("File non trovati o memoria di massa piena\n");
        return 1;
    }
    do{ 
        n = fread(buf,sizeof(char),DIM,in);

        for ( i = 0; i <= n; i++){
            if (buf[i]>='0' && buf[i]<='9'){
                ctr++;
            }   
        }
    }while(n==100);
    
    fclose(in);
    printf("Fine, numero di cifre:%d\n",ctr);
    return 0;
}

/*
#include<stdio.h>
#include<stdlib.h>
#define DIM 100

int main(){
    char buf[DIM];
    int n;
    FILE* in = fopen("Input.txt", "r");
    FILE* out = fopen("Output.txt", "w");

    if (in == NULL || out == NULL){
        printf("File non trovati o memoria di massa piena\n");
        return 1;
    }
    do{ 
        n = fread(buf,sizeof(char),DIM,in);
        fwrite(buf,sizeof(char),n,out);
    }while(n==100);
    
    fclose(in);
    fclose(out);

    printf("Fine\n");
    return 0;
}

*/