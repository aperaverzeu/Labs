#ifndef CANVAS_H
#define CANVAS_H

#include <QtWidgets>
#include "mainwindow.h"

class Pile {
public:
    Pile(int a,int b) : x(a), y(b) {}
    ~Pile();

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

private:
    int x;
    int y;
};

class Canvas : public QWidget {
    Q_OBJECT

public:
    Canvas(MainWindow *p);

    void draw();
    void drawRectangle();
    void drawTempRectangle();
    void drawCircle();
    void drawTempCircle();
    void drawLine();
    void drawTempLine();
    void fill();
    int filling4(int x,int y,QRgb coltarget, QRgb colrep);

    void paintEvent(QPaintEvent *event);

    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

public slots:
    void newCanvas();
    void saveCanvas();
    void openCanvas();
    void returnCanvas();

private:
    int xMove;
    int yMove;
    int xPress;
    int yPress;
    int xRelease;
    int yRelease;

    int pixActual;
    int xMax;
    int yMax;

    QPainter *painter;
    QLabel *label;
    MainWindow *parent;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QImage *image;
    QVector<QPixmap *> pixmapList;
    QPainterPath *path;
};

#endif // CANVAS_H
