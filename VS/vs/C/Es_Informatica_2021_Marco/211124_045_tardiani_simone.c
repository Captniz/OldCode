#include<stdio.h>

int ControlloData(int gg,int mm, int aa);

int main(){
    
    ControlloData(31,12,2021);

    return 0;
}

int ControlloData(int gg,int mm, int aa){

    int Mesi[12] ={31,28,31,30,31,30,31,31,30,31,30,31};

    if (aa < 0){
        return 0;
    }
    
    if (mm < 1 || mm > 12){
        return 0;
    }
    
    if (gg < 1 || gg > Mesi[mm-1]){
        return 0;
    }
    
    return 1;
}