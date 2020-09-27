#include "rectangle.h"

Rectangle::Rectangle() {}

void Rectangle::build(double sideN, double sideM)
{
    canDraw = false;
    canMovePoint = true;
    points.resize(4);
    points[0] = {-sideM/2, -sideN/2};
    points[1] = {sideM/2 , -sideN/2};
    points[2] = {sideM/2 ,  sideN/2};
    points[3] = {-sideM/2,  sideN/2};
    repaint();
}

QPointF Rectangle::hypotenuse(QPointF a, QPointF b, QPointF c)
{
    qreal dimAB, dimBA, hipAB, hipBA, d;
    dimAB = a.y() - b.y();
    dimBA = b.x() - a.x();
    hipAB = a.x() * b.y() - a.y() * b.x();
    hipBA = - dimBA * c.x() - (-dimAB) * c.y();
    d = dimAB * (-dimAB) - dimBA * dimBA;
    return {(dimBA * hipBA - (-dimAB) * hipAB) / d,(dimBA * hipAB - dimAB * hipBA) / d};
}

void Rectangle::movePoint(int numMovePoint, qreal dx, qreal dy)
{
    points[numMovePoint] = {points[numMovePoint].x() + dx, points[numMovePoint].y() + dy};
    if (points[numMovePoint].x() == points[(numMovePoint + 2) % 4].x())
        points[numMovePoint] = {points[numMovePoint].x() + 0.1,points[numMovePoint].y()};
    if (points[numMovePoint].y() == points[(numMovePoint + 2) % 4].y())
        points[numMovePoint] = {points[numMovePoint].x(),points[numMovePoint].y() + 0.1};
    points[(numMovePoint - 1 + 4) % 4] = hypotenuse(points[(numMovePoint - 1 + 4) % 4], points[(numMovePoint - 2 + 4) % 4], points[numMovePoint]);
    points[(numMovePoint + 1 + 4) % 4] = hypotenuse(points[(numMovePoint + 1 + 4) % 4], points[(numMovePoint + 2 + 4) % 4], points[numMovePoint]);
}
