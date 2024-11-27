#include <stdio.h>

double f(double x, double y) 
{ 
    return x + y; 
} 

int main() 
{ 
    double x0, y0, x_end, h; 
    int n, i; 
    
    // Print user details
    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");
    
    // Take input from the user
    printf("Enter initial value of x0: "); 
    scanf("%lf", &x0); 
    printf("Enter initial value of y0: "); 
    scanf("%lf", &y0); 
    printf("Enter the end value of x: "); 
    scanf("%lf", &x_end); 
    printf("Enter the number of intervals n: "); 
    scanf("%d", &n); 
    
    // Calculate step size
    h = (x_end - x0) / n; 
    
    // Print header for table of results
    printf("     x   |      y    \n");
    
    double x = x0; 
    double y = y0; 
    
    // Print the initial values
    printf("%6.4f | %6.4f\n", x, y); 
    
    // Apply Euler's method and print the values of x and y
    for (i = 1; i <= n; i++) 
    { 
        y = y + h * f(x, y); 
        x = x + h;  
        printf("%6.4f | %6.4f\n", x, y); 
    } 
    
    // Print the final approximate value of y
    printf("Approximate value of y at x = %.2f is: %.6f\n", x_end, y); 

    return 0; 
}
