#include <stdio.h> 
#include <math.h> 

// Function to compute f(x)
double f(double x) { 
    return 1.0 / (1.0 + x * x); 
}

// Simpson's 1/3 Rule
double simpson13(double a, double b, int n) { 
    // Ensure n is even
    if (n % 2 != 0) { 
        n++;  // If n is odd, increment it
    } 

    double h = (b - a) / n;  // Step size
    double sum = f(a) + f(b);  // Add f(a) and f(b) to sum

    printf("\nSimpson's 1/3 Rule:\n");
    
    // Loop over each subinterval
    for (int i = 1; i < n; i++) { 
        double x = a + i * h;  // Compute x_i
        double y = f(x);  // Compute f(x)
        
        // Apply Simpson's Rule (weight 4 for odd, 2 for even)
        if (i % 2 == 0) { 
            sum += 2 * y;  // Even index: weight 2
        } else { 
            sum += 4 * y;  // Odd index: weight 4
        }

        // Print intermediate x and f(x) values
        printf("x: %.4f, y: %.4f\n", x, y); 
    } 

    return sum * (h / 3);  // Return the result of the approximation
}

int main() { 
    double a, b;  // Lower and upper limits of integration
    int n;  // Number of subintervals

    // User details
    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");

    // User input for the limits and number of intervals
    printf("Enter lower limit (a): "); 
    scanf("%lf", &a); 
    printf("Enter upper limit (b): "); 
    scanf("%lf", &b); 
    printf("Enter number of intervals (n): "); 
    scanf("%d", &n); 

    double result = simpson13(a, b, n); 

    printf("\nFinal value using Simpson's 1/3 Rule: %.4f\n", result); 
    
    return 0; 
}
