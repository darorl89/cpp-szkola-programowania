#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;

const int NAMEMAX = 35;
struct customer
{
    char fullname[NAMEMAX];
    double payment;
};

class Stack
{
    static const int MAX = 10;
    customer customers[MAX];
    int customersLeft;
public:
    Stack() {customersLeft = 0;}
    void addCustomer(const char * fname, double pay);
    int delCustomer();
    void show();
};


#endif // STACK_H_INCLUDED
