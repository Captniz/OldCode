#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
const int DIM = 24;

class Mac{
    public:
    int x;  
    int y;
    int bat;

    Mac(int b){
        x=(DIM/2);
        y=(DIM/2);
        bat=b;
    }
   Mac(){
        x=(DIM/2);
        y=(DIM/2);
        bat=100;
    }
    
    void Draw( char road [DIM][DIM]){
        road[y][x]=216;

        for (int i = 0; i < 30; i++){cout<<endl;}
        for (int i = 0; i < DIM; i++){
            for (int j = 0; j < DIM; j++){
                cout<<road[i][j];
                road[i][j]=176;
            }
            cout<<endl;
        }

        cout<<"X: "<<x<<" Y: "<<y<<endl;
        cout<<"Batteria: "<<bat<<'%'<<endl;
    }

    void Move(char c){
        if(bat==0){
            cout<<"Batteria scarica"<<endl;
            exit(0);
        }
        switch (c){
        case 'w':
            y--;
            if(y<0){
                cout<<"Ti sei schiantato :C"<<endl;
                exit(0);
            }
            bat--;
            break;
        case 'a':
            x--;
            if(x<0){
                cout<<"Ti sei schiantato :C"<<endl;
                exit(0);
            }
            bat--;
            break;
        case 's':
            y++;
            if(y>DIM){
                cout<<"Ti sei schiantato :C"<<endl;
                exit(0);
            }
            bat--;
            break;
        case 'd':
            x++;
            if(x>DIM){
                cout<<"Ti sei schiantato :C"<<endl;
                exit(0);
            }
            bat--;
            break;
        default:
            break;
        }
    }
};
class Pol: public Mac{
    public: 
    bool sirena;

    Pol(int b){
        x=(DIM/2);
        y=(DIM/2);
        bat=b;
        sirena=false;
    }
    void Draw( char road [DIM][DIM]){
        if(sirena && (x+y)%2){
            road[y][x]=177;
        }else{
            road[y][x]=178;
        }

        for (int i = 0; i < 30; i++){cout<<endl;}
        for (int i = 0; i < DIM; i++){
            for (int j = 0; j < DIM; j++){
                cout<<road[i][j];
                road[i][j]=176;
            }
            cout<<endl;
        }

        cout<<"X: "<<x<<" Y: "<<y<<endl;
        cout<<"Batteria: "<<bat<<'%'<<endl;
        cout<<"Sirena: "<<sirena<<endl;
    }
    void Move(char c){
        if(bat<=0){
            cout<<"Batteria scarica"<<endl;
            exit(0);
        }
        switch (c){
        case 'w':
            y--;
            if(y<0){
                cout<<"Ti sei schiantato :C"<<endl;
                exit(0);
            }
            break;
        case 'a':
            x--;
            if(x<0){
                cout<<"Ti sei schiantato :C"<<endl;
                exit(0);
            }
            break;
        case 's':
            y++;
            if(y>DIM){
                cout<<"Ti sei schiantato :C"<<endl;
                exit(0);
            }
            break;
        case 'd':
            x++;
            if(x>DIM){
                cout<<"Ti sei schiantato :C"<<endl;
                exit(0);
            }
            break;
        case 'x':
            sirena=!sirena;
            break;
        default:
            break;
        }
        bat--;
        if (sirena){
            bat--;
        }
    }
};

int main(){
    char m [DIM][DIM];
    char c;
    Pol mac = Pol(20);

    for (int i = 0; i < DIM; i++){
        for (int j = 0; j < DIM; j++){
            m[i][j]=176;
        }
    }
    mac.Draw(m);
    while (1){
        c = _getch();
        mac.Move(c);
        mac.Draw(m);
    }
    return 0;
}
