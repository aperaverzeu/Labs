#include "rect.h"

Rect::Rect()
{

}

void Rect::DrawRectUp(QPainter *painter)
{
    QRect flag(QPoint(300,120), QSize(100,50));

    painter->setPen(QPen(Qt::red, 3, Qt::SolidLine, Qt::FlatCap));
    painter->drawRect(flag);
}

void Rect::DrawRectDown(QPainter *painter)
{
    QRect flag(QPoint(300,340), QSize(100,50));

    painter->setPen(QPen(Qt::red, 3, Qt::SolidLine, Qt::FlatCap));
    painter->drawRect(flag);
}
