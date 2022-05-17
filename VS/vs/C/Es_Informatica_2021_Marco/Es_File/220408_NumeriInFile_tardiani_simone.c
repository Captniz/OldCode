#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int check(char in);
void write(FILE* fp_out);
void read(FILE* fp_in);

int main(){
    FILE* fp_out = fopen("Output.txt", "w");
    write(fp_out);
    fclose(fp_out);
    printf("\n\n\n");
    FILE* fp_in = fopen("Output.txt", "r");
    read(fp_in);
    fclose(fp_in);

    return 0;
}

void write(FILE* fp_out){
    char in;
    if (fp_out == NULL){
        perror("Spazio su disco esaurito");
        exit(1);
    }
    
    printf("Input:\n\n");
    in=getchar();
    while (check(in)){
        fprintf(fp_out, "%c",in);
        in=getchar();
    }
    
    printf("\nFine Scrittura\n=========================");
}

void read(FILE* fp_in){
    char buf[80];
    if (fp_in == NULL){
        perror("File non esistente");
        exit(1);
    }
    printf("Ouput:\n\n");
    while (fgets(buf,80,fp_in)!=NULL){
        printf("%s",buf);
    } 

    printf("\n\nFine lettura\n=========================");   
}

int check(char in){
    if (in != '0'&& in != '1'&&in != '2'&&in != '3'&&in != '4'&&in != '5'&&in != '6'&&in != '7'&&in != '8'&&in != '9'&&in != '\n'){
        return 0;
    }
    return 1;
}