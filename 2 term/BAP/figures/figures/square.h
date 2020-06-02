#ifndef SQUARE_H
#define SQUARE_H
#include "rectangle.h"

class Square : public Rectangle
{
public:
    Square();
    void build(double side);

private:
    void movePoint(int numMovePoint, qreal dx, qreal dy) override;
};

#endif // SQUARE_H
