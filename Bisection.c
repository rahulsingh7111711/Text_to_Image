#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x * x - 4 * x - 9;
}

void bisection(double a, double b, double tolerance) {
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval.\n");
        return;
    }

    double c = a;
    int iteration = 0;

    printf("Iteration\t x0\t\t x1\t\t x2\t\t f(x2)\n");
    printf("---------------------------------------------------------------------------\n");

    while ((b - a) >= tolerance) {
        c = (a + b) / 2;

        printf("%d\t\t %.5f\t %.5f\t %.5f\t %.5f\n", iteration + 1, a, b, c, f(c));

        if (fabs(f(c)) < tolerance) {
            break;
        }

        else if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
        iteration++;
    }

    printf("---------------------------------------------------------------------------\n");
    printf("The approximate root is = %.5f\n", c);
}

int main() {
    double a, b, tolerance;
    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");
    printf("Enter the first initial guess (x0): ");
    scanf("%lf", &a);
    printf("Enter the second initial guess (x1): ");
    scanf("%lf", &b);
    printf("Enter the tolerance value: ");
    scanf("%lf", &tolerance);

    bisection(a, b, tolerance);

    return 0;
}
//Approx answer is 2.706482
