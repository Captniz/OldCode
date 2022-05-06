#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 30


int main(){
    int n=0;
    char buf[30];
    char path[80];
    FILE* out = fopen("Output.txt","w");
    FILE* in;
    
    do{
        printf("\nPercorso FILE input: ");
        gets(path); 
        in = fopen(path,"r");               //"C://Windows/Lenovo/ImController/Data/NOTICE_IMCService.txt"
    }while(in==NULL);

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
        n=fread(buf,sizeof(char),DIM,in);
        fwrite(buf,sizeof(char),n,out);
    } while (n==DIM);

    fclose(in);
    fclose(out);

    return 0;
}
