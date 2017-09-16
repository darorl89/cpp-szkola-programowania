#ifndef COMPLEX0_H_INCLUDED
#define COMPLEX0_H_INCLUDED
#include <iostream>

class Complex
{
    double real;
    double imaginary;
public:
    Complex(double r = 0.0, double i = 0.0)
    {
        real = r;
        imaginary = i;
    }
    Complex operator+(const Complex & c) const
    {
        Complex result(real + c.real, imaginary + c.imaginary);
        return result;
    }
    Complex operator-(const Complex & c) const
    {
        Complex result(real - c.real, imaginary - c.imaginary);
        return result;
    }
    Complex operator*(const Complex & c) const
    {
        Complex result(real * c.real - imaginary * c.imaginary, real * c.imaginary + imaginary * c.real);
        return result;
    }
    friend Complex operator*(double x, const Complex & c)
    {
        Complex result(x * c.real, x * c.imaginary);
        return result;
    }
    friend Complex operator*(const Complex & c, double x)
    {
        return x * c;
    }
    friend Complex operator~(const Complex & c)
    {
        Complex result(c.real,-c.imaginary);
        return result;
    }
    friend std::ostream & operator<<(std::ostream & os, const Complex & c);
    friend Complex operator>>(std::istream & is, const Complex & c);
};


#endif // COMPLEX0_H_INCLUDED
