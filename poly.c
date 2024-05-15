#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <complex.h>
#include <stdlib.h>
#define MAX 100

#define PI 3.141592653589793238462643383279502884197169399375105820974944

// Recursive function to perform FFT
void fft(complex double X[], int N, bool invert) {
    complex double A[N];
    int i,k;
    if (N == 1) {
        A[0] = X[0];
        X[0] = A[0];
    } else {
        complex double even[N/2];
        complex double odd[N/2];
        for(i = 0; i < N/2; i++) {
            even[i] = X[i*2];
            odd[i] = X[i*2+1];
        }
        fft(even, N/2, invert);
        fft(odd, N/2, invert);
        for (k = 0; k < N/2; k++) {
            complex double t = cexp(-2.0 * I * PI * k / N * (invert ? -1 : 1)) * odd[k];
            A[k] = even[k] + t;
            A[k + N/2] = even[k] - t;
            if (invert) {
                A[k] /= 2;
                A[k + N/2] /= 2;
            }
        }
        for (i = 0; i < N; i++) {
            X[i] = A[i];
        }
    }
}

// Function to multiply two polynomials using FFT
void multiply_polynomials(double A[], double B[], int n1, int n2) {
    int N = 1,i;
    while (N < (n1+n2-1)) N=N << 1;

    complex double fa[N];
    complex double fb[N];

    // Initialize arrays with polynomial coefficients
    for (i = 0; i < N; i++) {
        fa[i] = (i < n1) ? A[i] : 0;
        fb[i] = (i < n2) ? B[i] : 0;
    }

    // Perform FFT on both polynomials
    fft(fa, N, false);
    fft(fb, N, false);

    // Pointwise multiplication
    for (i = 0; i < N; i++) {
        fa[i] *= fb[i];
    }

    // Inverse FFT
    fft(fa, N, true);

    // Result
    printf("Result:\n");
    for (i = 0; i < n1+n2-1; i++) {
        printf("Coefficient of x^%d: %.0f\n", i, creal(fa[i])); // Printing with integer format
    }
}

int main() {
    int n1, i,n2;
    double A[MAX], B[MAX];

    printf("Enter the size of First polynomial : ");
    scanf("%d", &n1);
    for ( i = 0; i < n1; ++i) {
        printf("Enter coefficient of x^%d:", i);
        scanf("%lf", &A[i]);
    }

    printf("Enter the size of second polynomial : ");
    scanf("%d", &n2);
    for (i = 0; i < n2; ++i) {
        printf("Enter coefficient of x^%d:", i);
        scanf("%lf", &B[i]);
    }

    multiply_polynomials(A, B, n1, n2);

    return 0;
}

