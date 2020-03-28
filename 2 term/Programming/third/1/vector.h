#include <stdio.h>
#include <stdbool.h>
#define VECTOR_INITIAL_CAPACITY 1

typedef struct {
    int size;
    int capacity;
    int *data;
} Vector;

void init(Vector *vector);
int get(Vector *vector, int index);
void set(Vector *vector, int index, int value);

bool empty(Vector *vector);
int size(Vector *vector);
int capacity(Vector *vector);

void resize(Vector *vector);
void clear_vector(Vector *vector);
void push_back(Vector *vector, int value);
int pop_back(Vector *vector);
