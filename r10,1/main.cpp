#include <iostream>
#include "BankBill.h"

using std::cout;
using std::endl;

int main()
{
    BankBill bill1("Kawula", "e23", 20);
    bill1.showBill();
    bill1.subBalance(20);
    bill1.showBill();
    bill1.addBalance(30);
    bill1.showBill();
    std::cout << "Hello world!" << std::endl;
    return 0;
}
