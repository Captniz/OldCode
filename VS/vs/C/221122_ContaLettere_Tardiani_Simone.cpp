/*Scrivi una classe C++ ContaLettere che, letto un testo da file di testo, in un array allocato dinamicamente memorizzi nel programma in tanti oggetti ContaLettere quante sono le lettere alfabetiche presenti, contando quante sono le lettere del testo.  NON deve essere memorizzato alcun oggetto quando non è presente nessuna lettera nel testo. Per ipotesi tutte le lettere del testo sono minuscole e non ci sono numeri. Nell’oggetto deve essere memorizzata la lettera e una variabile contatore.
Esempio: arca darca
Memorizza i seguenti oggetti :
‘a’:4 ; ‘r’:2 ; c:’2’ ; d:’1’*/
#include<iostream>
#include<fstream>

using namespace std;

class ContaLettere{
    public:
    int ctr;
    char c;
    ContaLettere(){
        c=0;
        ctr=0;
    }
    ContaLettere(char c){
        this->c=c;
        ctr=0;
    }
    bool operator==(const ContaLettere &p1){
        if(p1.c==this->c){
            return true;
        }else{
            return false;
        }
        
    }
};
int main(){
    ContaLettere *v = new ContaLettere [26];
    char c=0;
    int ctr=0;

    for (int i = 0; i < 26; i++){
        v[i] = ContaLettere();
    }

    fstream file = fstream();
    file.open("input.txt", file.in);

    
    while(file>>c){
        c=tolower(c);
        v[(c-'a')].c=1;
    }
    for (int i = 0; i < 26; i++){
        ctr+=v[i].c;
    }

    v = new ContaLettere[ctr];

    for (int i = 0; i < ctr; i++){
        v[i]=ContaLettere();
    }

    file.close();
    file.open("input.txt", file.in);

    while(file>>c){
        for (int i = 0; i < ctr; i++){
            if(v[i].c==c){
                v[i].c=c;
                v[i].ctr++;
                break;
            }else if(v[i].c==0){
                v[i].c=c;
                v[i].ctr++;
                break;
            }
        }
    }
    
    for (int i = 0; i < ctr; i++){
        cout<<v[i].c<<"-"<<v[i].ctr<<endl;
    }

    file.close();
    return 0;
}