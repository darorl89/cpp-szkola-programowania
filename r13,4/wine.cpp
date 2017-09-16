#include "wine.h"

Port::Port(const char * br, const char * st, int b)
{
    brand = new char [strlen(br) + 1];
    strcpy(brand,br);
    strncpy(style,st,20);
    bottles = b;
}

Port::Port(const Port & p)
{
    brand = new char [strlen(p.brand) + 1];
    strcpy(brand,p.brand);
    strncpy(style,p.style,20);
    bottles = p.bottles;
}

Port & Port::operator=(const Port & p)
{
    if (this == &p)
        return *this;
        return *this;
    delete [] brand;
    brand = new char [strlen(p.brand) + 1];
    strcpy(brand,p.brand);
    strncpy(style,p.style,20);
    bottles = p.bottles;
    return *this;
}

Port & Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port & Port::operator-=(int b)
{
    bottles -= b;
    return *this;
}

void Port::Show() const
{
    std::cout << "Marka: " << brand << std::endl;
    std::cout << "Styl: " << style << std::endl;
    std::cout << "Liczba butelek: " << bottles << std::endl;
}

ostream & operator<<(ostream & os, const Port & p)
{
    os << "Marka: " << p.brand
    << ", styl: " << p.style
    << ", liczba butelek: " << p.bottles << std::endl;
    return os;
}

VintagePort::VintagePort() : Port()
{
    nickname = nullptr;
    year = 0;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y) : Port(br,"Brak",b)
{
    nickname = new char [strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}
VintagePort::VintagePort(const VintagePort & vp) : Port(vp)
{
    nickname = new char [strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    Port::operator=(vp);
    delete [] nickname;
    nickname = new char [strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    std::cout << "Nazwa: " << nickname << std::endl;
    std::cout << "Rok: " << year << std::endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp)
{
    os << (const Port &) vp;
    os << ", nazwa: " << vp.nickname << ", rocznik: " << vp.year << std::endl;
    return os;
}
