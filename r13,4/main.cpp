#include <iostream>
#include "wine.h"

using namespace std;

int main()
{
    Port v1("XD","Biale",10);
    VintagePort vp1("DrinkGutINC", 20, "Zacne", 1950);
    Port v2("XDx2", "Czerwone", 20);
    VintagePort vp2("DrinkBetterINC", 30, "Zacniejsze", 1939);
    v1 = vp1;
    v1 = vp1;

    v1 += 20;
    v1 -= 20;
    vp1 = vp2;
    cout << v1;
    vp1.Show();
    vp1 += 20;
    cout << vp1;
    vp1 = vp1;
    return 0;
}
