#ifndef RECT_H
#define RECT_H
#include <QPainter>

class Rect
{
public:
    Rect();
protected:
    void DrawRectUp(QPainter *painter);
    void DrawRectDown(QPainter *painter);
};

#endif // RECT_H
