#include <iostream>

using namespace std;

int main()
{
    string name,dessert;
    const int SrSize=20;
    cout<<"Podaj swoje imie:\n";
    cin>>name;
    cout<<"Podaj swoj ulubiony deser:\n";
    cin>>dessert;
    dessert[dessert.length()-1]='e';
    cout<<"Mam dla ciebie "<<dessert;
    cout<<", "<<name<<".\n";
    return 0;
}

