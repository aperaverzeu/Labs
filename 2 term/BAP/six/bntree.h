#ifndef BNTREE_H
#define BNTREE_H
#include <string>
#include <cmath>
#include <QTreeWidget>
#include <QString>

typedef struct tree_s tree_t;
typedef struct node_s node_t;
typedef struct data_s data_t;

struct data_s {
    QString key;
    QString value;
};

struct node_s {
    data_t data;

    uint64_t weight; // количество узлов у данного узла

    node_t *left;
    node_t *right;

    node_t *parent;
};

struct tree_s
{
    node_t *root; // указатель на корень дерева
};

class bntree
{
public:
    bntree();
    ~bntree();

    node_t *p = nullptr;

    // Вставка данных, ключ - значение
    void insert(QString key, QString val = "");
    // Удаление узла по индексу
    void erase(uint64_t index);
    // Удаление узла по ключу
    void erase(QString key);
    // Взятие узла по индексу
    data_t *get(uint64_t index);
    // Взятие узла по ключу
    data_t *get(QString key);
    void output(QTreeWidget *tree);
    void rec(QTreeWidget *tree, QTreeWidgetItem *p, node_t *r, bool b);
    void clearD();
    // Поиск узла по ключу, возвращает индекс узла
    uint64_t search(QString key);

    // Кол-во элементов в дереве
    uint64_t size();

    // Печать дерева
    void print();
    tree_t *tree;

protected:


    uint64_t get_child_weight(node_t *node);
    node_t *node_new();
    void node_free(node_t *e);
    bool erase_simple(node_t *search_node);
    void clear(node_t *p);
    void print(node_t *p, int indent);
    void balance(node_t *p);
    void clearD(node_t *p);

public:
    // Ближайшая степень 2-ки к числу
    uint64_t cpl2(uint64_t x);

    // Быстрый логарифм
    long ilog2(long x);

    // Вес узла к глубине
    uint64_t weight_to_depth(node_t *p);

    QString findMax(node_t* p);
    node_t* getParent(node_t *p, QString key);
    void removeMaxBranch();
};

#endif // BNTREE_H
