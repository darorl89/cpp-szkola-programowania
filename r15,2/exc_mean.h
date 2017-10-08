// exc_mean.h -- klasy wyjątkow dla funkcji hmean() i gmean()
#include <iostream>
#include <stdexcept>

class bad_hmean : public std::logic_error
{
    private:
        double v1;
        double v2;
    public:
        bad_hmean(double a = 0, double b = 0) : std::logic_error("hmean: niepoprawne argumenty: a = -b"), v1(a), v2(b) { }
        const char * what();
};

inline const char * bad_hmean::what()
{
        return "niepoprawne argumenty funkcji hmean: a = -b\n";
}


class bad_gmean : public std::logic_error
{
    public:
        double v1;
        double v2;
        bad_gmean(double a = 0, double b = 0) : std::logic_error("Argumenty funkcji gmean() powinny byc >= 0"), v1(a), v2(b) { }
        const char * what();
};

inline const char * bad_gmean::what()
{
   return "Argumenty funkcji gmean() powinny byc >= 0\n";
}

