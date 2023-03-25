#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int n=0;
    int ctr=0;
    int **m;
    fstream file;
    file.open("input.txt", ios::out|ios::in|ios::app);

    file >> n;
    m = new int * [n];
    for(int i = 0; i < n; i++){
        m[i] = new int [n];
    } 

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            file >> m[i][j];
            if (i==j){
                ctr+=m[i][j];
            }
        }
    }
    file.clear(); 
    file<<"\n\nDiagonale 1: "<<ctr<<endl;
    ctr=0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j==(n-i-1)){
                ctr+=m[i][j];
            }
        }
    }
    file<<"Diagonale 2: "<<ctr<<endl;
    return 0;
}   