#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class Calc{
    public:
        Calc(){
        };
        int Somma(int a, int b){
            return a+b;
        };
        int Sottrazione (int a, int b){
            return a-b;
        };
        int Moltiplicazione (int a, int b){
            return a*b;
        }; 
        int Quadrato (int a){
            return a*a;
        }; 
        int Cubo (int a){
            return a*a*a;
        }; 
        int Incremento (int a){
            return a+1;
        }; 
        int Decremento (int a){
            return a-1;
        };
};

int main(){
    int a=1,b=2;
    Calc c = Calc();
    cout << "Somma: " << c.Somma(a,b) << endl;
    return 0;
}
