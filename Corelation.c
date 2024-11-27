#include <stdio.h>
#include <math.h>

int main() {
    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");
    
    int n, i;
    double x[100], y[100];
    double sum_x = 0, sum_y = 0, x_mean, y_mean;
    double numerator = 0, denominator_x = 0, denominator_y = 0, r;

    // Input the number of data points
    printf("Enter the number of data points (n): ");
    scanf("%d", &n);

    // Input the values for x
    printf("Enter the values for x:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
        sum_x += x[i];
    }

    // Input the values for y
    printf("Enter the values for y:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
        sum_y += y[i];
    }

    // Calculate the means of x and y
    x_mean = sum_x / n;
    y_mean = sum_y / n;

    // Print the table of values and calculations
    printf("\n%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", 
           "x", "y", "(x-x')", "(y-y')", "(x-x')^2", "(y-y')^2", "(x-x')*(y-y')");
    for (i = 0; i < n; i++) {
        double x_diff = x[i] - x_mean;
        double y_diff = y[i] - y_mean;
        double x_diff_sq = x_diff * x_diff;
        double y_diff_sq = y_diff * y_diff;
        double product = x_diff * y_diff;

        numerator += product;
        denominator_x += x_diff_sq;
        denominator_y += y_diff_sq;

        // Displaying each step's calculation
        printf("%-10.2f %-10.2f %-10.2f %-10.2f %-10.2f %-10.2f %-10.2f\n", 
               x[i], y[i], x_diff, y_diff, x_diff_sq, y_diff_sq, product);
    }

    // Calculate Pearson correlation coefficient (r)
    r = numerator / sqrt(denominator_x * denominator_y);

    // Display Pearson correlation coefficient
    printf("\nPearson correlation coefficient (r): %.2f\n", r);

    // Interpret the correlation
    if (r > 0) {
        printf("The correlation is positive.\n");
    } else if (r < 0) {
        printf("The correlation is negative.\n");
    } else {
        printf("There is no correlation.\n");
    }

    // Check the strength of the correlation
    if (fabs(r) > 0.5) {
        printf("There is a strong correlation.\n");
    } else {
        printf("There is a weak correlation.\n");
    }

    return 0;
}

