#ifndef SHIP_H
#define SHIP_H
#include <QPainter>
#include <rect.h>

class ship : public Rect
{
public:
    ship();

    void Up();

    void Down();

    void DrawShip(QPainter *painter);

private:
    bool IsFlagUp = false;
};

#endif // SHIP_H
