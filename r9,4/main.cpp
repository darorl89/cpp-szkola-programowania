#include <iostream>
#include "sales.h"

double benefits[Sales::QUARTERS] = {4,2,8};

int main()
{
    Sales::Sales sale;
    Sales::setSales(sale,benefits,Sales::QUARTERS);
    Sales::showSales(sale);
    Sales::setSales(sale);
    Sales::showSales(sale);
    return 0;
}
