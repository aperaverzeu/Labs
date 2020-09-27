#include "queue.h"

QString Queue::output() {
    if (this->isEmpty())
        return "Queue is empty!";

    QString res = " ";
    Node *node = this->first;
    while(node != last) {
        res += QString::number(node->data) + "   ";
        node = node->next;
    }
    if (node == last) res += QString::number(last->data) + "  ";
    return res;
}

bool Queue::isEmpty() {
    return this->first == nullptr && this->last == nullptr;
}

int Queue::front() {
    if (this->first == nullptr)
        return 0;

    return this->first->data;
}

int Queue::back() {
    if (this->last == nullptr)
        return 0;

    return this->last->data;
}

void Queue::push(int value) {
    Node *node = new Node(value);
    if (this->isEmpty()) {
        this->first = node;
        this->last = node;
        return;
    }
    last->next = node;
    last = node;
}

void Queue::pop() {
    if (this->isEmpty())
        return;

    Node *node = this->first;
    if (this->first->next != nullptr) {
        this->first = this->first->next;
        this->first->previous = nullptr;
    } else {
        this->first = nullptr;
        this->last = nullptr;
    }
    delete node;
}
