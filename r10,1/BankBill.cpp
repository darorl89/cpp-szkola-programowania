#include "BankBill.h"

BankBill::BankBill(string s, string bID, double b)
{
    name = s;
    billID = bID;
    balance = b;
}

void BankBill::showBill() const
{
    std::cout << "Nazwisko posiadacza: " << name << ", Id rachunku: " << billID << ", saldo " << balance << std::endl;
}

void BankBill::addBalance(double ab)
{
    if(ab < 0)
    {
        std::cout << "Nie mozesz dodac ujemna wartosc" << std::endl;
        std::cout << "Operacja przerwana" << std::endl;
    }
    else
        balance -= ab;
}

void BankBill::subBalance(double ab)
{
    if(ab < 0)
    {
        std::cout << "Nie mozesz odjac ujemna wartosc" << std::endl;
        std::cout << "Operacja przerwana" << std::endl;
    }
    else
        balance -= ab;
}
