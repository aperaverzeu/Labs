#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void init(Vector *vector) {
    vector->size = 0;
    vector->capacity = VECTOR_INITIAL_CAPACITY;
    vector->data = malloc(sizeof(int) * vector->capacity);
    if(!vector->data) exit(1);
}

void checkOutOfRange(Vector *vector, int index) {
    if(index >= vector->size || index < 0) {
        printf("Index %d out of bounds for vector of size %d\n", index, vector->size);
        exit(1);
    }
}

int get(Vector *vector, int index) {
    checkOutOfRange(vector, index);
    return vector->data[index];
}

void set(Vector *vector, int index, int value) {
    while(index >= vector->size) {
        push_back(vector, 0);
    }
    checkOutOfRange(vector, index);
    
    vector->data[index] = value;
}

bool empty(Vector *vector) {
    return vector->size == 0;
}

int size(Vector *vector) {
    return vector->size;
}

int capacity(Vector *vector) {
    return vector->capacity;
}

void resize(Vector *vector) {
    if(vector->size + 1 >= vector->capacity) {
        vector->capacity *= 2;
        vector->data = realloc(vector->data, sizeof(int) * vector->capacity);
        if(!vector->data) exit(1);
    }
}

void sort_vector(Vector *vector) {
    
}

void clear_vector(Vector *vector) {
    while(size(vector)) {
        pop_back(vector);
    }
}

void push_back(Vector *vector, int value) {
    resize(vector);
    
    vector->data[vector->size] = value;
    vector->size += 1;
}

int pop_back(Vector *vector) {
    checkOutOfRange(vector, vector->size - 1);
    int data = vector->data[vector->size - 1];
    set(vector, vector->size - 1, 0);
    vector->size -= 1;
    return data;
}

int back(Vector *vector) {
    checkOutOfRange(vector, vector->size - 1);
    return vector->data[vector->size - 1];
}

int front(Vector *vector) {
    checkOutOfRange(vector, 0);
    return vector->data[0];
}
