#include <iostream>
#include "wine.h"

using namespace std;

int main()
{
    Pair<string,int> p1("a",2);
    Pair<string,int> ratings[4] = {Pair<string,int>("Pod czerwonym baronem",2),Pair<string,int>("U jozka",5),Pair<string,int>("U stasia",1),Pair<string,int>("U pawla",10)};
    cout << "Oto restauracje: " << endl;
    for (int i = 0; i < 4; ++i)
    {
        cout << ratings[i].first() << "; " << ratings[i].second() << endl;
    }

    cout << "Uwaga, zmiana oceny: ";
    ratings[3].second() = 11;
    cout << ratings[3].first() << "; " << ratings[3].second() << endl;
    return 0;
}
