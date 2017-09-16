#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED
#include <iostream>
using std::cout;
using std::endl;
class Move
{
    double x;
    double y;
public:
    Move(double a = 0, double b = 0);
    void showmove() const;
    Move add(const Move & m) const;
    void reset(double a = 0, double b = 0);
};


#endif // MOVE_H_INCLUDED
