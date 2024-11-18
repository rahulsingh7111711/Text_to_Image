#include <stdio.h>
#include <math.h>
float f(float x)
{
    return 1 / (1 + x * x);
}

int main()
{
    float a, b, n, h, integral = 0.0;
    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");
    printf("Enter the value of a = ");
    scanf("%f", &a);
    printf("Enter the value of b = ");
    scanf("%f", &b);
    printf("Enter the value of sub-intervals = ");
    scanf("%f", &n);
    h = (b - a) / n;
    printf("\n%-10s %-10s\n", "x", "f(x)");
    for (int i = 0; i <= n; i++)
    {
        float x = a + i * h;
        float y = f(x);
        printf("%-10.2f %-10.2f\n", x, y);
        if (i == 0 || i == n)
        {
            integral += y;
        }
        else
        {
            integral += 2 * y;
        }
    }
    integral = (h / 2) * integral;
    printf("\nThe final value of the integral is: %.4f\n", integral);
    return 0;
}
