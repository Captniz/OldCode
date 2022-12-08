/*
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
        Test (const Test& obj){
            numElem=obj.numElem;
            for(int i=0; i<10; i++){
                v[i]=obj.v[i];
            }
        };
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
                cout  << v[i] << " ";
            }
            cout << endl;
        }
        void rimuoviVocali(int numElem){
            for(int i = 0; i < numElem; i++){
                while(v[i].find_first_of("aeiou")!=-1){
                    v[i].erase(v[i].find_first_of("aeiou"), 1);
                }
            }
        }
        void rimuoviConsonanti(int numElem){
            for(int i = 0; i < numElem; i++){
                while(v[i].find_first_not_of("aeiou")!=-1){
                    v[i].erase(v[i].find_first_not_of("aeiou"), 1);
                }
            }
        }
        int contaLunghezza(int numElem){
            int lunghezza = 0;
            for(int i = 0; i < numElem; i++){
                lunghezza += v[i].length();
            }
            return lunghezza;
        }
};

int main(){
    int numElem=3;
    Test oggetto(numElem);
    oggetto.ordina(numElem);
    oggetto.stampa(numElem);
    Test oggetto2=Test(oggetto);
    oggetto2.rimuoviVocali(numElem);
    oggetto2.stampa(numElem);
    return 0;
}
*/
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
        Test (const Test& obj){
            numElem=obj.numElem;
            for(int i=0; i<10; i++){
                v[i]=obj.v[i];
            }
        };
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
                cout  << v[i] << " ";
            }
            cout << endl;
        }
        void rimuoviVocali(int numElem){
            for(int i = 0; i < numElem; i++){
                while(v[i].find_first_of("aeiou")!=-1){
                    v[i].erase(v[i].find_first_of("aeiou"), 1);
                }
            }
        }
        void rimuoviConsonanti(int numElem){
            for(int i = 0; i < numElem; i++){
                while(v[i].find_first_not_of("aeiou")!=-1){
                    v[i].erase(v[i].find_first_not_of("aeiou"), 1);
                }
            }
        }
        int contaLunghezza(int numElem){
            int lunghezza = 0;
            for(int i = 0; i < numElem; i++){
                lunghezza += v[i].length();
            }
            return lunghezza;
        }
};

int main(){
    int numElem=10;
    Test oggetto(numElem);
    oggetto.ordina(numElem);
    oggetto.stampa(numElem);
    Test oggetto2(oggetto);
    oggetto2.rimuoviVocali(numElem);
    oggetto2.stampa(numElem);
    oggetto.rimuoviConsonanti(numElem);
    oggetto.stampa(numElem);
    if(oggetto2.contaLunghezza(numElem) > oggetto.contaLunghezza(numElem))
        cout << "Ci sono piu' lettere in oggetto2" << endl;
    else
        cout << "Ci sono piu' lettere in oggetto1" << endl;
    return 0;
}