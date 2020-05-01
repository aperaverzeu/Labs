#ifndef MYLIST_H
#define MYLIST_H
#include <QString>
#include <info.h>


class MyList
{
public:
     Info *first = nullptr;

    MyList();

     void add(Info *info);

     void remove(Info input);

     Info* remove(Info *info, Info input);

     QString find(Info input);

     QString output();
};

#endif // MYLIST_H
