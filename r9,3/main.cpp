#include <iostream>
#include <cstring>
#include <new>
#include <ostream>
#include "chaff.h"

int main()
{
    char buffer[200];
    chaff *pch1 = new (buffer) chaff[2];
    chaff *pch2 = new chaff[2];
    for (int i = 0; i < 2; ++i)
    {
        pch1[i].dross = "Buffor";
        pch1[i].slag = 1;
        pch2[i].dross = "NewDynamic";
        pch2[i].slag = 2;
    }
    std::cout << "Adres zmiennej buffer:" << &buffer << std::endl;
    for (int i = 0; i < 2; ++i)
    {
        std::cout << "Adres struktury w buffer (" << i+1 << "): " << &pch1 << ", adres chaff: " << &(pch1[i].dross) << ", adres slag: " << &pch1[i].slag << std::endl;
        std::cout << "Adres struktury poza buffer(" << i+1 << "): "  << &pch2 << ", adres chaff: " << &(pch1[i].dross) << ", adres slag: " << &pch2[i].slag << std::endl;
    }
    return 0;
}
