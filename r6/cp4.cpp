
#include <iostream>

using namespace std;

void menu (void) {
    cout << "Zakon Programistow Dobrej Woli ZPDW" << endl;
    cout << "a. Lista wg imion \t\t" << "b. Lista wg stanowisk" << endl;
    cout << "c. Lista wg pseudonimow \t" << "d. Lista wg preferencji" << endl;
    cout << "q. Koniec" << endl;
}

struct zpdw {
    char imie[30];
    char stanowisko[30];
    char pseudonim[30];
    int preferencje;
};

int main() {
    zpdw p1[4] = {
        {"Slawek", "Prezes", "Slawcio", 1},
        {"Heniek", "V-Prezes", "Henio", 2},
        {"Maciek", "WEB-DEV", "Gumis", 2},
        {"Zdzislaw", "***", "Landryn", 0}
    };
    menu();
    char odp;
    while (odp != 'q') {
        cout << "Wybierz odpowiedz: ";
        cin >> odp;
        switch (odp) {
        case 'a': for (int i = 0; i < 4; i++) cout << p1[i].imie << endl; break;
        case 'b': for (int i = 0; i < 4; i++) cout << p1[i].stanowisko << endl; break;
        case 'c': for (int i = 0; i < 4; i++) cout << p1[i].pseudonim << endl; break;
        case 'd': for (int i = 0; i < 4; i++) cout << p1[i].preferencje << endl; break;
        case 'q': cout << "Zegnamy"; break;
        }
    }
    return 0;
}

