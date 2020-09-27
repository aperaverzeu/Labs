#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "angle.h"

class Rectangle : public Angle
{
public:
    Rectangle();
    void build(double sideN, double sideM);
    QPointF hypotenuse(QPointF a, QPointF b, QPointF c);

private:
    void movePoint(int numMovePoint, qreal dx, qreal dy) override;
};

#endif // RECTANGLE_H
