#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void init(String *string) {
    string->size = 0;
    string->capacity = VECTOR_INITIAL_CAPACITY;
    string->data = malloc(sizeof(int) * string->capacity);
    if(!string->data) exit(1);
}

void checkOutOfRange(String *string, int index) {
    if(index >= string->size || index < 0) {
        printf("Index %d out of bounds for vector of size %d\n", index, string->size);
        exit(1);
    }
}

char get(String *string, int index) {
    checkOutOfRange(string, index);
    return string->data[index];
}

void set(String *string, int index, char value) {
    while(index >= string->size) {
        push_back(string, 0);
    }
    checkOutOfRange(string, index);
    
    string->data[index] = value;
}

bool empty(String *string) {
    return string->size == 0;
}

int size(String *string) {
    return string->size;
}

int capacity(String *string) {
    return string->capacity;
}

void resize(String *string) {
    if(string->size + 1 >= string->capacity) {
        string->capacity *= 2;
        string->data = realloc(string->data, sizeof(int) * string->capacity);
        if(!string->data) exit(1);
    }
}

void sort_vector(String *vector) {
    
}

void clear_string(String *string) {
    while(size(string)) {
        pop_back(string);
    }
}

void push_back(String *string, int value) {
    resize(string);
    
    string->data[string->size] = value;
    string->size += 1;
}

char pop_back(String *string) {
    checkOutOfRange(string, string->size - 1);
    char data = string->data[string->size - 1];
    set(string, string->size - 1, 0);
    string->size -= 1;
    return data;
}

char back(String *string) {
    checkOutOfRange(string, string->size - 1);
    return string->data[string->size - 1];
}

char front(String *string) {
    checkOutOfRange(string, 0);
    return string->data[0];
}
