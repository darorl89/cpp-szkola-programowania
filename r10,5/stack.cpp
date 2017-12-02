#include "stack.h"

void Stack::addCustomer(const char* fname, double pay)
{
    strncpy(customers[customersLeft].fullname,fname,NAMEMAX);
    customers[customersLeft].payment = pay;
    ++customersLeft;
}
int Stack::delCustomer()
{
    if(--customersLeft < 0)
        customersLeft = 0;
    strncpy(customers[customersLeft+1].fullname,"DELETED",NAMEMAX);
    return customersLeft;
}
void Stack::show()
{
    cout << "Kolejka: " << endl;
    for(int i = customersLeft - 1; i >= 0; --i)
    {
        cout << customersLeft - i << ". " << customers[i].fullname << ", kwota: " << customers[i].payment << endl;
    }
    if(customersLeft > 0)
        cout << "Pozostalo: " << customersLeft << endl;
    else
        cout << "Kolejka pusta!" << endl;
}
