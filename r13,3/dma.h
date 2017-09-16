// dma.h -- dziedziczenie i dynamiczny przydział pamięci
#ifndef DMA_H_
#define DMA_H_
#include <iostream>
class DMA
{
    int rating;
    char * label;
public:
    DMA(const char * l, int r);
    virtual ~DMA();
    DMA(const DMA & rs);
    DMA & operator=(const DMA & rs);
    int showRating() const;
    char * showLabel() const;
    virtual void View() const;
};

// klasa bazowa korzystająca z dynamicznego przydziału pamięci
class baseDMA : public DMA
{
    public:
        baseDMA(const char * l = "brak", int r = 0);
        baseDMA(const baseDMA & rs);
        virtual ~baseDMA();
        baseDMA & operator=(const DMA & rs);
        baseDMA & operator=(const baseDMA & rs);
        friend std::ostream & operator<<(std::ostream & os,
                const baseDMA & rs);
        virtual void View() const;
};

// klasa pochodna bez dynamicznego przydziału pamięci
// nie jest potrzebny destruktor
// używa niejawnego konstruktora kopiującego
// używa niejawnego operatora przypisania
class lacksDMA : public DMA
{
    private:
        enum { COL_LEN = 40 };
        char color[COL_LEN];
    public:
        lacksDMA(const char * c = "brak", const char * l = "brak",
                int r = 0);
        lacksDMA(const char * c, const baseDMA & rs);
        lacksDMA(const lacksDMA & rs);
        lacksDMA & operator=(const lacksDMA & rs);
        virtual ~lacksDMA() {}
        friend std::ostream & operator<<(std::ostream & os,
                const lacksDMA & rs);
        virtual void View() const;
};

// klasa pochodna z dynamicznym przydziałem pamięci
class hasDMA : public DMA
{
    private:
        char * style;
    public:
        hasDMA(const char * s = "brak", const char * l = "brak",
                int r = 0);
        hasDMA(const char * s, const baseDMA & rs);
        hasDMA(const hasDMA & hs);
        ~hasDMA();
        hasDMA & operator=(const hasDMA & rs);
        friend std::ostream & operator<<(std::ostream & os,
                const hasDMA & rs);
        virtual void View() const;
};

#endif
