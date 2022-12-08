#include<stdio.h>

int Data(int aa, int mm, int gg, int aa2, int mm2, int gg2);

int main(){
    printf("%d",Data(2002,10,20,2005,10,20));
    return 0;
}

int Data(int aa, int mm, int gg, int aa2, int mm2, int gg2){
    //*Var
    int ValueMesi[]={0,31,28,31,30,31,30,31,31,30,31,30};
    int i=0,ctr=0;

    //*anni
    aa=aa * 365 + ((aa/4) - ((aa/100)-((aa/100)/10)*8));
    aa2=aa2 * 365 + ((aa2/4) - ((aa2/100)-((aa2/100)/10)*8));

    //*mesi
    for ( i = 0; i < mm; i++){
        ctr+=ValueMesi[i];
    }
    mm=ctr;
    ctr=0;
    for ( i = 0; i < mm2; i++){
        ctr+=ValueMesi[i];
    }
    mm2=ctr;
    ctr=0;
    
    if (gg+mm+aa>gg2+mm2+aa2){
        return ((gg+mm+aa)-(gg2+mm2+aa2));
    }else if (gg+mm+aa<gg2+mm2+aa2){
        return ((gg2+mm2+aa2)-(gg+mm+aa));
    }else{
        return 1;
    }
}