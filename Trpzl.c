#include <stdio.h>  
#include <math.h>     
double  f(double x) {  
    return 1.0 / (1.0 + x * x);    
} 
double trapezoidal_rule(double (*f)(double), double a, double b, int n) {       
    double h = (b - a) / n; 
    double sum = 0.5 * (f(a) + f(b));       
    printf("|   x   |   f(x)   |\n");   
    printf("| %.6lf | %.6lf |\n", a, f(a));     
    for (int i = 1; i < n; i++) {         
        double x_i = a + i * h;          
        printf("| %.6lf | %.6lf |\n", x_i, f(x_i));         
        sum += f(x_i);  
    }      
    printf("| %.6lf | %.6lf |\n", b, f(b));      
    return sum * h;   
}  
int main() {     
    double a, b;       
    int n;        
    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");         
    printf("Enter the lower limit of integration (a): ");     
    scanf("%lf", &a);  
    printf("Enter the upper limit of integration (b): ");      
    scanf("%lf", &b);  
    printf("Enter the number of subintervals (n): ");     
    scanf("%d", &n);  
    double result = trapezoidal_rule(f, a, b, n);  
    printf("\nThe approximate value of the integral is: %.6lf\n", result);  
    return 0;  
}
