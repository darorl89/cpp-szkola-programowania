#include <iostream>

using namespace std;

long double probability(int number, int picks, int magic);

int main()
{
    cout << "Szansa wygranej dla 5 liczb od 1 do 50 i magicznej 1 do 6 wynosi: " << probability(50,6,27);
    return 0;
}

long double probability(int number, int picks,int magic = 1){
    long double result = 1;
    for(int i = picks; picks > 0; --picks, --number ){
        result = result * number / picks;
    }

    return result * magic;
}
