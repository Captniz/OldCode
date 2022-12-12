#include<string>
#include<iostream>
using namespace std;

int main(){
    //convert a int to string
    int n = 1;
    string s = "a";

    char s1[100];
    sprintf(s1,"%d",n);
    string s2 = string(s1);
    s = s + s2;
    cout << s <<'~'<<s1[0]<< endl;
    return 0;
}