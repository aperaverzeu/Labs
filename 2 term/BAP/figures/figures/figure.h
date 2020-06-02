#ifndef FIGURE_H
#define FIGURE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>
#include <QVector>
#include <QtMath>

class Figure : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Figure(QObject *rel = 0);
    ~Figure();

    bool canDraw = true;
    bool showCenter = false;
    bool showBorder = false;
    bool waitBorder = false;
    bool canMovePoint = false;
    bool movePointNow = false;
    int numMovePoint;
    QPointF pointBorder, pointCenter;
    QPointF previousPoint, startPoint;

    QVector<QPointF> points;

    virtual qreal Perimeter();
    virtual qreal Area();

    void build();
    void move(qreal dx, qreal dy);
    void zoom(double percentage);
    virtual void rotate(double angle);

    double heron(QPointF a, QPointF b, QPointF c);
    qreal distance(QPointF a, QPointF b);
    QPointF rotatePoint(QPointF base, QPointF point, double angle);
    QPointF center();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    virtual void movePoint(int numMovePoint, qreal dx,qreal dy);
    virtual void repaint();

     /*
    void build();
    bool showC = false;
    bool waitO = false;
    bool showO = false;

     void move(qreal dx, qreal dy);
     QPointF pointO, pointC;
     void zoom(double a);
     virtual void rotate(double da);
     QPointF previousPoint, startPoint;
     double St(QPointF a, QPointF b, QPointF c);
     qreal R(QPointF a, QPointF b);
     QPointF rotatePoint(QPointF base, QPointF point, double da);
     QPointF C();
     bool canMovePoint = false;
     bool movePointNow = false;
     int numMovePoint;
      */

};

#endif // FIGURE_H
