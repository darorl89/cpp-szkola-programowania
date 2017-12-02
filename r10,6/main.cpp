#include <iostream>
#include "Move.h"

using namespace std;

int main()
{
    Move one(3,32);
    Move two(1,10);
    Move three;
    three = one.add(two);
    three.showmove();
    return 0;
}
