#include "hashtable.h"

bool HashTable::isEmpty() {
    int sum{};
    for (int i{}; i < hashGroups; ++i) {
        sum += table[i].size();
    }
    if (!sum) {
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key) {
    return key % hashGroups;
}

void HashTable::insertItem(int key, QString value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr->second = value;
            // std::cout << "[WARNING] Key exists! Value replaced." << std::endl;
            break;
        }
    }

    if (!keyExists) {
        cell.emplace_back(key, value);
    }

    return;
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr = cell.erase(bItr);
            // std::cout << "[INFO] Pair remove." << std::endl;
            break;
        }
    }

    if (!keyExists) {
       // QMessageBox::information(this, "", "[WARNING] Key not found");
    }

    return;
}

QString HashTable::searchItem(int key) {
    QString res;
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            res = bItr->second;
            break;
        }
    }

    if (!keyExists) {
        res = "[WARNING] Key not found";
    }

    return res;
}

QString HashTable::printTable() {
    QString res;
    for (int i{}; i < hashGroups; ++i) {
        if (table[i].size() == 0) continue;

        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++) {
            res += "Key: " + QString::number(bItr->first) + "     Value: " + bItr->second + '\n';
            // std::cout << "[INFO] key: " << bItr->first << "Value: " << bItr->second << std::endl;
        }
    }
    return res;
}

void HashTable::clear() {
    while (!table->empty()) {
        table->pop_back();
    }
}

int HashTable::findBigger(int amount) {
    int keyValue = 0, averageKeyValue = 0, moreThenAverage = 0;

    for (int i{}; i < amount; ++i) {
        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++) {
            keyValue += bItr->first;
        }
    }

    averageKeyValue = keyValue/amount;

    for (int i{}; i < amount; ++i) {
        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++) {
            if (bItr->first > averageKeyValue) {
                moreThenAverage++;
            }
        }
    }
    return moreThenAverage;
}

