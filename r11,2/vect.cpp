// vect.cpp -- implementacje metod klasy Vector
#include <cmath>
#include "vect.h"        // włącza plik nagłówkowy <iostream>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
    // przelicznik radianów na stopnie
    const double Rad_to_deg = 45.0 / atan(1.0);
    // powinno wyjść około 57.2957795130823
    // metody publiczne
    Vector::Vector()          // konstruktor domyślny
    {
        x = y = 0.0;
        mode = RECT;
    }
    // konstruuje wektor o zadanych współrzędnych biegunowych (w trybie 'p')
    // bądź prostokątnych (w domyślnym trybie 'r')
    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
        }
        else if (form == POL)
        {
            x = magval() / cos(angval());
            y = magval() / sin(angval());
        }
        else
        {
            cout << "Niepoprawna wartość trzeciego argumentu Vector() -- ";
            cout << "zeruję wektor\n";
            x = y = 0;
            mode = RECT;
        }
    }

    // zerowanie wartości wektora dla zadanych współrzędnych kartezjańskich (dla RECT)
    // albo dla zadanych współrzędnych biegunowych (POL)
    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
        }
        else if (form == POL)
        {
            x = n1 * cos(n2);
            y = n1 * sin(n2);
        }
        else
        {
            cout << "Niepoprawna wartość trzeciego argumentu Vector() -- ";
            cout << "zeruję wektor\n";
            x = y = 0;
            mode = RECT;
        }
    }

    double Vector::magval() const
    {
        return sqrt(x * x + y * y);
    }

    double Vector::angval() const
    {
        return atan2(y,x);
    }

    Vector::~Vector()   // destruktor
    {
    }

    void Vector::polar_mode()  // przełącza do reprezentacji biegunowej
    {
        mode = POL;
    }

    void Vector::rect_mode()   // przełącza do reprezentacji kartezjańskiej
    {
        mode = RECT;
    }

    // przeciążone operatory
    // dodawanie dwóch wektorów
    Vector Vector::operator+(const Vector & b) const
    {
        return Vector(x + b.x, y + b.y);
    }

    // odejmowanie wektora b od wektora a
    Vector Vector::operator-(const Vector & b) const
    {
        return Vector(x - b.x, y - b.y);
    }

    // zmienia znak wektora
    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    // mnoży wektor wywołujący przez n
    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }

    // funkcje zaprzyjaźnione
    // mnoży n przez wektor a
    Vector operator*(double n, const Vector & a)
    {
        return a * n;
    }

    // wyświetla współrzędne wektora (prostokątne w trybie RECT,
    // biegunowe w trybie POL)
    std::ostream & operator<<(std::ostream & os, const Vector & v)
    {
        if (v.mode == Vector::RECT)
            os << "(x,y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == Vector::POL)
        {
            os << "(m,a) = (" << v.magval() << ", "
                << v.angval() * Rad_to_deg << ")";
        }
        else
            os << "Niepoprawny tryb reprezentacji obiektu wektora";
        return os;
    }
} // koniec przestrzeni nazw VECTOR

