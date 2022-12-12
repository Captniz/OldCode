#include <iostream>
using namespace std;

class Test {
    public:
        int num;
        Test() {
            num = 0;
        }
        // prefix increment
        Test operator++()
        {
            ++num;
            // returned value should be a reference to *this
            return *this;
        }
        // postfix increment
        Test operator++(int) {
            // returned value should be a copy of the object before increment
            Test temp = *this;
            ++num;
            return temp;
        }
        //overload prefix decrement
        Test operator--(){
            --num;
            return *this;
        }
        //overload postfix decrement
        Test operator--(int) {
            Test temp = *this;
            --num;
            return temp;
        }
        //overload = operator
        Test operator=(const int& n) {
            num = n;
            return *this;
        }
        //overload + operator
        Test operator+(const Test& t) {
            Test temp;
            temp.num = num + t.num;
            return temp;
        }
        //overload - operator
        Test operator-(const Test& t) {
            Test temp;
            temp.num = num - t.num;
            return temp;
        }
        //overload * operator
        Test operator*(const Test& t) {
            Test temp;
            temp.num = num * t.num;
            return temp;
        }
        //overload / operator
        Test operator/(const Test& t) {
            Test temp;
            temp.num = num / t.num;
            return temp;
        }
        //overload output stream
        friend ostream& operator<<(ostream& os, const Test& dt);
        //overload input stream
        friend istream& operator>>(istream& is, Test& dt);
};
// overload output stream
ostream& operator<<(ostream& os, const Test& dt){
    os << dt.num << endl;
    return os;
}

// overload input stream
istream& operator>>(istream& is, Test& dt){
    is >> dt.num;
    return is;
}

int main() {
    Test t1,t2,t3,t4;
    cin>>t1;
    t2.num=20;
    cout<<t1+t2;
    return 0;
}