#include <iostream>
#include "person.h"

using std::cout;
using std::endl;

int main()
{
    Person one;
    Person two("Staszek");
    Person three("Jacek", "Placek");
    three.show();
    cout << endl;
    one.formalShow();
    return 0;
}
