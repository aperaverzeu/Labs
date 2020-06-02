#ifndef ANGLE_H
#define ANGLE_H
#include "figure.h"

class Angle : public Figure
{
public:
    Angle();
    void build(int side, double radius);

protected:
    void movePoint(int numMovePoint, qreal dx, qreal dy) override;
    QPointF buildPoint(double angle, int radius);
};

#endif // ANGLE_H
