#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** init(int size) {
    // array initialization
    int** array;
    array = (int**)malloc(size*sizeof(int*));
    for (int i = 0; i < size; i++) {
        array[i] = (int*)malloc(size*sizeof(int));
    }
    
    time_t t;;
    srand((unsigned) time(&t));
    
    // array value initialiaziton
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            array[i][j] = rand() % 100;
        }
    }
     return array;
}

void show(int** array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
}

void mirror(int** array, int size) {
    int ** mirror = NULL;
    mirror = (int**)malloc(size*sizeof(int*));
    for (int i = 0; i < size; i++) {
        mirror[i] = (int*)malloc(size*sizeof(int));
    }
    
    
    for(int i=0; i<size; i++) {
       for(int j=0; j<size; j++) {
          int ii = size - 1 - i;
          int jj = size - 1 - j;
          mirror[i][j]=array[ii][jj];
       }
    }
    
    printf("Final array:\n");
    show(mirror, size);
}

void findAndDelete(int** array, int size) {
    int maxElement = 0;
    int deltaI = 0, deltaJ = 0;
    int indexI = 0, indexJ = 0;
    // find max value element
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (maxElement < array[i][j]) {
                maxElement = array[i][j];
                indexI = i;
                indexJ = j;
            }
        }
    }
    
    
    int** newArray = NULL;
    newArray = (int**)malloc((size-1)*sizeof(int*));
    for (int i = 0; i < size-1; i++) {
        newArray[i] = (int*)malloc((size-1)*sizeof(int));
    }
    
    // algorithm
    for (int i = 0; i < size; i++) {
        deltaJ = 0;
        if (i==indexI) {
            deltaI = 1;
            continue;
        }
        for (int j = 0; j < size; j++) {
            if (j == indexJ) {
                deltaJ = 1;
                continue;
            }
            newArray[i-deltaI][j-deltaJ] = array[i][j];
        }
    }
    
    show(newArray, size-1);
    printf("\n");
    
    mirror(newArray, size-1);
    
    array = newArray;
    
}

void cleaning(int** array, int size) {
   for(int i = 0; i < size; i++) {
       free(array[i]);
   }
    free(array);
}

int main(int argc, const char * argv[]) {
    int **array = NULL;
    int size = 0;
    
    // size initialization
    printf("Enter size of array:\t");
    scanf("%d", &size);
    
    // size validation
    while (size <= 0) {
        printf("Enter a valid value of size of the array:\t");
        scanf("%d", &size);
    }
    
    array = init(size);
    
    printf("Initial array:\n");
    show(array, size);
    printf("\n");
    
    printf("Find and Delete:\n");
    findAndDelete(array, size);
    
//    printf("Final array:\n\n");
//    mirror(array, size);

    
    // free memory
    cleaning(array, size);
    return 0;
}
