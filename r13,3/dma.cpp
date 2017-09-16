// dma.cpp -- metody klas

#include "dma.h"
#include <cstring>


DMA::DMA(const char * l, int r)
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

DMA::DMA(const DMA & rs)
{
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

DMA::~DMA()
{
    delete [] label;
}

int DMA::showRating() const
{
    return rating;
}

char * DMA::showLabel() const
{
    return label;
}

DMA & DMA::operator=(const DMA & rs)
{
    if (this == &rs)
        return *this;
    delete [] label;
    label = new char [strlen(rs.label) + 1];
    strcpy(label,rs.label);
    rating = rs.rating;
    return *this;
}
void DMA::View() const
{
    std::cout << "Etykietka: " << label << std::endl;
    std::cout << "Ocena: " << rating << std::endl;
}
// metody klasy baseDMA
baseDMA::~baseDMA()
{

}
baseDMA::baseDMA(char const * l, int r) : DMA(l,r)
{

}
baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    DMA::operator=(rs);
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
    os << "Etykietka: " << rs.showLabel() << ", ocena: " << rs.showRating() << std::endl;
    return os;
}

void baseDMA::View() const
{
    DMA::View();
}

// metody klasy lacksDMA
lacksDMA::lacksDMA(const char * c, const char * l, int r)
: DMA(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs)
: DMA(rs)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const lacksDMA & rs) : DMA(rs)
{
    std::strncpy(color, rs.color, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

lacksDMA & lacksDMA::operator=(const lacksDMA & rs)
{
    if (this == &rs)
        return *this;
    DMA::operator=(rs);
    return *this;
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
    os << (const baseDMA &) ls;
    os << "Kolor: " << ls.color << std::endl;
    return os;
}

void lacksDMA::View() const
{
    std::cout << "Kolor: " << color << std::endl;
}

// metody klasy hasDMA
hasDMA::hasDMA(const char * s, const char * l, int r)
: DMA(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const baseDMA & rs)
: DMA(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs)
: DMA(hs) // wywołuje konstruktor kopiujący klasy bazowej
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs)
        return *this;
    DMA::operator=(hs); // kopiuje dane klasy bazowej
    delete [] style; // przygotowanie do nowego stylu
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
    os << (const baseDMA &) hs;
    os << "Styl: " << hs.style << std::endl;
    return os;
}

void hasDMA::View() const
{
    DMA::View();
    std::cout << "Styl: " << style <<std::endl;
}
