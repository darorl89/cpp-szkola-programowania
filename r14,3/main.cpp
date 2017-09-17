#include "QueueTP.h"
#include <cstring>
#include "worker.h"

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;


    cout << "Podaj maksymalna dlugosc kolejki: ";
    int qs;
    char ch;
    cin >> qs;
    QueueTP<Worker *> line(qs);
    Worker * pt = nullptr;

    cout << "Nacisnij D, aby wprowadzic strukture, \n"
        << "P, aby przetworzyc strukture, lub K, aby zakonczyc.\n";
    cin.get();
    while (cin >> ch && toupper(ch) != 'K')
    {

        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch (ch)
        {
        case 'D':
        case 'd':
            if (line.isfull())
                cout << "Kolejka pelna!\n";
            else
            {
                char choice;
                cout << "Podaj kategorie pracownika:\n"
                    << "k: kelner  p: piosenkarz  "
                    << "s: spiewajacy kelner  w: wyjscie\n";
                cin >> choice;
                while (strchr("kpsw", choice) == NULL)
                {
                    cout << "Wpisz k, p, s lub w: ";
                    cin >> choice;
                }
                if (choice == 'w')
                    break;
                switch (choice)
                {
                case 'k': pt = new Waiter;
                    break;
                case 'p': pt = new Singer;
                    break;
                case 's': pt = new SingingWaiter;
                    break;
                }
                cin.get();
                pt->Set();
                line.enqueue(pt);
            }
            break;

        case 'P':
        case 'p':
            if (line.isempty())
                cout << "Kolejka pusta\n";
            else
            {
                cout << "Obiekt sciagniety z poczatku kolejki:\n";
                line.dequeue(pt);
                pt->Show();
                delete pt;
            }
            break;

        default:
            cout << "Wybrales zla opcje!\n";
            break;
        }
        cout << "\nNacisnij D, aby wprowadzic strukture, \n"
            << "P, aby przetworzyc strukture, lub K, aby zakonczyc.\n";

    }
    delete pt;

    return 0;
}
