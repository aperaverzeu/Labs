#ifndef AUTO_H
#define AUTO_H

#include <QString>

class Auto
{
public:
    Auto(QString country, QString mark, QString motorType, int price, int eating, int durability, int convenience);

    QString country;
    QString mark;
    QString motorType;
    int price;
    int eating;
    int durability;
    int convenience;
};

#endif // AUTO_H
