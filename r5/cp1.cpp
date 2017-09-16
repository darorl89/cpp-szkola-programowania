#include <iostream>

using namespace std;

int main()
{
    int start,stop,result;
    result=start=stop=0;
    cout<<"Podaj poczatek: ";
    cin>>start;
    cout<<"Podaj koniec: ";
    cin>>stop;
    for(int i = start; i<=stop; ++i )
    {
        result+=i;
    }
    cout<<"Suma liczb miedzy "<<start<<" a "<<stop<<" wynosi "<<result;
    return 0;
}
