#include <iostream>

using namespace std;

int fill_array(double [], int);
void show_array(const double [], int);
void reverse_array(double [], int);

const int mySize = 4;

int main()
{
    double myArray[3]{0};
    fill_array(myArray,mySize);
    show_array(myArray,mySize);
    reverse_array(myArray,mySize);
    show_array(myArray,mySize);
    return 0;
}

int fill_array(double ar[], int tableSize){
    int values = 0;
    cout << "Podaj wartosci: " << endl;
    while(values < tableSize && cin >> ar[values])
        ++values;
    return values;
}
void show_array(const double ar[], int tableSize){
    for (int i = 0; i < tableSize; ++i)
        cout << "Wartosc " << i << ": " << ar[i] << endl;
}
void reverse_array(double ar[], int tableSize){
    double temp;
    for(int i = 0; i < tableSize / 2; ++i){
        temp = ar[i];
        ar[i] = ar[tableSize-1-i];
        ar[tableSize-1-i] = temp;
    }
}
