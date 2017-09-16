#include <iostream>
#include "Move.h"

using namespace std;

int main()
{
    Move one;
    Move two(1,10);
    Move three;
    three = one.add(two);
    three.showmove();
    return 0;
}
