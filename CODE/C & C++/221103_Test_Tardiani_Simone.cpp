/*
 * Scrivi un programma C++ che all'interno di una classe chiamata Test, definisca un array di stringhe statico.
 * Il programma tramite un costruttore (con numElem come parametro) deve leggere da input l'array di stringhe e fare l'ordinamento decrescente per parole.
*/
#include<iostream>
#include<string>
using namespace std;

class Test{
    private:
        string str[10];
        int numElem;
    public:

        Test(int n){
            numElem=n;
            for (int i = 0; i < 10; i++){
                cout<<"Inserisci la "<<i+1<<" stringa: ";
                cin>>str[i];
                cin.ignore();
            }
        };

        void sort(){
            string temp;
            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10-1; j++){
                    if(str[j]<str[j+1]){
                        temp=str[j];
                        str[j]=str[j+1];
                        str[j+1]=temp;
                    }
                }
            }
        };
        void print(){
            for (int i = 0; i < 10; i++){
                cout<<str[i]<<endl;
            }
        };
};

int main(){
    int n;
    cout<<"Inserisci numElem: ";
    cin>>n;
    cin.ignore();
    Test test = Test(n);
    test.sort();
    test.print();
    return 0;
}