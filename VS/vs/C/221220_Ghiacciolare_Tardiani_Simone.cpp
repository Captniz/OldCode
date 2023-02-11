//DESCRIZIONE : 
//*Anche nel nostro stabilimento balneare di fiducia è quasi Natale, e al posto degli ombrelloni e lettini il nostro proprietario ha messo su una bellissima pista di pattinaggio.
//*La pista può ospitare 100 persone contemporaneamente al massimo.
//*Per pattinare si noleggiano delle scarpe pattini; lo stabilimento ne ha 5 per ogni taglia dal [30 al 45) e ogni persona può pattinare solo se è disponibile un paio di scarpe pattini della sua misura.
//*Accedono alla pista in contemporanea una o più persone in gruppo con il loro paio di scarpe, con una registrazione dell’ora e minuti di inizio accesso alla pista.
//*Se la pista non è in grado di ospitare tutte le persone o se le scarpe non sono disponibili le persone si mettono in coda di ingresso. (Ti consiglio un array circolare di oggetti per implementarlo).
//*Al termine dell’accesso della pista viene registrata l’ora di uscita ed è fatta pagare una tariffa di 10 centesimi al minuto per persona . La tariffa è scontata del 25% se le persone erano almeno in gruppo di tre persone. La tariffa viene calcolata sul gruppo di persone. 
//*Ogni 10 noleggi ogni paio di scarpe viene messo in manutenzione per 15 minuti per essere affilato. Ogni manutenzione costa 2 euro.
//*La manutenzione della pista costa 20 cent al minuto.
//*Scrivi un programma C++ che implementi tutte le classi necessarie per la gestione degli ingressi e delle uscite.
//*Il programma oltre a questo calcola e stampa il totale dei costi e degli introiti della pista, con opportune funzioni che forniscano l’output.
//*Il programma stampa anche quante persone sono nella pista e quali paia di scarpe sono occupate e quali disponibili.*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>                                                                                  
using namespace std;

//TUTTE QUESTE VARIABILI SONO GLOBALI NON PERCHE' SONO UTILIZZATE IN PIU' CLASSI MA PIU' CHE ALTRO LE HO USATE PER EVITARE DI DOVERLE CAMBIARE NELLE VARIE CLASSI SE DEVO FARE UNA DIMOSTRAZIONE DEL PROGRAMMA
time_t timeInSec;                                                                                   //VARIABILE PER TEMPO
const int nPattiniXTaglia = 5;                                                                      //NUMERO PATTINI X TAGLIA
const int nTaglie = 15;                                                                             //NUMERO TAGLIE
const int playTime = 2;                                                                             //TEMPO DI ATTIVITA'
const int usiMax = 5;                                                                               //USI MASSIMI PATTINI
const int fixTime = 1;                                                                              //TEMPO MANUTENZIONE
const int timeMultiplier = 5;                                                                       //MULTIPLICATORE TEMPO
const int nMaxPersone = 5;                                                                          //MAX PERSONE x GRUPPO
const long long startTime = (long long)time(&timeInSec);                                            //TEMPO INIZIALE

class Pattino{
//CLASSE PATTINO
//DESCR : classe che rappresenta un singolo pattino
//ATTRIB : taglia, disponibile, usi, releaseTime
//METODI : usa(), rilascia()
//METODI GET/SET/ETC : getTaglia(), getDisponibile(), getUsi()
    private:
    int taglia;                                                                                     //TAGLIA PATTINO     
    bool disponibile;                                                                               //DISPONIBILITA'
    int usi;                                                                                        //USI RIMANENTI
    long long releaseTime;                                                                          //TEMPO DI RILASCIO

    public:
        Pattino(){
            this->taglia = 0;
            this->disponibile = true;
            this->usi = usiMax;
            this->releaseTime=0;
        }
        Pattino(int taglia){
            this->taglia = taglia;
            this->disponibile = true;
            this->usi = usiMax;
            this->releaseTime=0;
        }
        bool usa(){
        //ASKS :
        //RETURN : 'false' in caso di successo, 'true' in caso di fallimento
        //DESCR : se il pattino e' disponibile usalo, altrimenti controlla che sia finita la manutenzione e in tal caso usalo

            if(!disponibile){                                                                       //SE NON DISPONIBILE
                if(releaseTime>=(long long)time(&timeInSec)){                                           //SE (TEMPO DI MAUNTENZIONE > TEMPO ATTUALE) -> LA MANUTENZIONE E' FINITA / NEL CASO TEMPO DI MAUNTENZIONE==0 VUOL DIRE CHE QUALCUNO LO USA GIA
                    this->usi=usiMax;                                                                       //RESET USI
                    disponibile = true;                                                                     //DISPONIBILE                    
                    releaseTime = 0;                                                                        //RESET TEMPO RILASCIO                      
                }else{                                                                                  //ALTRIMENTI:
                    return true;                                                                            //RETURN NON DISPONIBILE
                }
            }
            this->usi--;                                                                            //DIMINUZIONE USI PATTINO
            this->disponibile=false;                                                                //SET NON DISPONIBILE       
            
            return false;                                                                           //RETURN SUCCESSO      
        }
        bool rilascia(){           
        //ASKS :
        //RETURN : 'false' in caso di successo, 'true' in caso di successo ma il pattino necessita di manutenzione
        //DESCR : rilascia il pattino e controlla se necessita di manutenzione
        //APPUNTI : ho dovuto mettere il pagamento delle manutenzioni nel main perche' altrimenti le classi si intrecciano chiamando qui 'Pista' e mi da errore di classe non definita

            this->disponibile = true;                                                               //SET DISPONIBILE IL PATTINO

            //MANUTENZIONE
            if(this->usi == 0){                                                                     //SE GLI USI SONO FINITI
                this->disponibile=false;                                                            //SET NON DISPONIBILE               
                this->releaseTime = (long long) time(&timeInSec) + (60*fixTime/timeMultiplier);     //SET TEMPO RILASCIO -> (60*Tempo necessario riparazione/moltiplicatore del tempo per tempo simulato)
                return true;                                                                        //RETURN NECESSITA DI MANUTENZIONE -> AGGIUNGERE 2 EURO ALLE SPESE
            }
            return false;                                                                           //RETURN NON NECESSITA DI MANUTENZIONE
        }

        //GET/SET/ADD/SUB FUNCTIONS:
        int getUsi(){
            return this->usi;
        }
        int getTaglia(){
            return this->taglia;
        }
        bool getDisponibile(){
            return this->disponibile;
        }
};
class Pista{
//CLASSE PISTA
//DESCR : classe che rappresenta la pista principale e piu' in generale la struttura che gestisce il pattino
//ATTRIB : personeMax, personeActual, Spese, Incassi, pattini
//METODI : getPattini(), rilasciaPattino(), addSpese(), addIncassi(), getPersoneMax(), getPersoneActual(), getSpese(), getIncassi(), getPattino()
//METODI GET/SET/ETC : getPersoneMax(), getPersoneActual(), addPersone(), removePersone(), getSpese(), addSpese(), getIncassi(), addIncassi(), getDisponibilita()
    private:
    int personeMax;                                                                                 //MAX PERSONE
    int personeActual;                                                                              //PERSONE ATTUALI
    float Spese;                                                                                    //SPESA TOTALE
    float Incassi;                                                                                  //INCASSI TOTALE
    Pattino pattini[nPattiniXTaglia][nTaglie];                                                      //MATRICE PATTINI TOTALI

    public:
        Pista(){
            this->Incassi = 0;
            this->Spese = 0;
            this->personeMax = 100;
            this->personeActual = 0;

            for(int i = 0; i < nPattiniXTaglia; i++){
                for(int j = 0; j < nTaglie; j++){
                    this->pattini[i][j] = Pattino(30 + j);  //RIGHE: TAGLIA, COLONNE: PATTINI SINGOLI x TAGLIA
                    /*  10 20 30
                        10 20 30
                        10 20 30 etc...*/
                }
            }
        }
        Pattino* getPattini(int taglia){
        //ASKS : int taglia
        //RETURN : puntatore al pattino disponibile della taglia selezionata, NULL in caso di pattino non disponibile
        //DESCR : se il pattino e' disponibile usalo e ritorna il puntatore, altrimenti se non ci sono pattini disponibili ritorna NULL

            for(int i = 0; i < nPattiniXTaglia; i++){                                               //PER OGNI PATTINO DELLA TAGLIA SELEZIONATA
                if(!pattini[i][taglia-30].usa()){                                                       //SE DISPONIBILE
                    return &pattini[i][taglia-30];                                                          //RETURN PATTINO
                }
            }
            return NULL;                                                                            //RETURN NULL
        }
        int getDisponibilita(){
        //ASKS : 
        //RETURN : numero di pattini disponibili
        //DESCR : ritorna il numero di pattini disponibili attraverso un contatore
            
            int disponibilita = 0;
            for(int i = 0; i < nPattiniXTaglia; i++){                                               //PER OGNI PATTINO DELLA TAGLIA SELEZIONATA
                for(int j = 0; j < nTaglie; j++){                                                           //PER OGNI TAGLIA
                    if(pattini[i][j].getDisponibile()){                                                         //SE DISPONIBILE
                        disponibilita++;                                                                            //INCREMENTA DISPONIBILITA'
                    }
                }
            }
            return disponibilita;                                                                   //RETURN DISPONIBILITA'
        }

        //GET/SET/ADD/SUB FUNCTIONS:
        int getPersoneMax(){
            return this->personeMax;
        }
        int getPersoneActual(){
            return this->personeActual;
        }
        void addPersone(int persone){
            this->personeActual += persone;
        }
        void removePersone(int persone){
            this->personeActual -= persone;
        }
        float getSpese(){
            return this->Spese;
        }
        void addSpese(float spese){
            this->Spese += spese;
        }
        float getIncassi(){
            return this->Incassi;
        }
        void addIncassi(float incassi){
            this->Incassi += incassi;
        }
};
class Gruppo{
//CLASSE GRUPPO
//DESCR : classe che rappresenta un gruppo di persone che entra nello stabilimento
//ATTRIB : persone, taglie, pattini, tempoInizio
//METODI : 
//METODI GET/SET/ETC : getListaPattini(), getTempoInizio(), getPersone()
    private:
    int persone;                                                                                    //NUMERO PERSONE DEL GRUPPO
    int *taglie;                                                                                    //TAGLIE DEL GRUPPO             
    Pattino **pattini;                                                                              //PATTINI DEL GRUPPO
    long long tempoInizio;                                                                          //TEMPO INIZIO ATTIVITA'
    int modificatoreTempo;

    public:
        Gruppo(){
            srand(time(NULL));
            this->persone = 0;
            this->pattini = NULL;
            this->taglie = NULL;
            this->tempoInizio = 0;
            this->modificatoreTempo = (rand() % 15 + 15)/timeMultiplier;  
        }
        Gruppo(int persone){
            srand(time(NULL));
            this->persone = persone;
            this->taglie = new int[persone];
            for(int i = 0; i < persone; i++){                                                       //PER OGNI PERSONA DEL GRUPPO
                this->taglie[i] = rand() % nTaglie + 30;                                                //TAGLIE RANDOM DA 30 A (30+nTaglie-1)
            }
            this->pattini = new Pattino *[persone];             
            this->tempoInizio = 0;
            this->modificatoreTempo = ((rand() % 15 + 15)*60/timeMultiplier);
        } 
        void MettInPista(Pista *p, vector <Gruppo> &gruppiInPista, vector <Gruppo> &gruppiInCoda){  
        //ASKS : Pista p, vector <Gruppo> &gruppiInPista, vector <Gruppo> &gruppiInCoda
        //RETURN :
        //DESCR : mette il gruppo in pista se possibile, altrimenti lo mette in coda

            if (p->getPersoneActual() + persone > p->getPersoneMax()){                                //SE (NUMERO DI PERSONE IN PISTA + PERSONE DEL GRUPPO) > MAX PERSONE IN PISTA -> TROPPE PERSONE NELLA PISTA
                gruppiInCoda.push_back(*this);                                                          //METTI IN CODA GRUPPO
                return;                                                                                 //ESCI             
            }
            for (int i = 0; i < persone; i++){                                                      //PER OGNI PERSONA DEL GRUPPO
                pattini[i] = p->getPattini(taglie[i]);                                                   //PRENDI PATTINO
                if(pattini[i] == NULL){                                                                 //SE NON DISPONIBILE ANCHE SOLO UN PATTINO
                    gruppiInCoda.push_back(*this);                                                          //METTI IN CODA GRUPPO
                    return;                                                                                 //RETURN 
                }
            }
            tempoInizio = (long long) time(&timeInSec);                                             //SET TEMPO INIZIO ATTIVITA'
            gruppiInPista.push_back(*this);                                                         //METTI IN PISTA GRUPPO
            cout<<"Un gruppo e' entrato in pista!"<<endl;                                           //MESSAGGIO DI ENTRATA GRUPPO
            p->addPersone(persone);                                                                  //AGGIUNGI PERSONE AL NUMERO DI PERSONE IN PISTA
        }
        void EsciDallaPista(Pista *p){
        //ASKS : Pista p
        //RETURN :
        //DESCR : esce dalla pista, fa pagare e rilascia i pattini

            for(int i = 0; i < persone; i++){                                                       //PER OGNI PERSONA DEL GRUPPO
                if(pattini[i]->rilascia()){                                                             //RILASCIA PATTINO
                    p->addSpese(2);                                                                          //AGGIUNGI SPESA SE IL PATTINO NECESSITA DI MANUTENZIONE
                }                    
            }
            if (persone>=3){                                                                        //SE PERSONE >= 3   
                p->addIncassi(((persone*playTime*0.10)-((persone*playTime*0.10)/4)));                       //AGGIUNGI INCASSI -> (PERSONE * 0.10 * TEMPO DI GIOCO - 25% DI SCONTO)
            }else{                                                                                  //ALTRIMENTI                      
                p->addIncassi((persone*playTime*0.10));                                                     //AGGIUNGI INCASSI -> (PERSONE * 0.10 * TEMPO DI GIOCO)                   
            }
            p->removePersone(persone);                                                               //RIMUOVI PERSONE DAL NUMERO DI PERSONE IN PISTA
            cout<<"Un gruppo e' uscito!"<<endl;                                                     //MESSAGGIO DI USCITA GRUPPO
        }

        //GET/SET/ADD/SUB FUNCTIONS:
        Pattino** getListaPattini(){
            return pattini;   
        }
        long long getTempoInizio(){
            return tempoInizio;
        }
        int getPersone(){
            return persone;
        }
        int getModTempo(){
            return modificatoreTempo;
        }
};

void printInfo(Pista pista, vector<Gruppo> gruppiInPista, vector<Gruppo> gruppiInCoda){
//ASKS : Pista p, vector <Gruppo> &gruppiInPista, vector <Gruppo> &gruppiInCoda
//RETURN :
//DESCR : stampa le informazioni della pista

    cout << "----------------------------------------" << endl;
    cout << "Pattini: " << pista.getDisponibilita() << " pattini disponibili" << endl;
    cout << "Coda: " << gruppiInCoda.size() << " gruppi in coda" << endl;
    cout << "Pista: " << gruppiInPista.size() << " gruppi in pista" << endl;
    cout << "Persone: " << pista.getPersoneActual() << " persone in pista" << endl;
    cout << "Incassi: " << pista.getIncassi() << endl;
    cout << "Spese: " << pista.getSpese() << endl;
    cout << "Guadagno: " << pista.getIncassi()-pista.getSpese() << endl;
    cout << "Gruppi in pista: " << endl;
    for(int i = 0; i < gruppiInPista.size(); i++){
        cout << "Gruppo " << i+1 << ": " << gruppiInPista[i].getPersone() << " persone" << /*"|" << (gruppiInPista[i].getModTempo()+playTime*60/timeMultiplier) << */endl;
    }
    cout << "Gruppi in coda: " << endl;
    for(int i = 0; i < gruppiInCoda.size(); i++){
        cout << "Gruppo " << i+1 << ": " << gruppiInCoda[i].getPersone() << " persone" << /*"|" << (gruppiInCoda[i].getModTempo()+playTime*60/timeMultiplier) << */endl;
    }
    cout << "----------------------------------------" << endl;
}

int main(){
    srand(time(NULL));                                                  
    Pista pista;                                                                                    //CREA PISTA    
    Gruppo g;                                                                                       //CREA GRUPPO                                
    vector<Gruppo> gruppiInPista;                                                                   //CREA VETTORE DI GRUPPI IN PISTA
    vector<Gruppo> gruppiInCoda;                                                                    //CREA VETTORE DI GRUPPI IN CODA
    long long tempoPassato1min = 0;                                                                 //TEMPO ATTUALE PRIMA CHE PASSI UN MINUTO -> SI AGGIORNA OGNI MINUTO                                     
    int tempoRnd = 0;                                                                               //TEMPO RANDOM PER INTERVALLO DI TEMPO TRA ENTRATA DI NUOVO GRUPPO                                
    bool entrataPeriodica = false;                                                                  //SE E' ENTRATO UN GRUPPO NEL MINUTO ATTUALE
    int codaActual = 0;                                                                             //NUMERO DI GRUPPI IN CODA ATTUALMENTE -> PER EVITARE DI CONTROLLARE PIU VOLTE DELLE PERSONE
    int ctrl = 0;                                                                                   //CONTATORE PER EVITARE DI CONTROLLARE PIU VOLTE DELLE PERSONE
    
    cout<<"La pista e' aperta!"<<endl;                                                              //MESSAGGIO DI INIZIO
    while(1){                                                                                       //CICLO INFINITO
        tempoPassato1min = (long long)time(&timeInSec);                                             //AGGIORNA TEMPO ATTUALE                     
        entrataPeriodica = false;                                                                   //RESET ENTRATA PERIODICA                  
        tempoRnd = (rand() % 21 + 30)/timeMultiplier;                                               //TEMPO RANDOM DA 30 A 50 SECONDI -> (rnd[30...50] / timeMultiplier)
        while((long long)time(&timeInSec)-tempoPassato1min<(60/timeMultiplier)){                    //CICLO PER 1 MINUTO (ACCELLERATO SECONDO timeMultiplier) -> .(60/timeMultiplier)
            if(!entrataPeriodica && (long long)time(&timeInSec)-tempoPassato1min>=tempoRnd){            //SE E' PASSATO IL TEMPO RANDOM E NON E' ENTRATO UN GRUPPO NEL MINUTO ATTUALE
                cout<<"Un gruppo e' entrato, tempo random di entrata: "<<tempoRnd<<endl;                    //MESSAGGIO DI ENTRATA GRUPPO
                g = Gruppo(rand() % nMaxPersone + 1);                                                       //GRUPPO RANDOM DA 1 A 5
                gruppiInCoda.push_back(g);                                                                  //AGGIUNGI GRUPPO IN CODA 
                entrataPeriodica = true;                                                                    //SET ENTRATA PERIODICA A TRUE
            }
        }
                                                                                                    //OGNI MINUTO

        cout<<"Un minuto e' passato!"<<endl;                                                        //MESSAGGIO DI FINE MINUTO                                   
        pista.addSpese(0.20);                                                                       //AGGIUNGI SPESA PER MANUTENZIONE PISTA 
        printInfo(pista, gruppiInPista, gruppiInCoda);                                              //STAMPA INFO PISTA              
        
                                                                                                    //FAI USCIRE LA GENTE CHE HA FINITO
        codaActual = gruppiInPista.size();                                                          //AGGIORNA NUMERO DI GRUPPI IN CODA ATTUALMENTE -> EVITA ERRORI DI LETTURA DELL ARRAY
        ctrl = 0;                                                                                   //RESET CONTATORE                              
        for(int i=0;i < codaActual;i++){                                                            //PER OGNI GRUPPO IN CODA
            if((gruppiInPista[ctrl].getTempoInizio() + (playTime*60/timeMultiplier)) < (long long)time(&timeInSec)){     //SE IL TEMPO DI ATTIVITA' E' FINITO
                gruppiInPista[ctrl].EsciDallaPista(&pista);                                              //FA USCIRE IL GRUPPO
                gruppiInPista.erase(gruppiInPista.begin()+ctrl);                                        //RIMUOVI IL GRUPPO DAL VETTORE
            }else{                                                                                  //ALTRIMENTI:
                ctrl++;                                                                                 //INCREMENTA CONTATORE                               
            }
        }

                                                                                                    //FAI ENTRARE LA GENTE CHE HA FINITO DI ASPETTARE
        codaActual = gruppiInCoda.size();                                                           //AGGIORNA NUMERO DI GRUPPI IN CODA ATTUALMENTE -> EVITA ERRORI DI LETTURA DELL ARRAY
        for(int i=0;i < codaActual;i++){                                                            //PER OGNI GRUPPO IN CODA               
            gruppiInCoda[0].MettInPista(&pista, gruppiInPista, gruppiInCoda);                           //FA ENTRARE IL GRUPPO -> NEL CASO NON POSSA ENTRARE, LO RIMETTE IN CODA LA FUNZIONE
            gruppiInCoda.erase(gruppiInCoda.begin());                                                   //RIMUOVI IL GRUPPO DAL VETTORE               
        }
    }

    return 0;
}