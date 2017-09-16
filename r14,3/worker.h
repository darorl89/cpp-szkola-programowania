#ifndef WORKER_H_INCLUDED
#define WORKER_H_INCLUDED
#include <iostream>
class Worker
{
    std::string fullname;
    long id;
protected:
    virtual void Data() const {std::cout << "Nazwisko: " << fullname << ", id: " << id;}
    virtual void Get() {std::cout << "Podaj nazwisko: ";std::cin >> fullname; std::cout << "Podaj id: "; std::cin >> id;}
public:
    Worker(const std::string & s = "Brak", long n = 0) : fullname(s), id(n) {}
    virtual ~Worker() {}
};

#endif // WORKER_H_INCLUDED
