#include <iostream>
#include "sales.h"

double benefits[Sales::QUARTERS] = {4,2,8,6};

int main()
{
    Sales::Sales sale;
    Sales::setSales(sale,benefits,Sales::QUARTERS);
    Sales::showSales(sale);
    return 0;
}
