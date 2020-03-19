#include <stdio.h>
#include <math.h>

// #define __LDBL_MAX__ 1.79769313486231580793728971405301e+308L

long double fact(int n) {
    if(n > 20)
        return __LDBL_MAX__;
    if(n == 0)
        return 1;
    return n * fact(n - 1);
}

double rec(double x, double e, int i, double sum) {
    if(fabs(sum - sin(x)) < e) {
        return sum;
    }
    
    sum += pow(x, 2 * (i) - 1) / fact(2 * (i) - 1) * (((i) - 1) % 2 == 0 ? 1 : -1);
    i++;
    
    return rec(x, e, i, sum);
}

int main(){
    double x, e, sum = 0;
    
    printf("Введите х и е: \n");
    scanf("%lf %lf", &x, &e);
    
    x = fmod(x, 2 * acos(-1));
    
    printf(" sin(x) = %lf\n", sin(x));
    
    
    int i = 1;
    for (i = 1; fabs(sum - sin(x)) > e; i++) {
        sum += pow(x, 2 * i - 1) / fact(2 * i - 1) * ((i - 1) % 2 == 0 ? 1 : -1);
    }
    printf("Результат работы цикла:\n sin(x) = %lf, n = %d\n", sum, i);
    
    
    i = 1;
    sum = rec(x, e, i, 0);
    printf("Результат работы рекурсии:\n sin(x) = %lf, n = %d\n", sum, i);
    
    return 0;
}
