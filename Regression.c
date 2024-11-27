#include <stdio.h>

int main() {
    int n;
    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");
    
    // Input the number of data points
    printf("Enter the number of data points (n): ");
    scanf("%d", &n);
    
    // Declare arrays for x and y values
    double x[n], y[n];
    
    // Input the x values
    printf("Enter the x values separated by spaces: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }
    
    // Input the y values
    printf("Enter the y values separated by spaces: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
    }
    
    // Initialize summation variables
    double sum_x = 0, sum_y = 0, sum_x_squared = 0, sum_xy = 0;
    
    // Calculate summations
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_x_squared += x[i] * x[i];
        sum_xy += x[i] * y[i];
    }
    
    // Calculate mean values
    double xbar = sum_x / n, ybar = sum_y / n;
    
    // Calculate the slope (m) and intercept (c)
    double m = (n * sum_xy - sum_x * sum_y) / (n * sum_x_squared - sum_x * sum_x);
    double c = ybar - m * xbar;
    
    // Print the table of calculations
    printf("\nTable of Calculations:\n");
    printf("x\t y\t x^2\t xy\n");
    for (int i = 0; i < n; i++) {
        printf("%.2lf\t %.2lf\t %.2lf\t %.2lf\n", x[i], y[i], x[i]*x[i], x[i]*y[i]);
    }
    
    // Print the regression equation
    printf("\nThe regression line equation is: y = %.2lfx + %.2lf\n", m, c);
    
    return 0;
}

