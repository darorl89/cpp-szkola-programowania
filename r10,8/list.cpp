#include "list.h"

List::List()
: index(0)
{
}

bool List::isEmpty() const
{
    if (index == 0)
        return true;
    else
        return false;
}

bool List::isFull() const
{
    if (index == LISTMAX)
        return true;
    else
        return false;
}
void List::add(const double & input)
{
    if (!isFull())
    {
        elements[index] = input;
        ++index;
    }
}

void List::visit(void (* pf)(double &))
{
    for(int i = 0; i < index; ++i)
    {
        (*pf)(elements[i]);
    }
}

void List::printList() const
{
    cout << "Lista: " << endl;
    for (int i = 0; i < index; i += 2)
    {
        cout << i+1 << ". " << elements[i] << "\t\t" << i+2 << ". " << elements[i+1] << endl;
    }
}
