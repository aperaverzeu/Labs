#include "square.h"

Square::Square() {}

void Square::build(double side)
{
    canDraw = false;
    canMovePoint = true;
    points.resize(4);
    points[0] = {-side/2, -side/2};
    points[1] = {side/2 , -side/2};
    points[2] = {side/2 ,  side/2};
    points[3] = {-side/2,  side/2};
    repaint();
}

void Square::movePoint(int numMovePoint, qreal dx, qreal dy)
{
    qreal ndx, ndy, dx0, dy0;
    ndx = points[numMovePoint].x() - points[(numMovePoint + 2) % 4].x();
    ndy = points[numMovePoint].y() - points[(numMovePoint + 2) % 4].y();
    if ((points[numMovePoint].x() < pointCenter.x())^(points[numMovePoint].y() > pointCenter.y())){
        dx0 = (dx + dy) * ndx / (ndx + ndy);
        dy0 = (dx + dy) * ndy / (ndx + ndy);
    }
    else{
        dx0 = (dx - dy) * ndx / (ndx - ndy);
        dy0 = (dx - dy) * ndy / (ndx - ndy);
    }
    dx = dx0;
    dy = dy0;
    points[numMovePoint] = {points[numMovePoint].x() + dx, points[numMovePoint].y() + dy};
    if (points[numMovePoint].x() == points[(numMovePoint + 2) % 4].x())
        points[numMovePoint] = {points[numMovePoint].x() + 0.1, points[numMovePoint].y() + 0.1};
    if (points[numMovePoint].y() == points[(numMovePoint + 2) % 4].y())
        points[numMovePoint] = {points[numMovePoint].x() + 0.1,points[numMovePoint].y() + 0.1};
    points[(numMovePoint - 1 + 4) % 4] = hypotenuse(points[(numMovePoint - 1 + 4) % 4], points[(numMovePoint - 2 + 4) % 4], points[numMovePoint]);
    points[(numMovePoint + 1 + 4) % 4] = hypotenuse(points[(numMovePoint + 1 + 4) % 4], points[(numMovePoint + 2 + 4) % 4], points[numMovePoint]);
}
