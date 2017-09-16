#include <iostream>
#include <cstring>

int main()
{
    using namespace std;
    string input = "";
    cout << "WprowadŸ wiersz:\n";
    while (getline(cin,input) && !input.empty())
    {
        cout << "Wprowadz nastepny wiersz (wiersz pusty konczy wprowadzanie):\n";
    }
    cout << "Koniec\n";
    return 0;
}
