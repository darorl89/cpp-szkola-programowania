#include "emp.h"

Abstr_emp::Abstr_emp() : fname("UNDEF"), lname("UNDEF"), job("UNDEF") {}

Abstr_emp::~Abstr_emp() {}

Abstr_emp::Abstr_emp(const std::string & fn, const std::string & ln, const std::string & j) : fname(fn), lname(ln), job(j) {}

void Abstr_emp::showAll() const
{
    std::cout << "Imie: " << fname << std::endl
    << "Nazwisko: " << lname << std::endl
    << "Praca: " << job;
}

void Abstr_emp::setAll()
{
    std::cout << "Podaj imie: ";
    std::cin >> fname;
    std::cout << "Podaj nazwisko: ";
    std::cin >> lname;
    std::cout << "Podaj prace: ";
    std::cin >> job;
}

std::ostream & operator<<(std::ostream & os, const Abstr_emp & e)
{
    os << "Imie: " << e.fname << ", nazwisko: " << e.lname << ", praca: " << e.job;
    return os;
}



Employee::Employee() : Abstr_emp() {}

Employee::Employee(const std::string & fn, const std::string & ln, const std::string & j) : Abstr_emp(fn, ln, j) {}

void Employee::showAll() const { Abstr_emp::showAll(); }

void Employee::setAll() { Abstr_emp::setAll(); }



Manager::Manager() : Abstr_emp(), inchargeof(-1) {}

Manager::Manager(const std::string & fn, const std::string & ln, const std::string & j, int ico) : Abstr_emp(fn, ln, j), inchargeof(ico) {}

Manager::Manager(const Abstr_emp & e, int ico) : Abstr_emp(e), inchargeof(ico) {}

Manager::Manager(const Manager & m) : Abstr_emp(m), inchargeof(m.inchargeof) {}

void Manager::showAll() const
{
    Abstr_emp::showAll();
    std::cout << std::endl
    << "Dowodzi: " << inchargeof;
}

void Manager::setAll()
{
    Abstr_emp::setAll();
    std::cout << "Podaj dowodzenie: ";
    std::cin >> inchargeof;
}



Fink::Fink() : Abstr_emp(), reportsto("UNDEF") {}

Fink::Fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo) : Abstr_emp(fn, ln, j), reportsto(rpo) {}

Fink::Fink(const Abstr_emp & e, const std::string & rpo) : Abstr_emp(e), reportsto(rpo) {}

Fink::Fink(const Fink & e) : Abstr_emp(e), reportsto(e.reportsto) {}

void Fink::showAll() const
{
    Abstr_emp::showAll();
    std::cout << std::endl
    << "Raportuje do: " << reportsto;
}

void Fink::setAll()
{
    Abstr_emp::setAll();
    std::cout << "Komu raportuje: ";
    std::cin >> reportsto;
}



Highfink::Highfink() : Abstr_emp(), Manager(), Fink() {}

Highfink::Highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico) : Abstr_emp(fn, ln, j), Manager(fn,ln,j,ico), Fink(fn,ln,j,rpo) {}

Highfink::Highfink(const Abstr_emp & e, const std::string& rpo, int ico) : Abstr_emp(e), Manager(e,ico), Fink(e,rpo) {}

Highfink::Highfink(const Fink& f, int ico) : Abstr_emp(f), Manager(f,ico), Fink(f) {}

Highfink::Highfink(const Manager& m, const std::string& rpo) : Abstr_emp(m), Manager(m), Fink(m, rpo) {}

Highfink::Highfink(const Highfink& h) : Abstr_emp(h), Manager(h), Fink(h) {}

void Highfink::showAll() const
{
    Abstr_emp::showAll();
    std::cout << std::endl
    << "Dowodzi: " << Manager::inChargeOf() << std::endl
    << "Raportuje do: " << Fink::reportsTo();
}

void Highfink::setAll()
{
    Abstr_emp::setAll();
    std::cout << "Podaj dowodzenie: ";
    std::cin >> Manager::inChargeOf();
    std::cout << "Komu raportuje: ";
    std::cin >> Fink::reportsTo();
}
