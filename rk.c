#include <stdio.h>

double f(double x, double y) 
{ 
    double m; 
    m = (x * x) + (y * y); 
    return m; 
}

int main() 
{ 
    double x0, y0, k1, k2, k3, k4, delta, y, x, xn, n, h; 
    
    // User Details
    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");
    printf("y' = f(x, y) = x^2 + y^2 given.\n"); 
    
    // Input values
    printf("Enter initial value for x (x_0): "); 
    scanf("%lf", &x0); 
    printf("Enter initial value for y (y_0): "); 
    scanf("%lf", &y0); 
    printf("Enter the value of x at which y is required (x_n): "); 
    scanf("%lf", &xn); 
    printf("Enter the number of intervals (n): "); 
    scanf("%lf", &n); 
    
    // Calculate step size
    h = (xn - x0) / n; 
    
    // Initialize variables
    x = x0; 
    y = y0; 
    
    // Print header for result table
    printf("x\t\tk1\t\tk2\t\tk3\t\tk4\t\ty\n"); 
    printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", x, 0.0, 0.0, 0.0, 0.0, y); 
    
    // Runge-Kutta iteration
    while (x < xn) 
    { 
        k1 = h * f(x, y); 
        k2 = h * f((x + h / 2.0), (y + k1 / 2.0)); 
        k3 = h * f((x + h / 2.0), (y + k2 / 2.0)); 
        k4 = h * f((x + h), (y + k3)); 
        delta = (k1 + 2 * k2 + 2 * k3 + k4) / 6.0; 
        y = y + delta; 
        x = x + h; 
        
        // Print each step's result
        printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", x, k1, k2, k3, k4, y); 
    } 
    
    // Final result
    printf("f(%lf) = %lf\n", xn, y); 
    
    return 0; 
}
