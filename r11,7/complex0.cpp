#include "complex0.h"

std::ostream & operator<<(std::ostream & os, const Complex & c)
{
    os << "(" << c.real << "," << c.imaginary << ")";
    return os;
}
Complex operator>>(std::istream & is, const Complex & c)
{
    double r,i;
    std::cout << "Podaj skladowa rzeczywista: ";
    is >> r;
    std::cout << "Podaj skladowa urojona: ";
    is >> i;
    Complex result(r,i);
    std::cout << result;
    return result;
}
