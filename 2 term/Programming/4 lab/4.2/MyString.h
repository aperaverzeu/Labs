#ifndef SECONDCLION_MYSTRING_H
#define SECONDCLION_MYSTRING_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string_t;

typedef struct str_node {
    struct str_node* next;
    struct string_t* mystr;
} s_node;
s_node* head = NULL;

typedef struct string_t {
    char*  mybuf;
    size_t mycap;
    struct string_t * next;
} string;

string* new_string();
static void fstr(string* str);
void free_strings();
size_t length(string* str);
void ensure_capacity(string* str, size_t cap);
void trim(string* str, size_t len);
void set_length(string* str, size_t len);
string* set(string* str, const char* value);
string* append(string* str, const char* value);
string* substring(string* str, size_t idx, size_t len);
void shrink_to_fit(string* str);
string* read_from_n(FILE* stream, size_t bufsize);
string* read_from(FILE* stream);
#endif //SECONDCLION_MYSTRING_H
