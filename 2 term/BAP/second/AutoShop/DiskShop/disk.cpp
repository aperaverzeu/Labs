#include "disk.h"

Disk::Disk(QString type, QString author, QString title, QString note, int price)
{
    this->type = type;
    this->author = author;
    this->title = title;
    this->note = note;
    this->price = price;
}
