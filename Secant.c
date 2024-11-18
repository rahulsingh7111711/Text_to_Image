#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x * x - 4 * x - 9;
}

void secant(double x0, double x1, double tolerance, int max_iterations) {
    double x2;
    int iteration = 0;

    printf("Iteration\t x0\t\t x1\t\t x2\n");
    printf("------------------------------------------------------------\n");

    while (iteration < max_iterations) {
        x2 = ((x0*f(x1)) - (x1* f(x0))) / (f(x1) - f(x0));

        printf("%d\t\t %.5f\t %.5f\t %.5f\n", iteration + 1, x0, x1, x2);

        if (fabs(f(x2)) < tolerance) {
            break;
        }

        x0 = x1;
        x1 = x2;
        iteration++;
    }

    printf("------------------------------------------------------------\n");
    printf("The approximate root is = %.5f\n", x2);
}

int main() {
    double x0, x1, tolerance;
    int max_iterations;
    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");
    printf("Enter the first initial guess (x0): ");
    scanf("%lf", &x0);
    printf("Enter the second initial guess (x1): ");
    scanf("%lf", &x1);
    printf("Enter the tolerance value: ");
    scanf("%lf", &tolerance);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    secant(x0, x1, tolerance, max_iterations);
    return 0;
}
