/*
 * Scrivi un programma C++ che all'interno di una classe chiamata Test, definisca un array di stringhe statico.
 * Il programma tramite un costruttore (con numElem come parametro) deve leggere da input l'array di stringhe e fare l'ordinamento decrescente per parole.
 * 
 * Modifica il file precedente in questo modo.
 * Duplica un oggetto della classe precedente grazie al costruttore copia, in questo modo avrai due oggetti della classe Test obj1 e obj2. Adesso scrivi i seguenti metodi di classe:
 * - rimuoviVocali(): il metodo rimuove tutte le vocali facendo uno shift a sinistra di tutte le vocali presenti nell'array di stringhe ordinato,
 * - rimuoviConsonanti(): il metodo rimuove tutte le consonanti facendo uno shift a sinistra di tutte le consonanti presenti nell'array di stringhe ordinato.
 * Applica rimuoviVocali() su obj1, e rimuoviConsonanti() su obj2.
 * Riordina di nuovo gli array di stringhe sui due oggetti usando una funzione della classe, stampa le stringhe risultato e tramite una funzione della classe contaLunghezza() dichiara se ci sono piu' lettere in obj1 oppure in obj2.
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

        Test (const Test& obj){
            numElem=obj.numElem;
            for(int i=0; i<10; i++){
                str[i]=obj.str[i];
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

        void RimuoviVocali(){
            for (int i = 0; i < 10; i++){
                while (str[i].find_first_of("aeiou")!=-1){
                    str[i].erase(str[i].find_first_of("aeiou"),1);
                }
            }
        }

        void RimuoviCons(){
            for (int i = 0; i < 10; i++){
                while (str[i].find_first_not_of("aeiou")!=-1){
                    str[i].erase(str[i].find_first_not_of("aeiou"),1);
                }
            }
        }

        int ContaLunghezza(){
            int ctr=0;
            for (int i = 0; i < 10; i++){
                ctr+=str[i].length();
            }
            return ctr;
        }
};

int main(){
    int n;
    cout<<"Inserisci numElem: ";
    cin>>n;
    cin.ignore();
    Test test = Test(n);
    Test test2 = Test(test);
    test.RimuoviVocali();
    test2.RimuoviCons();
    test.sort();
    test2.sort();
    test.print();
    cout<<"-----------------"<<endl;
    test2.print();
    cout<<"-----------------"<<endl;
    if(test.ContaLunghezza()>test2.ContaLunghezza()){
        cout<<"Ci sono piu' lettere in test"<<endl;
    }else{
        cout<<"Ci sono piu' lettere in test2"<<endl;
    }
    return 0;
}