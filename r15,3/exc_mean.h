// exc_mean.h -- klasy wyjątkow dla funkcji hmean() i gmean()
#include <iostream>
#include <string>
#include <stdexcept>

class bad_mean : public std::logic_error
{
    double v1;
    double v2;
public:
    double getv1() const { return v1;}
    double getv2() const { return v2;}
    bad_mean(double a = 0, double b = 0) : std::logic_error("Inappropriate function arguments for mean"), v1(a), v2(b) { }
    virtual const char * what() { return logic_error::what();}
};


class bad_hmean : public bad_mean
{
public:
    bad_hmean (double a, double b) : bad_mean(a,b) { }
    const char * what() override { return "Inappropriate args for hmean"; }
};

class bad_gmean : public bad_mean
{
public:
    bad_gmean(double a, double b) : bad_mean(a,b) { }
    const char * what() override { return "Inappropriate args for gmean"; }
};



