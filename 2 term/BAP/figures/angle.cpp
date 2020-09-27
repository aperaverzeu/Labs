#include "angle.h"

Angle::Angle() {}

void Angle::build(int side, double radius)
{
    canMovePoint = true;
    canDraw = false;
    for (int i = 0; i < side; i++) {
        points.push_back(buildPoint(i * 2 * M_PI / side + M_PI / side, radius));
    }
    repaint();
}

void Angle::movePoint(int numMovePoint, qreal dx, qreal dy)
{
    points[numMovePoint] = { points[numMovePoint].x() + dx,
                                                    points[numMovePoint].y() + dy };
}

QPointF Angle::buildPoint(double angle, int radius)
{
    return {radius * sin(angle), radius * cos(angle)};
}
