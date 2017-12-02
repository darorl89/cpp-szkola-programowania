// static.cpp -- stosowanie lokalnej zmiennej statycznej
#include <iostream>
// stale:
const int ArSize = 10;

// prototyp funkcji:
void strcount(std::string str);

int main()
{
    using namespace std;
    string input;
    char next;

    cout << "Wprowadz wiersz:\n";
    getline(cin,input);
    while (!input.empty())
    {
        strcount(input);
        cout << "Wprowadz nastepny wiersz (wiersz pusty konczy wprowadzanie):\n";
        getline(cin,input);
    }
    cout << "Koniec\n";
    return 0;
}

void strcount(std::string str)
{
    using namespace std;
    static int total = 0;          // statyczna zmienna lokalna

    cout << "\"" << str << "\" zawiera ";
    total += str.size();
    cout << str.size() << " znakow\n";
    cout << "lacznie "<< total << " znakow\n";
}
