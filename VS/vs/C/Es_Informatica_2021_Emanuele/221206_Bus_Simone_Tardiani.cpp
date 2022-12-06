#include <iostream>
#include <string>
using namespace std;

//Creare la classe MezziTrasporto con attributi: velocità massima, 
//tipo di trazione (animale, muscolare, motore) e numero di persone massimo trasportabili.
class MezziTrasp{
    protected:
        int velMax;
        string trazione;
        int nPersone;
    public:
        MezziTrasp(int velMax, int trazione, int nPersone){
            string trz[3] = {"animale", "muscolare", "motore"};
            this->velMax = velMax;
            this->trazione = trz[trazione];
            this->nPersone = nPersone;
        }
        MezziTrasp(){}
};
//Creare la sottoclasse VeicoloAmotore che eredita tutti i membri di MezziTrasporto, 
//ma prevede anche il consumo e il tipo di alimentazione (benzina, diesel, kerosene). 
//I metodi per questa classe sono: l’accensione e lo spegnimento e la possibilità di accelerare e frenare.
class VeicoloMotore : protected MezziTrasp{
    protected:
        int consumo;
        string alimentazione;
        string stato;
    public:
        VeicoloMotore(int velMax, int trazione, int nPersone, int consumo, int alimentazione){
            string trz[3] = {"animale", "muscolare", "motore"};
            string alm [3] = {"benzina", "diesel", "kerosene"};  
            this->consumo = consumo;
            this->alimentazione = alm[alimentazione];
            this->velMax = velMax;
            this->trazione = trz[trazione];
            this->nPersone = nPersone;
            stato="spento";
        }
        void accendi(){
            cout << "Accensione veicolo" << endl;
            stato="acceso";
        }
        void spegni(){
            cout << "Spegnimento veicolo" << endl;
            stato="spento";
        }
};
//Infine, aggiungere la classe Autobus con gli attributi costo del biglietto e numero di posti sia in piedi che a sedere. 
//I metodi sono: aprire e chiudere le porte e il metodo per prenotare la fermata. 
class Autobus : protected MezziTrasp{
    protected:
        int costoBiglietto;
        int nPostiPiedi;
        int nPostiSedere;
        string stato;
    public:
        Autobus(int velMax, int trazione, int nPersone, int costoBiglietto, int nPostiPiedi, int nPostiSedere){
            string trz[3] = {"animale", "muscolare", "motore"};
            string alm [3] = {"benzina", "diesel", "kerosene"};  
            this->velMax = velMax;
            this->trazione = trz[trazione];
            this->nPersone = nPersone;
            this->costoBiglietto = costoBiglietto;
            this->nPostiPiedi = nPostiPiedi;
            this->nPostiSedere = nPostiSedere;
            stato="chiuso";
        }
        void apri(){
            cout << "Apertura porte" << endl;
            stato="aperto";
        }
        void chiudi(){
            cout << "Chiusura porte" << endl;
            stato="chiuso";
        }
        void prenotaFermata(){
            cout << "Prenotazione fermata" << endl;
        }
};
//Creare un main opportuno per testare le classi.
//Nel main testare la definizione di un array statico di oggetti.
int main(){
    MezziTrasp *a = new MezziTrasp[2];
    a[0] = MezziTrasp(200, 2, 3);
    a[1] = MezziTrasp(100, 1, 2);
    return 0;
}