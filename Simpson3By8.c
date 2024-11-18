#include <stdio.h>
#include <math.h>
double f(double x)
{
    return 1 / (1 + x * x);
}
double simpsons_38(double a, double b, int n)
{
    if (n % 3 != 0)
    {
        printf("Number of intervals must be a multiple of 3.\n");
        return -1;
    }
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    printf("\nTable of values:\n");
    printf("    x         f(x)    \n");
    printf(" %7.4lf  %10.6lf \n", a, f(a));
    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        if (i % 3 == 0)
        {
            sum += 2 * f(x);
        }
        else
        {
            sum += 3 * f(x);
        }
        printf(" %7.4lf  %10.6lf \n", x, f(x));
    }
    printf(" %7.4lf  %10.6lf \n", b, f(b));
    return (3 * h / 8) * sum;
}
int main()
{
    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");
    double a, b;
    int n;
    printf("Enter the value of a (lower limit) = ");
    scanf("%lf", &a);
    printf("Enter the value of b (upper limit) = ");
    scanf("%lf", &b);
    printf("Enter the value of n (number of sub-intervals) = ");
    scanf("%d", &n);
    double result = simpsons_38(a, b, n);
    if (result != -1)
    {
        printf("\nThe final value of the integral is: %lf\n", result);
    }
}
