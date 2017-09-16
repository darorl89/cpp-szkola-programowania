// arrfun3.cpp -- funkcje obs³uguj¹ce tablica i const
#include <iostream>
const int Max = 5;

// prototypy funkcji
int fill_array(double * begining, double * ending );
void show_array(const double * begining, const double * ending );  // nie zmienia danych
void revalue(double r, double * begining, double * ending );

int main()
{
    using namespace std;
    double properties[Max];

    int size = fill_array(properties, properties + Max);
    show_array(properties, properties + size);
    if (size > 0)
    {
        cout << "Podaj czynnik zmiany wartoœci: ";
        double factor;
        while (!(cin >> factor)) // nieliczbowa wartoœæ na wejœciu
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Niepoprawna wartoœæ; podaj liczbê: ";
        }
        revalue(factor, properties,properties + size);
        show_array(properties, properties + size);
    }
    cout << "Gotowe.\n";
    cin.get();
    cin.get();
    return 0;
}

int fill_array(double * begining, double * ending )
{
    using namespace std;
    double temp;
    int i = 0;
    double * pt;
    for (pt = begining; pt != ending; ++pt)
    {
        cout << "Podaj wartoœæ nr " << (i + 1) << ": ";
        cin >> temp;
        if (!cin)    // b³êdne dane
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
           cout << "B³êdne dane, wprowadzanie danych przerwane.\n";
           break;
        }
        else if (temp < 0)     // nakaz zakoñczenia
            break;
        *pt = temp;
        ++i;
    }
    return i;
}

// poni¿sza funkcja mo¿e u¿yæ tablicy, której adres przekazano
// w ar, ale nie mo¿e jej modyfikowaæ
void show_array(const double * begining, const double * ending )
{
   using namespace std;
   const double * pt;
   int i = 0;
   for (pt = begining; pt != ending; ++pt)
    {
        cout << "Nieruchomoœæ nr " << (i + 1) << ": ";
        cout << *pt << endl;
        ++i;
    }
}

// mno¿y ka¿dy element ar[] przez r
void revalue(double r, double * begining,double * ending )
{
    double * pt;
    for (pt = begining; pt != ending; ++pt)
        *pt *= r;
}
