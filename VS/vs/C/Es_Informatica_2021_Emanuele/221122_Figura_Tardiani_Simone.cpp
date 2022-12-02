#include<iostream>

using namespace std;

class Figura{
    protected:
        float area;
        float perimetro;
    public:
        Figura(){
            area=0;
            perimetro=0;
        }
        void stampaArea(){
            cout<<area;
        }
        void stampaPerimetro(){
            cout<<perimetro;
        }
        void stampa(){
            cout<<"Sono una figura";
        }

};
class Quadrato:public Figura{
    private:
        float lato;
    public:
        Quadrato(float lato){
            area=0;
            perimetro=0;
            this->lato=lato;
        }
        float calcolaArea(){
            area=lato*lato;
        }
        float calcolaPerimetro(){
            perimetro=lato*4;
        }
        void stampa(){
            cout<<"Sono un quadrato";
        }

};
class Rombo:public Figura{
    private:
        float base;
        float altezza;
        float lato;
    public:
        Rombo(float lato,float base, float altezza){
            this->altezza=altezza;
            this->base=base;
            this->lato=lato;
            area=0;
            perimetro=0;
        }
        float calcolaArea(){
            area=(base*altezza)/2;
        }
        float calcolaPerimetro(){
            perimetro=lato*4;
        }
        void stampa(){
            cout<<"Sono un rombo";
        }
};
class Cerchio:public Figura{
    private:
        float raggio;
    public:
        Cerchio(float raggio){
            this->raggio=raggio;
            area=0;
            perimetro=0;
        }
        float calcolaArea(){
            area=((raggio*raggio)*3.14);
        }
        float calcolaPerimetro(){
            perimetro=(2*3.14*raggio);
        }
        void stampa(){
            cout<<"Sono un cerchio";
        }
};
int main(){
    Cerchio c = Cerchio(2);
    return 0;
}