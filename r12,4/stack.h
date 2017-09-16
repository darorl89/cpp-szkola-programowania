// stack.h -- definicja klasy stosu (wg ADT)
#ifndef STACK_H_
#define STACK_H_
#include <iostream>

typedef unsigned long Item;

class Stack
{
    private:
        enum { MAX = 10};    // stała zasięgu klasy
        Item * pitems;     // przechowuje elementy stosu
        int size;
        int top;             // indeks szczytowego elementu stosu
    public:
        Stack(int n = MAX);
        Stack(const Stack & s);
        ~Stack();
        bool isempty() const;
        bool isfull() const;
        // push() zwraca false, jeśli stos jest już pełen (true w pozostałych przypadkach)
        bool push(const Item & item);    // odkłada element na stos
        // pop() zwraca false, jeśli stos jest już pusty (true w pozostałych przypadkach)
        bool pop(Item & item);           // zdejmuje element ze stosu
        Stack & operator=(const Stack & st);
        friend std::ostream & operator<<(std::ostream & os, const Stack & st);
        int showSize() const;

};
#endif

