#include <stdio.h>
void gaussJordan(float a[2][3], int n) 
{
    float ratio;
    for(int i = 0; i < n; i++) {
        if(a[i][i] == 0.0) {
            printf("Mathematical Error!");
            return;
        }
        for(int j = 0; j < n; j++) {
            if(i != j) {
                ratio = a[j][i] / a[i][i];
                for(int k = 0; k < n + 1; k++) {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }
}

int main() {
    int n;
    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");
    
    printf("Input the number of data points: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("At least two data points are required.\n");
        return -1;
    }

    float x[n], y[n];
    float sxy = 0, sx = 0, sy = 0, sx2 = 0;

    // Input x values
    printf("Input the values of x:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    // Input y values
    printf("Input the values of y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &y[i]);
    }
    for (int i = 0; i < n; i++) 
    {
        sx += x[i];           
        sy += y[i];           
        sx2 += x[i] * x[i];   
        sxy += x[i] * y[i];   
    }

    float m[2][3];
    m[0][0] = n;            
    m[0][1] = sx;           
    m[0][2] = sy;           
    m[1][0] = sx;           
    m[1][1] = sx2;          
    m[1][2] = sxy;         
    printf("\nApply gauss jordan : \n");
    printf("Equation 1 : %0.2fa + %0.2fb = %0.2f\n",m[0][0],m[0][1],m[0][2]);
    printf("Equation 2 : %0.2fa + %0.2fb = %0.2f\n\n",m[1][0],m[1][1],m[1][2]);
    gaussJordan(m, 2);

    float b = m[1][2]/m[1][1];  
    float a = m[0][2]/m[0][0];
    printf("\nValue a : %.2f and b : %.2f\n", a, b);
    printf("Equation : y = %0.2fx + %0.2f\n",b,a);
    return 0;
}
