#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));
    int number;
    for (int i = 0; i < 10; ++i)
    {
        number = (std::rand());
            std::cout << number << std::endl;
    }
    return 0;
}
