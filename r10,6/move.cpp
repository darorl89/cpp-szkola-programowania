#include "Move.h"

Move::Move(double a, double b)
{
    x = a;
    y = b;
}
void Move::showmove() const
{
    cout << "Pozycja x: " << x << ", y: " << y << endl;
}
Move Move::add(const Move & m) const
{
    Move newMove;
    newMove.x = this->x + m.x;
    newMove.y = this->y + m.y;
    return newMove;
}
void Move::reset(double a, double b)
{
    x = a;
    y = b;
}
