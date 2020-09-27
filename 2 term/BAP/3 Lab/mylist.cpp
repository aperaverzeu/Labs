#include "mylist.h"

MyList::MyList()
{

}

void MyList::add(Info *info)
{
    info->next = first;
    first = info;
}

void MyList::remove(Info input)
{
    first = remove(first, input);
}

Info *MyList::remove(Info *info, Info input)
{
    if (info == nullptr) {
        return nullptr;
    }
    if (info->isEqual(input)) {
        return remove(info->next, input);
    }
    else {
            info->next = remove(info->next, input);
            return info;
    }
}

QString MyList::find(Info input)
{
    QString s;
    Info *info = first;
    while(info != nullptr) {
        if (info->isEqual(input)) {
            s = "Name: " + info->name + "\nSurname: " + info->surname + "\nCity: " + info->city + "\nStreet: " + info->street + "\nHouse: " + info->house
                    + "\nMarks:\nMath: " + QString::number(info->markMath) + "\tPhysics: " + QString::number(info->markPhys) + "\tLang: " + QString::number(info->markLang)
                    + "\nAverage mark:   " + QString::number(info->averageMark) + "\n----------\n" + s;
        }
        info = info->next;
    }
    return s;
}

QString MyList::output()
{
    QString s;
       Info *info = first;
       while(info != nullptr){
           s = "Name: " + info->name + "\nSurname: " + info->surname + "\nCity: " + info->city + "\nStreet: " + info->street + "\nHouse: " + info->house
                   + "\nMarks:\nMath: " + QString::number(info->markMath) + "\tPhysics: " + QString::number(info->markPhys) + "\tLang: " + QString::number(info->markLang)
                   + "\nAverage mark:   " + QString::number(info->averageMark) + "\n----------\n" + s;
           info = info->next;
       }
       return s;
}


