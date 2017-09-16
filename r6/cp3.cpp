#include <iostream>
#include <cctype>
#include <array>

using namespace std;
int main()
{
    char ch;
    cout << "r)roslinozerca     p)pianista"<<endl;
    cout << "d)drzewo           g)gra"<<endl;
    cout << "Prosze podac litere r, p, t lub g: ";
    while(!(cin>>ch && (ch=='r' || ch=='p' || ch=='d' || ch=='g'))){
        cout << "Prosze podac litere r, p, t lub g: ";
    }
    cout << "Klon jest: ";
    switch(ch){
    case 'r':
        cout << "roslinozerca";
        break;
    case 'p':
        cout << "pianista";
        break;
    case 'd':
        cout << "drzewem";
        break;
    case 'g':
        cout << "gra";
        break;
    }
    return 0;
}
