#include<iostream>
using namespace std;

class Ctr{
    private:
        int ctr;
    public:
        int test;
        Ctr(){
            ctr=0;
            test=0;
        };
        Ctr(int n){
            ctr=n;
            test=n;
        };
        void inc(){
            ctr++;
            test++;
        };
        void dec(){
            ctr--;
            test--;
        };
        int getCount(){
            return ctr;
        };
        char *toString(){
            //using malloc convert ctr to an array of char
            int div,size; 
            div=10;
            size=1;

            while(ctr/div!=0){
                div*=10;
                size++;
            }

            char *str = new char [size];
/*          char *str;
            str=(char*)malloc(size*sizeof(char));
*/
            sprintf(str,"%d",ctr);
            return str;
        };

};

int main(){
    int a;
    Ctr ctr = Ctr(10);
/*  cin>>a;
    cin.ignore();    
    cout<<a<<endl; */
    for (int i = 0; i < 100; i++){
        ctr.inc();
    }
    cout<<ctr.toString()<<endl;
    return 0;
}
