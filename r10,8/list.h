#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
class List
{
    static const int LISTMAX = 10;
    double elements[10];
    int index;
public:
    List();
    bool isEmpty() const;
    bool isFull() const;
    void add(const double &);
    void visit(void (*pf)(double &));
    int numberOfItems() const { return index;}
    void printList() const;
};
#endif // LIST_H_INCLUDED
