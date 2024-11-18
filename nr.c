#include <stdio.h>
#include <math.h>

double f(double x) {
    return (x * x * x) - 4 * x - 9; 
}

double df(double x) {
    return 3 * x * x - 4; 
}

void nr(double x0, double e) {
    double n;
    int i = 0;

    printf("Iteration\t x0\t\t x1\t\t f(x0)\n");
    printf("---------------------------------------------------------\n");

    while (fabs(f(x0)) > e) { 
        n = x0 - f(x0) / df(x0);

        printf("%d\t\t %.5f\t %.5f\t %.5f\n", i + 1, x0, n, f(x0)); 

        if (fabs(n - x0) < e) { 
            break;
        }

        x0 = n;
        i++;
    }

    printf("---------------------------------------------------------\n");
    printf("Final root is: %.5f\n", x0); 
}

int main() {
    double x0, e;
    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");
    printf("Enter the initial guess (x0): ");
    scanf("%lf", &x0);
    printf("Enter the tolerance value: ");
    scanf("%lf", &e);

    nr(x0, e);

    return 0;
}
