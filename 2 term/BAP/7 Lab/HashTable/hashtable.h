#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <list>
#include <QString>
#include <QMessageBox>

class HashTable {
private:
    static const int hashGroups = 10;
    std::list<std::pair<int, QString>> table[hashGroups];

public:
    bool isEmpty();
    int hashFunction(int key);
    void insertItem(int key, QString value);
    void removeItem(int key);
    QString searchItem(int key);
    QString printTable();
    void clear();
    int findBigger(int amount);

};

#endif // HASHTABLE_H
