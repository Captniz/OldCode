//211105_Cornice_tardiani_simone.c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define ROW 10
#define COL 10

//196 -
//194 ┬
//191 ┐
//192 └
//193 ┴
//217 ┘
//197 ┼
//195 ├
//180 ┤
//218 ┌

void printTOP(int max); //stampa la prima parte della tabella                         
void printBOT(int max); //stampa l'ultima parte della tabella           
void divisore(int max); //stampa le linee divisorie orizzontali      
void printMID(int m[ROW][COL]); //stampa tutti i numeri e le pareti laterali delle celle
int trovaMax(int m[ROW][COL]);  //trova quanto devono essere grandi le celle
void CaricaArray(int m[ROW][COL]);  //carica l'array

int main(){
    int m[ROW][COL];
    CaricaArray(m);
    printTOP(trovaMax(m));
    printMID(m);
    printBOT(trovaMax(m));
    return 0;
}

void printTOP(int max){
  
    int i,j;
    i=0;
    j=0;
    printf(" ");
    for ( i = 0; i < (COL-1); i++){
        
        for ( j = 0; j < max; j++){
            printf("%c",196);
        }
        printf(" ");
    }

    for ( j = 0; j < max; j++){
        printf("%c",196);
    }
    printf(" \n");
}

void printBOT(int max){
    
    int i,j;
    i=0;
    j=0;
    printf(" ");
    for ( i = 0; i < (COL-1); i++)  {
        
        for ( j = 0; j < max; j++){
            printf("%c",196);
        }
        printf(" ");
    }

    for ( j = 0; j < max; j++){
        printf("%c",196);
    }
    printf(" \n");
}

void divisore(int max){
   
    int i,j;
    i=0;
    j=0;
    printf(" ");
    for ( i = 0; i < (COL-1); i++){
        
        for ( j = 0; j < max; j++){
            printf("%c",196);
        }
        printf(" ");
    }

    for ( j = 0; j < max; j++){
        printf("%c",196);
    }
    printf(" \n");
}

void CaricaArray(int m[ROW][COL]){
   
    int i,j;
    i=0;
    j=0;
    srand(time(NULL));

    for (i=0;i<ROW;i++){
        
        for (j=0;j<COL;j++){
            m[i][j]=rand()%100+1;
        }
    }
}

int trovaMax(int m[ROW][COL]){
    
    int Pow,i,j,max;
    i=0;
    j=0;
    max=0;
    Pow=10;

    for (i=0;i<ROW;i++){
        
        for (j=0;j<COL;j++){
            
            if (max<m[i][j]){
                max=m[i][j];
            }
        }
    }

    for ( i = 1; 1 ; i++){
        
        if ((max/Pow)>=1){
            Pow=Pow*10;
        
        }else{
            return i;
        }
    }
}

void printMID(int m[ROW][COL]){

    int i,j,Pow,flag;
    i=0;
    j=0;
    flag=1;
    Pow=pow(10,trovaMax(m));

    for ( i = 0; i < (ROW-1); i++){
        printf("%c",179);
        for ( j = 0; j < COL; j++){
            flag=1;
            for ( Pow=pow(10,trovaMax(m)); flag==1; Pow=Pow/10){
                
                if ((m[i][j]/Pow)<1 && (m[i][j]/(Pow/10))<1){
                    putchar(' ');
                
                }else{
                    flag=0;
                }
            }
            printf("%d",m[i][j]);
            printf("%c",179);
        }
        putchar('\n');
        divisore(trovaMax(m));
    }
    printf("%c",179);
    for ( i = 0; i < COL; i++){
        flag=1;
        for ( Pow=pow(10,trovaMax(m)); flag==1; Pow=Pow/10){
            
            if ((m[ROW-1][i]/Pow)<1 && (m[ROW-1][i]/(Pow/10))<1){
                putchar(' ');
            
            }else{
                flag=0;
            }
        }
        printf("%d",m[ROW-1][i]);
        printf("%c",179);
    }
    putchar('\n');
}