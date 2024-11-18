#include <stdio.h>
#include <math.h>
float f(float x, float y)
{
    float m;
    m = (x * x) + (y * y);
    return m;
}
int main()
{
    float x0, y0, m1, m2, m3, m4, m, y, x, h, xn;
    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");
    printf("Enter x0,y0,xn:");
    scanf("%f %f %f ", &x0, &y0, &xn);
    h = xn - x0;
    x = x0;
    y = y0;
    while (x < xn)
    {
        m1 = h * f(x0, y0);
        printf("k1=%f\n", m1);
        m2 = h * f((x0 + h / 2.0), (y0 + m1 / 2.0));
        printf("k2=%f\n", m2);
        m3 = h * f((x0 + h / 2.0), (y0 + m2 / 2.0));
        printf("k3=%f\n", m3);
        m4 = h * f((x0 + h), (y0 + m3));
        printf("k4=%f\n", m4);
        m = ((m1 + 2 * m2 + 2 * m3 + m4) / 6);
        printf("k=%f\n", m);
        y = y + m;
        x = x + h;
        printf("x=%f\ty=%f\n", x, y);
    }
}
