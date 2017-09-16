#include <iostream>
#include <cctype>

using namespace std;
int main()
{
char ch;
std::cout << " Podaj tekst. Znak @ konczy wpisywanie. \n";
while(std::cin.get(ch) && ch!='@')
    {
        if(isdigit(ch))
        continue;
        else if (islower(ch))
            ch = (toupper(ch));
        else if (isupper(ch))
            ch = (tolower(ch));
        std::cout << ch;
    }
    return 0;
}
