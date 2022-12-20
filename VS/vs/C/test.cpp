#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>                                           //PERMETTE DI FARE VETTORI PIU FIGHI

using namespace std;

int main(){
    vector <int> vettore;
    int i;

    for(i=0;i<10;i++){
        vettore.push_back(i);
    }
    vettore.erase(vettore.begin());
    vettore.erase(vettore.begin());

    for(i=0;i<10;i++){
        cout<<vettore[i]<<endl;
    }
    cout<<vettore.size()<<endl;
    return 0;
}