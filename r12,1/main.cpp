#include <iostream>
#include <cow.h>

using namespace std;

int main()
{
    Cow one;
    Cow two("Mucka", "Pilka", 500);
    two.ShowCow();
    one = two;
    one.ShowCow();
    return 0;
}
