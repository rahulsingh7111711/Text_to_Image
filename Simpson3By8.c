#include <stdio.h> 
#include <math.h> 

// Function to compute f(x)
double f(double x) { 
    return 1.0 / (1.0 + x * x); 
}

// Simpson's 3/8 Rule
double simpson38(double a, double b, int n) { 
    // Ensure n is a multiple of 3
    if (n % 3 != 0) { 
        n += (3 - n % 3);  // Adjust n to the next multiple of 3
    } 

    double h = (b - a) / n;  // Step size
    double sum = f(a) + f(b);  // Add f(a) and f(b) to sum

    printf("\nSimpson's 3/8 Rule:\n");
    
    // Loop over each subinterval
    for (int i = 1; i < n; i++) { 
        double x = a + i * h;  // Compute x_i
        double y = f(x);  // Compute f(x)
        
        // Apply Simpson's 3/8 Rule (weight 3 for all, except for multiples of 3, which get weight 2)
        if (i % 3 == 0) { 
            sum += 2 * y;  // Weight 2 for every third interval
        } else { 
            sum += 3 * y;  // Weight 3 for other intervals
        }

        // Print intermediate x and f(x) values
        printf("x: %.4f, y: %.4f\n", x, y); 
    } 

    return sum * (3 * h / 8);  // Return the result of the approximation
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

    // Compute the result using Simpson's 3/8 rule
    double result = simpson38(a, b, n); 

    // Display the final result
    printf("\nFinal value using Simpson's 3/8 Rule: %.4f\n", result); 
    
    return 0; 
}
