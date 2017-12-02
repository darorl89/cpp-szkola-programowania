#include <iostream>
#include "golf.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
    Golf g("Pawel",23);
    Golf copyg("kaw",21);
    copyg = g;
    copyg.showgolf();
    return 0;
}
