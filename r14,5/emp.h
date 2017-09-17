#ifndef EMP_H_INCLUDED
#define EMP_H_INCLUDED
#include <iostream>
#include <string>

class Abstr_emp
{
    std::string fname;
    std::string lname;
    std::string job;
public:
    Abstr_emp();
    Abstr_emp(const std::string & fn, const std::string & ln, const std::string & j);
    virtual void showAll() const;
    virtual void setAll();
    friend std::ostream & operator<<(std::ostream & os, const Abstr_emp & e);
    virtual ~Abstr_emp() = 0;
};

class Employee : public Abstr_emp
{
public:
    Employee();
    Employee(const std::string & fn, const std::string & ln, const std::string & j);
    virtual void showAll() const;
    virtual void setAll();
};

class Manager : virtual public Abstr_emp
{
    int inchargeof;
protected:
    int inChargeOf() const { return inchargeof; }
    int & inChargeOf() { return inchargeof; }
public:
    Manager();
    Manager(const std::string & fn, const std::string & ln, const std::string & j, int ico = 0);
    Manager(const Abstr_emp & e, int ico = 0);
    Manager(const Manager & m);
    virtual void showAll() const;
    virtual void setAll();
};

class Fink : virtual public Abstr_emp
{
    std::string reportsto;
protected:
    const std::string reportsTo() const { return reportsto; }
    std::string & reportsTo() { return reportsto; }
public:
    Fink();
    Fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo);
    Fink(const Abstr_emp & e, const std::string & rpo);
    Fink(const Fink & e);
    virtual void showAll() const;
    virtual void setAll();
};

class Highfink : public Manager, public Fink
{
public:
    Highfink();
    Highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico);
    Highfink(const Abstr_emp & e, const std::string & rpo, int ico);
    Highfink(const Fink & f, int ico);
    Highfink(const Manager & m, const std::string & rpo);
    Highfink(const Highfink & h);
    virtual void showAll() const;
    virtual void setAll();
};

#endif // EMP_H_INCLUDED
