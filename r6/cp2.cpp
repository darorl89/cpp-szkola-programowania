#include <iostream>
#include <cctype>
#include <array>

using namespace std;
int main()
{
    cout.precision(2);
    array<double,10>donates;
    cout<<"Podaj wartosc: ";
    double sum{0};
    for (int i = 0; i<donates.size() && cin>>donates[i]; i++){
        cout<<"Podaj wartosc: ";
        sum+=donates[i];
    }
    cout<<"Srednia wynosi: "<<sum/donates.size()<<endl;
    cout<<"Wartosci wieksze: ";
    for(int i = 0; i < donates.size(); i++){
        if(donates[i]>sum/donates.size())
            cout<<donates[i]<<", ";
    }
    return 0;
}
