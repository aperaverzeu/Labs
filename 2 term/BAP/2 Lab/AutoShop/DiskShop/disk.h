#ifndef DISK_H
#define DISK_H
#include <QString>

class Disk
{
public:
    Disk(QString type, QString author, QString title, QString note, int price);

    QString type;
    QString author;
    QString title;
    QString note;
    int price;

};

#endif // DISK_H
