#include "ship.h"

ship::ship()
{

}

void ship::Up()
{
    IsFlagUp = true;
}

void ship::Down()
{
    IsFlagUp = false;
}

void ship::DrawShip(QPainter *painter)
{
    //DrawRect(painter);

    static const QPointF points[5] = {
            QPointF(100.0, 400.0),
            QPointF(150.0, 500.0),
            QPointF(550.0, 500.0),
            QPointF(650.0, 400.0),
            QPointF(100.0, 400.0),
        };

        painter->drawPolyline(points, 5);
        painter->drawEllipse(590,412,14,14);
        painter->drawEllipse(450,415,12,12);
        painter->drawEllipse(400,415,12,12);
        painter->drawEllipse(350,415,12,12);
        painter->drawEllipse(300,415,12,12);
        painter->drawEllipse(250,415,12,12);
        painter->drawEllipse(200,415,12,12);
        painter->drawEllipse(150,415,12,12);
        painter->drawLine(400,120,400,400);

        if(IsFlagUp)
        {
            DrawRectUp(painter);
        }
        else
        {
            DrawRectDown(painter);
        }
}
