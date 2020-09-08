#include "MyString.h"

string* new_string() {
    string* str = malloc(sizeof(string));
    str->mybuf = NULL;
    str->mycap = 0;

    s_node** nptr = &head;
    while ((*nptr) != NULL) {
        nptr = &((*nptr)->next);
    }
    (*nptr) = malloc(sizeof(s_node));
    (*nptr)->mystr = str;
    (*nptr)->next = NULL;
    return str;
}

static void fstr(string* str) {
    if (str->mybuf != NULL) {
        free(str->mybuf);
    }
    if (str != NULL) {
        free(str);
    }
}

void free_strings() {
    s_node* nptr = head;
    while (nptr != NULL) {

        fstr(nptr->mystr);
        s_node* next = nptr->next;
        free(nptr);
        nptr = next;
    }
}

size_t length(string* str) {
    return ((str->mybuf == NULL) ? (0) : (strlen(str->mybuf)));
}

void ensure_capacity(string* str, size_t cap) {
    if (str->mybuf == NULL) {
        str->mybuf = malloc(cap);
        str->mycap = cap;
    }
    else if (str->mycap < cap) {
        str->mybuf = realloc(str->mybuf, cap);
        str->mycap = cap;
    }
}

void trim(string* str, size_t len) {
    if (length(str) > len) {
        memset(str->mybuf + len, 0, 1);
    }
}

void set_length(string* str, size_t len) {
    ensure_capacity(str, len + 1);
    trim(str, len);
}

string* set(string* str, const char* value) {
    set_length(str, strlen(value));
    strcpy(str->mybuf, value);
    return (str);
}

string* append(string* str, const char* value) {
    set_length(str, strlen(value) + length(str));
    strcat(str->mybuf, value);
    return (str);
}

string* substring(string* str, size_t idx, size_t len) {
    string *substr = new_string();
    set(substr, str->mybuf + idx);
    trim(substr, len);
    return (substr);
}

void shrink_to_fit(string* str) {
    size_t len = length(str) + 1;
    if (len < str->mycap) {
        str->mybuf = realloc(str->mybuf, len);
        str->mycap = len;
    }
}

string* read_from_n(FILE* stream, size_t bufsize) {
    string* buf = new_string();
    ensure_capacity(buf, bufsize);
    fgets(buf->mybuf, bufsize, stream);
    shrink_to_fit(buf);
}

#define DEFAULT_READ_BUFFER_SIZE 1024

string* read_from(FILE* stream) {
    return (read_from_n(stream, DEFAULT_READ_BUFFER_SIZE));
}