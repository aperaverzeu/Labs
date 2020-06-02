#ifndef CIRCLE_H
#define CIRCLE_H
#include "figure.h"

class Circle : public Figure
{
public:
    Circle();
    void build(double radius);
    qreal Perimeter() override;
    qreal Area() override;
    void rotate(double angle) override;
protected:
    void repaint() override;
private:
    void movePoint(int numMovePoint, qreal dx, qreal dy) override;
};

#endif // CIRCLE_H
