#include <stdio.h>
#include "vector.h"

void show (Vector *v) {
    int d = v->size-1;
    int i;
    for(i = 0; i < v->size; i++) {
        printf("%d", get(v, i));
        if (i < d) {
            printf("   ");
        }
    }
    printf("\n");
}

void rotate (Vector *v, int shift) {
    shift %= v->size;
    int j;
    for(j = 0; j < shift; j++) {
        int tmp = get(v, 0);
        int k;
        for(k = 0; k < v->size - 1; k++) {
            set(v, k, get(v, k + 1));
        }
        set(v, v->size - 1, tmp);
    }
}
 
int main (void) {
//    int array[size];
    int size = 5;
    int shift;
    
    Vector vector;
    init(&vector);
    
    printf("Enter shift of array:\t");
    scanf("%d", &shift);
    while (shift <= 0) {
        printf("Enter a valid value:\t");
        scanf("%d", &shift);
    }
    
    for (int i = 0; i < size; i++) {
        set(&vector, i, i+1);
    }
    
    show(&vector);
    printf("\n");
    
    rotate(&vector, shift);
    show(&vector);
    printf("\n");
    
    return 0;
}
