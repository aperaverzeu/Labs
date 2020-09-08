#include <stdio.h>
#include <stdlib.h>


struct QNode {
    int key;
    struct QNode* next;
};

struct Queue {
    struct QNode *front, *back;
};

struct QNode* newNode(int k) {
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->back = NULL;
    return q;
}

void QPush(struct Queue* q, int k) {
    struct QNode* temp = newNode(k);
    if (q->back == NULL) {
        q->front = q->back = temp;
        return;
    }
    q->back->next = temp;
    q->back = temp;
}

void QPop(struct Queue* q) {
    if (q->front == NULL)
        return;

    struct QNode* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->back = NULL;

    free(temp);

}

int main() {
    struct Queue* q = createQueue();
    struct Queue* qt = createQueue();
    int number;
    printf("Enter number of elements:\t");
    scanf("%d", &number);
    int temp[number];
    // init queue
    for (int i = 0; i < number; i++) {
        QPush(q,i+1);
    }
    // queue output
    for (int i = 0; i < number; i++) {
        printf("%d\t", q->front->key);
        temp[i] = q->front->key;
        QPop(q);
    }
    printf("\n——————————————————————————————\n");
    for (int k = number ; k-- > 0 ; ) {
        int t = temp[k];
        QPush(qt,t);
    }
    // reverse
    for (int i = 0; i < number; i++) {
        printf("%d\t", qt->front->key);
        QPop(qt);
    }



    return 0;
}

