//211023_distanza2punti_Simone_Tardiani.c

#include <stdio.h>
#include <math.h>
float dist(int Xa, int Xb, int Ya, int Yb);
int main(){
    int Xa,Xb,Ya,Yb;

    printf("Xa:");
    scanf("%d",&Xa);
    while(getchar()!='\n');

    printf("Ya:");
    scanf("%d",&Ya);
    while(getchar()!='\n');

    printf("Xb:");
    scanf("%d",&Xb);
    while(getchar()!='\n');

    printf("Yb:");
    scanf("%d",&Yb);
    while(getchar()!='\n');

    printf("\n%.2f",dist(Xa,Xb,Ya,Yb));
    return 0;
}

float dist(int Xa, int Xb, int Ya, int Yb){
    float delta_x,delta_y,dist;
    delta_x=Xa-Xb;
    delta_y=Ya-Yb;
    delta_x=delta_x*delta_x;
    delta_y=delta_y*delta_y;
    dist=sqrt(delta_x+delta_y);
    if(dist<0){
        return dist*-1;
    } else {
        return dist;
    }
}