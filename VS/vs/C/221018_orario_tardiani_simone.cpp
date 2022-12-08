/*
Definire una classe Orario i cui oggetti possano essere inizializzati come: o(14,25,35); implementare il costruttore, il metodo scrivi() per la stampa a video, il metodo modifica (hh,mm,ss) per consentirne la modifica e un metodo valida() per consentire la validazione dell’orario.
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class Orario{
private:
    int hh;
    int mm;
    int ss;

public:
    Orario(int hh1, int mm1, int ss1){
        hh=hh1;
        mm=mm1;
        ss=ss1;
    }
    
    void scrivi(){
        cout<<hh<<":"<<mm<<":"<<ss<<endl;
    }

    void modifica(int hh1, int mm1, int ss1){
        hh=hh1;
        mm=mm1;
        ss=ss1;
    }

    bool valida(){
        if (hh>=0 && hh<=23 && mm>=0 && mm<=59 && ss>=0 && ss<=59){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    
    return 0;
}

