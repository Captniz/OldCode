#include <iostream>
#include <string>
using namespace std;

class Test{
    private:
        string v[10]; 
        int numElem;
    public:
        Test(int numElem){
            for(int i = 0; i < numElem; i++){
                cout << "Inserisci la stringa: ";
                cin >> v[i];
            }
        }
        void ordina(int numElem){
            string temp;
            for(int i = 0; i < numElem; i++){
                for(int j = i + 1; j < numElem; j++){
                    if(v[i] < v[j]){
                        temp = v[i];
                        v[i] = v[j];
                        v[j] = temp;
                    }
                }
            }
        }
        void stampa(int numElem){
            for(int i = 0; i < numElem; i++){
                cout << v[i] << " ";
            }
        }
};

int main(){
    int numElem=10;
    cout << "Inserisci il numero di elementi: ";
    cin >> numElem;
    Test oggetto(numElem);
    oggetto.ordina(numElem);
    oggetto.stampa(numElem);
    return 0;
}