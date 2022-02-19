//
#include<stdio.h>
#define DIM 80

void Spezza(char s[DIM],char Voc[DIM],char Con[DIM],int *VocLen,int *ConLen);
void Vis(char v[DIM]);

int main(){
    char s[DIM]="gatto,cane,pesce,alfa,aracnide";
    char Voc[DIM],Con[DIM];
    int Voclen,Conlen;
    Voclen=0;
    Conlen=0;

    Spezza(s,Voc,Con,&Voclen,&Conlen);

    printf("Stringa:%s\n",s);
    printf("Voc:%s\n",Voc);
    printf("Con:%s\n",Con);
    printf("Voclen:%d\n",Voclen);
    printf("Conlen:%d\n",Conlen);
    return 0;
}

void Spezza(char s[DIM],char Voc[DIM],char Con[DIM],int *VocLen,int *ConLen){
    int i,flag,VocLen1,ConLen1;
    i=0;
    VocLen1=0;
    ConLen1=0;
    flag=1;

    while ( s[i] != '\0' && flag){
        if (s[i]=='a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            while (s[i] != ',' && s[i]!= '\0'){
                Voc[VocLen1]=s[i];
                VocLen1++;
                i++;                
            }
            Voc[VocLen1]=' ';
            VocLen1++;
            i++;
        }else{
            while (s[i] != ',' && s[i]!= '\0'){
                Con[ConLen1]=s[i];
                ConLen1++;
                i++;                
            }
            Con[ConLen1]=' ';
            ConLen1++;
            i++;
        }

        if (s[i-1]=='\0'){
            flag=0;
        }
        
    }
    Con[ConLen1]='\0';
    Voc[VocLen1]='\0';
    *VocLen=VocLen1;
    *ConLen=ConLen1;
}

void vis(char v[DIM]){
    int i=0;

    for ( i = 0; v[i] != '\0'; i++){
        
    }
    
}