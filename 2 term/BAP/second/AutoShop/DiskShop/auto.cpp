#include "auto.h"

Auto::Auto(QString country, QString mark, QString motorType, int price, int eating, int durability, int convenience)
{
    this->country = country;
    this->mark = mark;
    this->motorType = motorType;
    this->price = price;
    this->eating = eating;
    this->durability = durability;
    this->convenience = convenience;
}
