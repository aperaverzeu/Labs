#include <stdio.h>
#include <stdbool.h>
#include "MyString.h"

bool issame(string x, string y){
    if (length(&x) != length(&y)) return false;
    for (int i = 0; i < length(&x); i++)
        if (x.mybuf[i] != y.mybuf[i] && x.mybuf[i] != ' ' && x.mybuf[i] != '_') return false;
    return true;
}

int main() {
    FILE * file = fopen("input.txt", "r");
    string str;
    int amount = 11;
    printf("Enter word : ");
    scanf("%s", str.mybuf);

    
    string* dict = calloc(amount, sizeof(string));
    set_length(dict, amount);
    printf("Result: \n");
    for (int i = 0; i < amount; ++i) {
        read_from(file);
        fscanf(file, "%s", dict[i].mybuf);
        if (issame(str,*dict)) printf("%s", dict[i].mybuf);
    }
    return 0;
}
