// stack.cpp -- metody klasy stosu
#include "stack.h"
#include <iostream>
Stack::Stack(int n)            // tworzy pusty stos
{
    size = n;
    top = 0;
    pitems = new Item[n];
}

Stack::Stack(const Stack & s)
{
    pitems = new Item [size];
    size = s.size;
    for (int i = 0; i < sizeof(s.pitems) / sizeof(Item); ++i)
        pitems[i] = s.pitems[i];
    top = s.top + 1;
}

Stack::~Stack()
{
    delete [] pitems;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item & item)
{
    if (top < size)
    {
        ++top;
        pitems[top] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = pitems[top];
        --top;
        return true;
    }
    else
    {
        delete [] pitems;
        return false;
    }
}

Stack & Stack::operator=(const Stack & s)
{
    if(this == &s)
        return *this;
    top = s.top;
    size = s.size;
    for (int i = 0; i < top; ++i)
    {
        pitems[i] = s.pitems[i];
    }
    return *this;
}

std::ostream & operator<<(std::ostream & os, const Stack & s)
{
    os << "Zawartosc kolejki (w kolejnosci zwalniania ze stosu): " << std::endl;
    for (int i = s.top; i > 0; --i)
    {
        os << s.pitems[i] << std::endl;
    }
    os << "Wolnych miejsc: ";
    if (s.size == s.top)
        os << "brak " << std::endl;
    else
        os << s.size - s.top << std::endl;

}

int Stack::showSize() const
{
    return size;
}
