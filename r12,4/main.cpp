#include "stack.h"

using namespace std;

int main()
{
    int size;
    cout << "wielkosc stosu" << endl;
    cin >> size;
    Stack example(size);
    cout << "Dodaj do stosu: ";
    unsigned long add;
    unsigned long * ptrash = new unsigned long [example.showSize()];
    int trash_count = 0;
    for (int i = 0; i < example.showSize() && cout << "Dodaj do stosu: " && cin >> add; ++i)
    {
        example.push(add);
    }
    cin.clear();
    cout << example;
    cout << "Zdjac ze stosu? (wpisz cokolwiek): ";
    string pop;
    getline(std::cin,pop);
    for (int i = example.showSize(); i >= 0 && !pop.empty(); ++i)
    {
        example.pop(ptrash[i]);
        cout << "Zdjac ze stosu? (wpisz cokolwiek): ";
    }

    delete [] ptrash;
    return 0;
}
