// Numero -> Numero romano
#include<stdio.h>

int main()
{
    // I II III IV V VI VII VIII VIII IX X
    //I
    //X
    //V
    //C
    //D
    //M

    int i,j,n,Nromani[]={1000,500,100,50,10,5,1};
    char cNromani[]={'M','D','C','L','X','V','I'};
    n=0;
    i=0;
    j=0;    

    do{
    printf("Numero?:");
    scanf("%d",&n);
    }while(n<0 || n>3999);

    for ( i = 0; n != 0; i++){
        for ( j = 0; j < 7; j++){
            if (n/Nromani[j]!=0){
                printf("%c",cNromani[j]);
                n=n-Nromani[j];
                j=j-1;
            }
        }
    }
    return 0;
}
