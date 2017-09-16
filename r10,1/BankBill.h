#ifndef BANKBILL_H_INCLUDED
#define BANKBILL_H_INCLUDED
#include <iostream>
using std::string;
class BankBill
{
    string name;
    string billID;
    double balance;
public:
    BankBill(string s, string bID, double b);
    void showBill() const;
    void addBalance(double ab);
    void subBalance(double ab);
};


#endif // BANKBILL_H_INCLUDED
