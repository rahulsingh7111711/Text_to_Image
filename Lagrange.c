#include <stdio.h>
double lagrangeInterpolation(double x[], double y[], int n, double target)
{
    double result = 0.0;
    for (int i = 0; i < n; i++)
    {
        double term = y[i];
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                term *= (target - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}

int main()
{
    int n;
    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");
    printf("Enter the number of points: ");
    scanf("%d", &n);
    double x[n], y[n];
    printf("Enter the values of x and y:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
    }
    double k;
    printf("Enter the value of x to calculate y for : ");
    scanf("%lf", &k);
    int isUniform = 1;
    for (int i = 1; i < n; i++)
    {
        if (x[i] != x[0])
        {
            isUniform = 0;
            break;
        }
    }
    double result = lagrangeInterpolation(x, y, n, k);
    printf("The value of y at x = %.2lf is %.5lf\n", k, result);
    return 0;
}
