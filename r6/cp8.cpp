// sumafile.cpp -- funkcje maj¹ce tablicê za parametr
#include <iostream>
#include <fstream>          // wejœcie-wyjœcie przez pliki
#include <cstdlib>          // funkcja exit()
const int SIZE = 60;
int main()
{
    using namespace std;
    char filename[SIZE];
    ifstream inFile;        // obiekt obs³uguj¹cy odczyt z pliku

    cout << "Podaj nazwê pliku z danymi: ";
    cin.getline(filename, SIZE);
    inFile.open(filename);  // po³¹czenie inFile z plikiem
    if (!inFile.is_open())  // nieudana próba otwarcia pliku
    {
        cout << "Otwarcie pliku " << filename << " nie powiod³o siê.\n";
        cout << "Program zostanie zakoñczony.\n";
        exit(EXIT_FAILURE);
    }
    double value;
    double sum = 0.0;
    int count = 0;          // liczba elementów do odczytu

    inFile >> value;        // pobierz pierwsz¹ wartoœæ
    while (inFile.good())   // póki dobre dane i nie EOF
    {
        ++count;            // wczytano kolejn¹ dan¹
        sum += value;       // obliczenie bie¿¹cej sumy
        inFile >> value;    // pobranie nastêpnej wartoœci
    }
    if (inFile.eof())
        cout << "Koniec pliku.\n";
    else if (inFile.fail())
        cout << "Wczytywanie danych przerwane - b³¹d.\n";
    else
        cout << "Wczytywanie danych przerwane, przyczyna nieznana.\n";
    if (count == 0)
        cout << "Nie przetworzono ¿adnych danych.\n";
    else
    {
        cout << "Wczytanych elementów: " << count << endl;
        cout << "Suma: " << sum << endl;
        cout << "Œrednia: " << sum / count << endl;
    }
    inFile.close();         // plik ju¿ niepotrzebny
    return 0;
}
