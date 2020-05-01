#ifndef INFO_H
#define INFO_H

#include <QString>

class Info
{
public:
    Info(QString name, QString surname, QString city, QString street, QString house, int markMath, int markPhys, int markLang, double averageMark);

    QString name, surname;
    QString city, street, house;
    int markMath, markPhys, markLang;
    double averageMark;
    Info *next;

    bool isEqual(Info input);
};

#endif // INFO_H
