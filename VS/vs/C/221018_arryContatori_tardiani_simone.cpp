/*
 Scrivi una classe CPP ContatoreV2, che allochi tramite la funzione malloc un array di numElem contatori. Scrivi l'opportuno costruttore che inizializzi la struttura dati.

Scrivi inoltre i metodi:

- incrementa(int c) // funzione che incrementa il c-simo contatore

- decrementa(int c) // funzione che decrementa il c-simo contatore

- stampa() // funzione che stampa lo stato dei contatori
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


class Contatore{

private:
    int valore;

public:
    Contatore(){
        valore=1;
    }

    void Inc(){
        valore++;
    }
};

class ContatoreV2{
private:
    int *v;
public:
    ContatoreV2(int numElem){
        v = new int[numElem];
    }

    void incrementa(int c){
        v[c]++;
    }

    void decrementa(int c){
        v[c]--;
    }

    void stampa(){
        for (int i = 0; i < sizeof(v); i++){
            cout<<v[i]<<endl;
        }
    }
    

};

int main(){
    
    cout<<"ciao";
    return 0;
}

