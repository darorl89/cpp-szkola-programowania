#include <iostream>

using namespace std;

char * makestr(char,int);

int main()
{
    char sign;
    int times;
    cout << "Podaj litere: ";
    cin >> sign;
    cout << "Podaj liczbe powtorzen: ";
    cin >> times;
    cout << "Oto twoj ciag znakow " << sign << " w liczbie sztuk : " << times << endl;
    cout <<  makestr(sign,times);
    return 0;
}

char * makestr(char sign, int times){
    char * pstr = new char [times+1];
    int n = times;
    while(n-->0){
        pstr[n] = sign;
    }
    return pstr;
}
