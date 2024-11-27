#include <stdio.h>
#define S 50

int main() 
{
    int n, i;
    float x[S], y[S], sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0, a, b;

    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");
    
    // Input number of data points
    printf("Number of data points: ");
    scanf("%d", &n);

    // Input data points for X
    printf("Enter data X: ");
    for (i = 0; i < n; i++) 
    {
        scanf("%f", &x[i]); 
    }

    // Input data points for Y
    printf("Enter data Y: ");
    for (i = 0; i < n; i++) 
    {
        scanf("%f", &y[i]);
    }
    
    // Calculate sums for the normal equations
    for (i = 0; i < n; i++) 
    {
        sumX += x[i];
        sumX2 += x[i] * x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
    }

    // Display the normal equations
    printf("\nEquations in the form of a and b: \n");
    printf("%da + %.2fb = %.2f\n", n, sumX, sumY);
    printf("%.2fa + %.2fb = %.2f\n", sumX, sumX2, sumXY);

    // Augmented matrix for the system of equations
    float matrix[2][3] = {
        { n, sumX, sumY },
        { sumX, sumX2, sumXY }
    };

    // Applying Gauss-Jordan elimination
    for (i = 0; i < 2; i++) 
    {
        float divisor = matrix[i][i];
        for (int j = 0; j < 3; j++) 
        {
            matrix[i][j] /= divisor;
        }

        // Eliminate the current column from the other row
        for (int k = 0; k < 2; k++) 
        {
            if (k != i)
            {
                float factor = matrix[k][i];
                for (int j = 0; j < 3; j++) 
                {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }

    // Extracting the solution from the augmented matrix
    a = matrix[0][2];
    b = matrix[1][2];

    // Output the results
    printf("Values are: a = %.2f and b = %.2f\n", a, b);
    printf("Final obtained equation is: y = %.2f + %.2fx\n", a, b);

    return 0;
}
