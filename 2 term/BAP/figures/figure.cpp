#include "figure.h"

Figure::Figure(QObject * rel) :
    QGraphicsScene(rel) {}

Figure::~Figure() {}

qreal Figure::Perimeter()
{
    double res = 0;
    for (int i = 0; i < (int)points.size(); i++){
        res += distance(points[i], points[(i + 1) % points.size()]);
    }
    return res / 30;
}

qreal Figure::Area()
{
    double res = 0;
    for (int i = 0; i < (int)points.size(); i++){
        res += (points[i].x() - points[(i + 1) % points.size()].x()) * (points[i].y() + points[(i + 1) % points.size()].y());
    }
    res = abs(res) / 2;
    return res / (30 * 30);
}

void Figure::build()
{
    repaint();
}

void Figure::move(qreal dx, qreal dy)
{
    for (int i = 0; i < (int)points.size(); i++) {
        points[i] = {points[i].x() + dx, points[i].y() + dy};
    }
    pointCenter = {pointCenter.x() + dx, pointCenter.y() + dy};
    repaint();
}

void Figure::zoom(double percentage)
{
    for (int i = 0; i < (int)points.size(); i++) {
        points[i] = {pointBorder.x() + (points[i].x() - pointBorder.x()) * percentage, pointBorder.y() + (points[i].y() - pointBorder.y()) * percentage};
    }
    pointCenter = {pointBorder.x() + (pointCenter.x() - pointBorder.x()) * percentage, pointBorder.y() + (pointCenter.y() - pointBorder.y()) * percentage};
    repaint();
}

void Figure::rotate(double angle)
{
    for (int i = 0; i < (int)points.size(); i++) {
        points[i] = rotatePoint(pointBorder, points[i], angle);
    }
    pointCenter = rotatePoint(pointBorder, pointCenter, angle);
    repaint();
}

double Figure::heron(QPointF a, QPointF b, QPointF c)
{
    double A, B, C, P;
    A = distance(a, b);
    B = distance(b, c);
    C = distance(c, a);
    P = (A + B + C) / 2;
    return sqrt(P * (P - A) * (P - B) * (P - C));
}

qreal Figure::distance(QPointF a, QPointF b)
{
    return sqrt((a.x() - b.x()) * (a.x() - b.x()) +  (a.y() - b.y()) * (a.y() - b.y()));
}

QPointF Figure::rotatePoint(QPointF base, QPointF point, double angle)
{
    double dx, dy, ndx, ndy;
    dx = point.x() - base.x();
    dy = point.y() - base.y();
    ndx = dx * cos(angle) - dy * sin(angle);
    ndy = dx * sin(angle) + dy * cos(angle);
    return {base.x() + ndx, base.y() + ndy};
}

QPointF Figure::center()
{
    double S = 0, x = 0, y = 0;
    for (int i = 0; i < (int)points.size(); i++) {
        double s = heron(points[0], points[i], points[(i + 1) % int(points.size())]);
        S += s;
        x += s * (points[0].x() + points[i].x() + points[(i + 1) % points.size()].x()) / 3;
        y += s * (points[0].y() + points[i].y() + points[(i + 1) % points.size()].y()) / 3;
    }
    if (S == 0) return points[0];
    x /= S;
    y /= S;
    return {x,y};
}

void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF point = event->scenePos();
    if (canDraw) {
        points.push_back(point);
        addEllipse(point.x(), point.y(), 5, 5, QPen(Qt::NoPen), QBrush(Qt::red));
    }
    else{
        if (canMovePoint){
            for (int i = 0; i < (int)points.size(); i++){
                if (distance(point, points[i]) <= 9) {
                    movePointNow = true;
                    numMovePoint = i;
                    break;
                }
            }
        }
    }
    startPoint = event->scenePos();
    previousPoint = event->scenePos();
}

void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qreal dx = event->scenePos().x() - previousPoint.x();
    qreal dy = event->scenePos().y() - previousPoint.y();
    if (movePointNow){
        movePoint(numMovePoint, dx, dy);

        pointCenter = center();
        repaint();
    }
    else if (canDraw) {
        QPointF point = event->scenePos();
        points.push_back(point);
        addLine(previousPoint.x(), previousPoint.y(), point.x(), point.y(), QPen(Qt::red, 5, Qt::SolidLine, Qt::RoundCap));
    }
    else{

        move(dx, dy);
    }
    previousPoint = event->scenePos();
}

void Figure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    movePointNow = false;
    if (event->scenePos() == startPoint && !canDraw && previousPoint == event->scenePos()){
        pointBorder = startPoint;
        //showO = true;
    }
    else{
        canDraw = false;
        pointCenter = center();
    }
    repaint();
}

// implementation in other classes
void Figure::movePoint(int numMovePoint, qreal dx, qreal dy) {}

void Figure::repaint()
{
    clear();
    for (int i = 0; i < (int)points.size(); i++) {
        addLine(points[i].x(), points[i].y(), points[(i + 1) % points.size()].x(), points[(i + 1) % points.size()].y(),(QPen(Qt::red, 5, Qt::SolidLine, Qt::RoundCap)));
    }
    if (canMovePoint) {
        for (int i = 0; i < (int)points.size(); i++) {
            addEllipse(points[i].x() - 5, points[i].y()-5, 9, 9, QPen(Qt::blue, 4), QBrush(Qt::red));
        }
    }
    if (points.size() == 1) {
         addEllipse(points[0].x(), points[0].y(), 5, 5, QPen(Qt::NoPen), QBrush(Qt::red));
    }
    if (showCenter) addEllipse(pointCenter.x()-4, pointCenter.y()-4, 7, 7, QPen(Qt::white, 3), QBrush(Qt::black));
}
