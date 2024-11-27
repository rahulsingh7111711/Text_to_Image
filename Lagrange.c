#include <stdio.h> 
#define MAX_SIZE 100 

int main() 
{ 
    int n; 
    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");
    printf("Enter number of terms: "); 
    scanf("%d", &n); 

    if (n > MAX_SIZE) 
    { 
        printf("The number of terms exceeds the maximum allowed size.\n"); 
        return 1; 
    } 
    
    double X[MAX_SIZE], Y[MAX_SIZE], x, sum = 0, term; 
    int i, j; 

    printf("Enter values of X:\n"); 
    for (i = 0; i < n; i++) 
    { 
        scanf("%lf", &X[i]); 
    } 
    
    printf("Enter values of Y:\n"); 
    for (i = 0; i < n; i++) 
    { 
        scanf("%lf", &Y[i]); 
    } 
    
    printf("Enter the value of x for which you want y: "); 
    scanf("%lf", &x); 
    
    for (i = 0; i < n; i++) 
    { 
        term = 1; 
        for (j = 0; j < n; j++) 
        { 
            if (i != j) 
            { 
                term *= (x - X[j]) / (X[i] - X[j]); 
            } 
        } 
        sum += term * Y[i]; 
    } 
    
    printf("\nValue at X = %lf is Y = %lf\n", x, sum); 
    
    return 0;
}
