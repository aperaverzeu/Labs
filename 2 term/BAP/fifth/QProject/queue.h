#ifndef QUEUE_H
#define QUEUE_H

#include <QString>

class Queue {
    struct Node {
        int data;
        Node *previous = nullptr;
        Node *next = nullptr;

        Node(int value) {
            this->data = value;
        }
    };
    Node *first = nullptr;
    Node *last = nullptr;

    public:
        bool isEmpty();
        int front();
        int back();
        void push(int);
        void pop();
        QString output();
};

#endif // QUEUE_H
