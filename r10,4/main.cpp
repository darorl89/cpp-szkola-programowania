#include <iostream>
#include "sales.h"
using namespace std;

int main()
{
    double bal[Sales::QUARTERS] {2, 5, 4, 5};
    Sales s1(bal, 4);
    s1.showSales();
    return 0;
}
