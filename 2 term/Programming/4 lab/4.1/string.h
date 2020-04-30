#include <stdio.h>
#include <stdbool.h>
#define VECTOR_INITIAL_CAPACITY 1

typedef struct {
    char size;
    char capacity;
    char *data;
} String;

void init(String *string);
char get(String *string, int index);
void set(String *string, int index, char value);

bool empty(String *string);
int size(String *string);
int capacity(String *string);

void resize(String *string);
void clear_string(String *string);
void push_back(String *string, int value);
char pop_back(String *string);
