#include <iostream>
#include "emp.h"

#include <iostream>

int main()
{
    Employee em("Tadeusz", "Hubert", "Sprzedawca");
    std::cout << em << std::endl;
    em.showAll();

    Manager ma("Morfiusz", "Smoczewski", "Malarz", 5);
    std::cout << ma << std::endl;
    ma.showAll();

    Fink fi("Maurycy", "Olkuski", "Hydraulik", "Julian Bar");
    std::cout << fi << std::endl;
    fi.showAll();
    Highfink hf(ma, "Jan Kudlaty");
    hf.showAll();
    std::cout << std::endl;
    std::cout << "Wcisnij dowolny przycisk, aby przejsc do nastepnego etapu:";
    std::cin.get();
    Highfink hf2;
    hf2.setAll();
    std::cout << "Uzywa wskaznika abstr_emp *:\n";
    Abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
    for (int i = 0; i < 4; ++i)
        tri[i]->showAll();

    return 0;
}
