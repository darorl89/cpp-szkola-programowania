#include "stack.h"

int main()
{
    Stack st;
    bool loop = true;
    do
    {
        char client[NAMEMAX];
        double pay;
        int choice;
        cout << "Dodaj (1) lub usun (2) klienta (3 aby wyjsc): ";
        while(!(cin >> choice) || choice < 1 || choice > 3)
            cout << "Podaj prawidlowa wartosc (1,2,3): ";
        cin.ignore();
        switch(choice)
        {
        case 1:
            cout << "Podaj imie i nazwisko klienta: ";
            while(!(cin.getline(client,NAMEMAX)))
                cout << "To pole nie moze byc puste: ";
            cout << "Podaj kwote: ";
            cin >> pay;
            while(pay < 0)
            {
                cout << "Podaj kwote wieksza od 0: ";
                cin.clear();
                cin.ignore();
                cin >> pay;
            }
            st.addCustomer(client,pay);
        break;
        case 2:
            if(st.delCustomer() < 0)
            {
                cout << "Brak klientow" << endl;
            }
        break;
        case 3:
            loop = false;
        break;
        }
        st.show();
    } while(loop);
    return 0;
}
