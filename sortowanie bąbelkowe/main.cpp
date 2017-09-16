#include <iostream>

using namespace std;

int main()
{
    int tablica[7] = {2,5,2,3,4,10,23};
    for(int i = 0 ; i < 7 ; i++)
    {
        if(tablica[i]>tablica[i+1])
        {
            int temp = tablica[i];
            tablica[i] = tablica[i+1];
            tablica[i+1] = temp;
            i = 0;
        }
    }
    for(int i = 0 ; i < 7 ; i++) cout << tablica[i] << endl;

}
