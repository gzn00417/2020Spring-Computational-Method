#include <cmath>
#include <cstdio>
#define N1 1   // n amount
#define N2 4   // x amount
#define N3 20  // n max

int Ns[N1] = {3};
double x[N2] = {5, 50, 115, 185};
double l = -1.0;
double r = 1.0;

double X(int k, int n) { return (k + 13) * (k + 13); }

double Y(double x) { return sqrt(x); }

int main() {
    for (int i = 0; i < N2; i++) printf("\tx=%.2lf", x[i]);
    printf("\n");
    for (int i = 0; i < N1; i++) {
        double a[N3 + 1], b[N3 + 1];
        int n = Ns[i];
        for (int k = 0; k <= n; k++) {
            a[k] = X(k, n);  // x
            b[k] = Y(a[k]);  // y
        }
        printf("n=%d", n);
        for (int p = 0; p < N2; p++) {
            double y = 0.0;
            for (int k = 0; k <= n; k++) {
                double l = 1.0;
                for (int j = 0; j <= n; j++) {
                    if (j != k) l *= (x[p] - a[j]) / (a[k] - a[j]);
                }
                y += l * b[k];
            }
            printf("\t%.6lf", y);
        }
        printf("\n");
    }
    printf("Actual");
    for (int p = 0; p < N2; p++) printf("\t%.6lf", Y(x[p]));
    return 0;
}