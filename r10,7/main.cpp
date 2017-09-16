#include <iostream>
#include "plorg.h"

using namespace std;

int main()
{
    Plorg one;
    Plorg two("Zlamas", 70);
    two.showPlorg();
    two.setFulness(10);
    two.showPlorg();
    return 0;
}
