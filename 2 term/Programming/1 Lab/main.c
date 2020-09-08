#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>


int convert(const char s[]) {
    // check-up naturality
    if (s[0] == '-') {
        printf("Error! Numbers do not natural\n");
        return -1;
    }
    
    int i = 0, sum = 0;
    while (s[i] != '\0' && s[i] != '\n' && s[i] != ' ' && sum < INT_MAX / 10 - 9) {
        if (s[i] <= '9' && s[i] >= '0') {
            sum = sum * 10 + (s[i] - '0');
            i++;
        } else {
    // check-up is it a number
            printf("Error! Should be a NUMBER!\n");
            return -1;
        }
    }
    return sum;
}


int power(int x, unsigned int y) {
    int temp;
    if (y == 0)
        return 1;
    
    temp = power (x, y / 2);
    if ((y % 2) == 0) {
        return temp * temp;
    } else {
        return x * temp * temp;
    }
}


int sizeOfNumber(int number){
    if (number < 10) {
        return 1;
    } else {
        return 1 + sizeOfNumber(number / 10);
    }
}


int rankDivision(int *k){
    int maxRank = *k / power(10, sizeOfNumber(*k)-1) * power(10, sizeOfNumber(*k)-1);
    *k -= maxRank;
    return maxRank;
}




// ================== main ==========================

int main(int argc, const char * argv[]) {
    
    int k = 0,l = 0,m;
    char numOne[10] = "";
    char numTwo[10] = "";
    
    
    printf("Enter two numbers\nYou should enter it in turn\nFirstly enter dividend, then divsor\nPress an enter after you put a num into:\n");
    fgets(numOne, 10, stdin);
    k = convert(numOne);
    
    fgets(numTwo, 10, stdin);
    l = convert(numTwo);
    
    
    // condition check-up
    if (k == -1 || l == -1) {
        return 0;
    }
    // division by zero
    if (l == 0) {
        printf("Error! Sorry, honey, but you should NOT divide by zero(0) \n\n");
        return 0;
    }
    // division evenly
    if (k % l != 0) {
        printf("Error! Numbers do not evenly devide :(\n\n");
        return 0;
    }
    
    
    
    int lenghtOfK = sizeOfNumber(k);
    m = k / l;    // division result
    
    // drawing!
    printf("%d | %d = %d\n", k, l, m);
    while (k != 0) {
        int temp = rankDivision(&m)*l;
        for (int i = 0; i < lenghtOfK - sizeOfNumber(temp); i++) {
            printf(" ");
        }
        printf("%d\n", temp);
        for (int i = 0; i < lenghtOfK; i++) printf("—");
        printf("\n");
        k -= temp;
        for (int i = 0; i < lenghtOfK - sizeOfNumber(k); i++) {
            printf(" ");
        }
        printf("%d\n", k);
    }
    
    return 0;
}
