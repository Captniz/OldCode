/*Scrivi un programma in C++ che implementi le classi necessari per la seguente realtà.
Si vuole scrivere un programma che realizzi la contabilità di una scuola.*/
#include <iostream>
#include <string>
using namespace std;

//Un dipendente è una classe dove vengono memorizzati, un nome, un cognome,un codice identificativo (numero progressivo), il numero di lezioni totali che svolge a settimana, e il suo stipendio lordo.
class Dipendente{
    protected:
        string nome;
        string cognome;
        int codice;
        int lezioneSettimanale;
        float stipendio;
    public:
        Dipendente(string nome, string cognome, int codice, int lezioneSettimanale){
            this->nome = nome;
            this->cognome = cognome;
            this->codice = codice;
            this->lezioneSettimanale = lezioneSettimanale;
        };
        Dipendente(){
            nome = "";
            cognome = "";
            codice = 0;
            lezioneSettimanale = 0;
        };
        string getNome(){
            return nome;
        }
        string getCognome(){
            return cognome;
        }
        int getCodice(){
            return codice;
        }
        float getStipendio(){
            return stipendio;
        }
};
//dirigente scolastico, dipendente dove è memorizzato il codice meccanografico della scuola (es. MNIS00IE) e quanti sono gli studenti della scuola. Lo stipendio del DS è di 23000€ + 0,5€ per ogni studente della scuola.
class Dirigente: public Dipendente{
    protected:
        string codiceMeccanografico;
        int numeroStudenti;
    public:
        Dirigente(string nome, string cognome, int codice, int lezioneSettimanale, string codiceMeccanografico, int numeroStudenti){
            this->codiceMeccanografico = codiceMeccanografico;
            this->numeroStudenti = numeroStudenti;
            this->nome = nome;
            this->cognome = cognome;
            this->codice = codice;
            this->lezioneSettimanale = lezioneSettimanale;
            stipendio = 23000 + (0.5 * numeroStudenti);
        };
        Dirigente(){
            codiceMeccanografico = "";
            numeroStudenti = 0;
        };
        void calcola(){
            stipendio = 23000 + (0.5 * numeroStudenti);
        };
        void StampaDettagliDipendente(){
            cout << "Nome: " << nome << endl;
            cout << "Cognome: " << cognome << endl;
            cout << "Codice: " << codice << endl;
            cout << "Stipendio: " << stipendio << endl;
            cout << "Codice Meccanografico: " << codiceMeccanografico << endl;
            cout << "Numero Studenti: " << numeroStudenti << endl;
        };
};
//docente, ogni docente è distinto, oltre dal numero di ore settimanali di lezione da quante ore di corsi di recupero fa. Ogni ora di corso di recupero è pagata 50€ all'ora. Un docente, se fa lezione guadagna 22€ all'ora di lezione.
class Docente: public Dipendente{
    protected:
        int oreRecupero;
    public:
        Docente(string nome, string cognome, int codice, int lezioneSettimanale, int oreRecupero){
            this->oreRecupero = oreRecupero;
            this->nome = nome;
            this->cognome = cognome;
            this->codice = codice;
            this->lezioneSettimanale = lezioneSettimanale;
            stipendio = (lezioneSettimanale * 22) + (oreRecupero * 50);
        };
        Docente(){
            oreRecupero = 0;
        };
        void calcola(){
            stipendio = (lezioneSettimanale * 22) + (oreRecupero * 50);
        };
        void StampaDettagliDipendente(){
            cout << "Nome: " << nome << endl;
            cout << "Cognome: " << cognome << endl;
            cout << "Codice: " << codice << endl;
            cout << "Stipendio: " << stipendio << endl;
            cout << "Codice Meccanografico: " << oreRecupero << endl;
        };
};
//docente referente di dipartimento. Ogni referente di dipartimento ha memorizzato quale dipartimento dirige e prende uno stipendio ulteriore di 1000€ rispetto a tutti i docenti normali.
class DocenteReferente: public Docente{
    protected:
        string dipartimento;
    public:
        DocenteReferente(string nome, string cognome, int codice, int lezioneSettimanale, int oreRecupero, string dipartimento){
            this->dipartimento = dipartimento;
            this->nome = nome;
            this->cognome = cognome;
            this->codice = codice;
            this->lezioneSettimanale = lezioneSettimanale;
            this->oreRecupero = oreRecupero;
            stipendio = (lezioneSettimanale * 22) + (oreRecupero * 50) + 1000;
        };
        DocenteReferente(){
            dipartimento = "";
        };
        void calcola(){
            stipendio = (lezioneSettimanale * 22) + (oreRecupero * 50) + 1000;
        };
        void StampaDettagliDipendente(){
            cout << "Nome: " << nome << endl;
            cout << "Cognome: " << cognome << endl;
            cout << "Codice: " << codice << endl;
            cout << "Stipendio: " << stipendio << endl;
            cout << "Codice Meccanografico: " << oreRecupero << endl;
            cout << "Dipartimento: " << dipartimento << endl;
        };
};

//funzione (del main) stampaStipendioDipendente() che stampi i dettagli base di ogni dipendente e lo stipendio
void stampaStipendioDipendente(Dirigente drg, DocenteReferente docRef, Docente docs[], int id){
    cout << "------------------------" << endl;
    cout << "Nome: " << drg.getNome() << endl;
    cout << "Cognome: " << drg.getCognome() << endl;
    cout << "Codice: " << drg.getCodice() << endl;
    cout << "Stipendio: " << drg.getStipendio() << endl;
    cout << "------------------------" << endl;
    cout << "Nome: " << docRef.getNome() << endl;
    cout << "Cognome: " << docRef.getCognome() << endl;
    cout << "Codice: " << docRef.getCodice() << endl;
    cout << "Stipendio: " << docRef.getStipendio() << endl;
    for(int i = 0; i<(id-2); i++){
        cout << "------------------------" << endl;
        cout << "Nome: " << docs[i].getNome() << endl;
        cout << "Cognome: " << docs[i].getCognome() << endl;
        cout << "Codice: " << docs[i].getCodice() << endl;
        cout << "Stipendio: " << docs[i].getStipendio() << endl;
    }
}

int main(){
    Docente docente[2];
    int id = 0;
    
    Dirigente drg = Dirigente("Claudio", "Bisio", ++id, 0, "MNIS00IE", 100);
    DocenteReferente drf = DocenteReferente("Vanessa", "Incontrada", ++id, 10, 3, "Coreutica");
    docente[0] = Docente("Giancarlo", "Giannini", ++id, 5, 4);
    docente[1] = Docente("Giovanni", "Caccioppo", ++id, 7, 5); 

    stampaStipendioDipendente(drg, drf, docente, id);

    return 0;
}