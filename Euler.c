#include <stdio.h>
float f(float x, float y)
{
    return x + y;
}
void euler_method(float x0, float y0, float h, int n)
{
    float x = x0;
    float y = y0;
    printf("%-10s%-10s\n", "x", "y");
    for (int i = 0; i <= n; i++)
    {
        printf("x%d = %-10.4f y%d = %-10.4f\n", i, x, i, y);
        y = y + h * f(x, y);
        x = x + h;
    }
}
int main()
{
    float x0, y0, h;
    int n;
    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");
    printf("Enter the initial value of x (x0): ");
    scanf("%f", &x0);
    printf("Enter the initial value of y (y0): ");
    scanf("%f", &y0);
    printf("Enter the final value of x (xn): ");
    float xn;
    scanf("%f", &xn);
    printf("Enter the number of steps (n): ");
    scanf("%d", &n);
    h = (xn - x0) / n;
    printf("Calculated step size (h): %.4f\n", h);
    euler_method(x0, y0, h, n);
    return 0;
}
