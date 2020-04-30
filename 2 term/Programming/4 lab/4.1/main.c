#include <stdio.h>
#include <string.h>

char* add_string_numbers(char * first, char * second, char * dest, int dest_len) {
    char * res = dest + dest_len - 1;
    *res = 0;

    if ( ! *first && ! *second ) {
        puts("Those numbers are less than nothing");
        return 0;
    }

    unsigned long first_len = strlen(first);
    unsigned long second_len = strlen(second);

    if ( ((first_len+2) > dest_len) || ((second_len+2) > dest_len) ) {
        puts("Possibly not enough space on destination buffer");
        return 0;
    }

    char *first_back = first+first_len;
    char *second_back = second+second_len;

    char sum;
    char carry = 0;

    while ( (first_back > first) || (second_back > second) ) {
        sum = ((first_back  > first)  ? *(--first_back) : '0')
            + ((second_back > second) ? *(--second_back) : '0')
            + carry - '0';

        carry = sum > '9';
        if ( carry ) {
            sum -= 10;
        }

        if ( sum > '9' ) {
            sum = '0';
            carry = 1;
        }

        *(--res) = sum;
    }

    if ( carry ) {
        *(--res) = '1';
    }

    return res;
}

int main(int argc, char** argv) {
    char * a = "987429247594";
    char * b = "739527";
    char r[100] = {0};

    char * res = add_string_numbers(a,b,r,sizeof(r));

    printf("%s + %s = %s\n", a, b, res);

    return (0);
}
