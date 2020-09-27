#include "info.h"

Info::Info(QString name, QString surname, QString city, QString street, QString house, int markMath, int markPhys, int markLang, double averageMark)
{
    this->name = name;
    this->surname = surname;
    this->city = city;
    this->street = street,
    this->house = house;
    this->markMath = markMath;
   this->markPhys = markPhys;
    this->markLang = markLang;
    this->averageMark = averageMark;
}

bool Info::isEqual(Info input)
{
    return (input.name == "" || input.name == name) &&
                (input.surname == "" || input.surname == surname) &&
                (input.city == "" || input.city == city) &&
                (input.street == "" || input.street == street) &&
                (input.house == "" || input.house == house) &&
                (input.markMath == 0 || input.markMath <= markMath) &&
                (input.markPhys == 0 || input.markPhys <= markPhys) &&
                (input.markLang == 0 || input.markLang  <= markLang) &&
                (input.averageMark == 0.0 || input.averageMark == averageMark);



}
