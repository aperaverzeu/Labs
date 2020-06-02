#include "circle.h"

Circle::Circle() {}

void Circle::build(double radius)
{
    canDraw = false;
    canMovePoint = true;
    points.resize(4);
    points[0] = {0, -radius};
    points[1] = {radius, 0};
    points[2] = {0,  radius};
    points[3] = {-radius,  0};
    repaint();
}

qreal Circle::Perimeter()
{
    qreal r = distance(points[0], points[2]) / 2;
    return 2 * M_PI * r / 30;
}

qreal Circle::Area()
{
    qreal r = distance(points[0], points[2]) / 2;
    return r * r * M_PI / (30 * 30);
}

void Circle::rotate(double angle)
{
    qreal r = distance(points[0], points[2]) / 2;
    pointCenter = rotatePoint(pointBorder, pointCenter, angle);
    points[0] = {pointCenter.x(), pointCenter.y()-r};
    points[1] = {pointCenter.x() + r,pointCenter.y()};
    points[2] = {pointCenter.x(), pointCenter.y()+r};
    points[3] = {pointCenter.x()-r,pointCenter.y()};
    repaint();
}

void Circle::repaint()
{
    clear();
    qreal r = distance(points[0], points[2]) / 2;
    addEllipse(pointCenter.x() - r, pointCenter.y() - r,2 * r,2 * r,QPen(Qt::red, 3));
    if (canMovePoint){
        for (int i = 0; i < (int)points.size(); i++){
            addEllipse(points[i].x() - 5, points[i].y()-5, 9, 9, QPen(Qt::blue, 4), QBrush(Qt::red));
        }
    }
    if (showCenter) addEllipse(pointCenter.x()-4, pointCenter.y()-4, 7, 7, QPen(Qt::white, 3), QBrush(Qt::black));
}

void Circle::movePoint(int numMovePoint, qreal dx, qreal dy)
{
    int direction;
    switch(numMovePoint){
    case 0:
        if (points[0].y() < points[2].y()) {
            direction = -dy;
            points[0] = {points[0].x(), points[0].y() - direction};
            points[2] = {points[0].x(), points[2].y() + direction};
        }
        else {
            direction = dy;
            points[0] = {points[0].x(), points[0].y() + direction};
            points[2] = {points[0].x(), points[2].y() - direction};
        }
        if (points[1].x() < points[3].x()) {
            points[1] = {points[1].x() - direction, points[1].y()};
            points[3] = {points[3].x() + direction, points[3].y()};
        }
        else {
            points[1] = {points[1].x() + direction, points[1].y()};
            points[3] = {points[3].x() - direction, points[3].y()};
        }
        break;
    case 1:
        if (points[1].x() < points[3].x()) {
            direction = -dx;
            points[1] = {points[1].x() - direction, points[1].y()};
            points[3] = {points[3].x() + direction, points[3].y()};
        }
        else {
            direction = dx;
            points[1] = {points[1].x() + direction, points[1].y()};
            points[3] = {points[3].x() - direction, points[3].y()};
        }
        if (points[0].y() < points[2].y()) {
            points[0] = {points[0].x(), points[0].y() - direction};
            points[2] = {points[0].x(), points[2].y() + direction};
        }
        else {
            points[0] = {points[0].x(), points[0].y() + direction};
            points[2] = {points[0].x(), points[2].y() - direction};
        }
        break;
    case 2:
        if (points[0].y() < points[2].y()) {
            direction = dy;
            points[0] = {points[0].x(), points[0].y() - direction};
            points[2] = {points[0].x(), points[2].y() + direction};
        }
        else {
            direction = -dy;
            points[0] = {points[0].x(), points[0].y() + direction};
            points[2] = {points[0].x(), points[2].y() - direction};
        }
        if (points[1].x() < points[3].x()) {
            points[1] = {points[1].x() - direction, points[1].y()};
            points[3] = {points[3].x() + direction, points[3].y()};
        }
        else {
            points[1] = {points[1].x() + direction, points[1].y()};
            points[3] = {points[3].x() - direction, points[3].y()};
        }
        break;
    case 3:
        if (points[1].x() < points[3].x()) {
            direction = -dx;
            points[1] = {points[1].x() + direction, points[1].y()};
            points[3] = {points[3].x() - direction, points[3].y()};
        }
        else {
            direction = dx;
            points[1] = {points[1].x() - direction, points[1].y()};
            points[3] = {points[3].x() + direction, points[3].y()};
        }
        if (points[0].y() < points[2].y()) {
            points[0] = {points[0].x(), points[0].y() + direction};
            points[2] = {points[0].x(), points[2].y() - direction};
        }
        else {
            points[0] = {points[0].x(), points[0].y() - direction};
            points[2] = {points[0].x(), points[2].y() + direction};
        }
        break;
    }
}
