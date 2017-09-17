#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "person.h"



int main()
{
    srand( time( NULL ) );
    using std::cout;
    using std::cin;
    using std::endl;
    using std::strchr;
    const int PERSONS = 1;

    Person * lolas[PERSONS];

    cout << "Podaj " << PERSONS << " czlonkow mafii: " << endl;

    for (int i = 0; i < PERSONS; ++i)
    {
        char choice;
        cout << "Podaj typ mafioza:\nr: rewolwerowiec p: pokerzysta b: badguy  w: wyjscie: " << endl;
        cin >> choice;
        while(strchr("rpbw",choice) == NULL)
        {
            cout << "Podaj typ mafioza:\nr: rewolwerowiec p: pokerzysta b: badguy  w: wyjscie: " << endl;
            cin >> choice;
        }
        if (choice == 'w')
            break;
        switch(choice)
        {
        case 'p':
        case 'P': lolas[i] = new PokerPlayer;
            break;
        case 'r':
        case 'R': lolas[i] = new Gunslinger;
            break;
        case 'b':
        case 'B': lolas[i] = new BadGuy;
            break;
        }
        cin.get();
        lolas[i]->set();
    }

    cout << "Lista: ";

    for (int i = 0; i < PERSONS; ++i)
    {
        cout << endl;
        lolas[i]->show();
    }
    cout << endl;
    for (int i = 0; i < PERSONS; ++i)
        delete lolas[i];
    cout << "Koniec\n";
    return 0;
}
