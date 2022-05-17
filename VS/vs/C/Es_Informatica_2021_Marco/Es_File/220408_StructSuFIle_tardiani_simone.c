#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 3
#define LEN 80

typedef struct persona{
    char *name;
    char *surn;
    char *code;
    int age;
} pers;

void InData(pers group[DIM],char name[DIM][LEN],char surn[DIM][LEN],char code[DIM][LEN],int id);

int main(){
    int i=0;
    pers group[DIM];
    char name[DIM][LEN];
    char surn[DIM][LEN];
    char code[DIM][LEN];

    for ( i = 0; i < DIM; i++){
        InData(group,name,surn,code,i);
    }
    
    return 0;
}

void InData(pers group[DIM],char name[DIM][LEN],char surn[DIM][LEN],char code[DIM][LEN],int id){
    printf("Nome %d:\n",id+1);
    gets(group->name);
    printf("Cogome %d:\n",id+1);
    gets(group->surn);
    
    printf("\n");
}