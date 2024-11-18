#include <stdio.h>

#define MAX 20  // Define maximum number of terms

int main() {
    float x, y, h, u, u1;
    int i, j, n, fact;

    // Declare arrays to store X and Y values and difference table
    float a[MAX][MAX];
    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");
    // Input number of terms (n)
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Check if n exceeds the maximum allowed size
    if (n > MAX) {
        printf("Number of terms exceeds the allowed limit of %d.\n", MAX);
        return 1;
    }

    // Input X values
    printf("Enter values of X:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &a[i][0]);
    }

    // Input Y values
    printf("Enter values of Y:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &a[i][1]);
    }

    // Input x for which we need to find y
    printf("Enter the value of x for which you want y: ");
    scanf("%f", &x);

    // Calculate h and check for equally spaced X values
    h = a[1][0] - a[0][0];
    for (i = 1; i < n; i++) {
        if (a[i][0] - a[i-1][0] != h) {
            printf("Cannot perform Newton Forward Interpolation as X values are not equally spaced.\n");
            return 1;
        }
    }

    // Construct the forward difference table
    for (j = 2; j <= n; j++) {
        for (i = 0; i < n - j + 1; i++) {
            a[i][j] = a[i + 1][j - 1] - a[i][j - 1];
        }
    }

    // Print the forward difference table
    printf("The Difference Table is as follows:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n - i; j++) {
            printf("%.4f ", a[i][j]);
        }
        printf("\n");
    }

    // Compute u = (x - X0) / h
    u = (x - a[0][0]) / h;
    y = a[0][1];  // Start with y = Y0
    u1 = u;
    fact = 1;

    // Apply Newton's Forward Interpolation formula
    for (i = 2; i <= n; i++) {
        y += (u1 * a[0][i]) / fact;

        fact *= i;  // Calculate factorial iteratively
        u1 *= (u - (i - 1));  // Calculate u terms iteratively
    }

    printf("\nValue at X = %.2f is %.4f\n", x, y);

    return 0;
}
