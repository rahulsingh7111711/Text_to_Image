#include <stdio.h>

int main() {
    int i, j, k, n;
    float A[20][20], c, x[10], sum = 0.0;
    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");
    printf("Enter the order of matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of augmented matrix row-wise:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= (n + 1); j++) {
            printf("A[%d][%d] : ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    // Forward elimination to obtain RREF
    for (j = 1; j <= n; j++) {
        // Normalize the pivot row
        float pivot = A[j][j];
        for (k = 1; k <= n + 1; k++) {
            A[j][k] /= pivot;  // Make the pivot equal to 1
        }

        // Eliminate column entries above and below the pivot
        for (i = 1; i <= n; i++) {
            if (i != j) {
                c = A[i][j];  // Get the current entry to eliminate
                for (k = 1; k <= n + 1; k++) {
                    A[i][k] -= c * A[j][k];  // Subtract the scaled pivot row
                }
            }
        }

        // Print the intermediate matrix after each elimination step
        printf("\nAfter processing column %d:\n", j);
        for (int row = 1; row <= n; row++) {
            for (int col = 1; col <= n + 1; col++) {
                printf("%6.2f ", A[row][col]);
            }
            printf("\n");
        }
    }

    // Print the final reduced row echelon form
    printf("\nIdentity Form:\n");
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n + 1; col++) {
            printf("%6.2f ", A[row][col]);
        }
        printf("\n");
    }

    // Extract solutions (if needed)
    for (i = 1; i <= n; i++) {
        x[i] = A[i][n + 1];  // Since A[i][n + 1] is now the solution
    }

    printf("\nThe solution is:\n");
    for (i = 1; i <= n; i++) {
        printf("x%d = %.2f\t", i, x[i]);
    }
    printf("\n");

    return 0;
}
