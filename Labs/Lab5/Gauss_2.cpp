#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define N 4

int main() {
    static double a[N][N] = {{0.4096, 0.1234, 0.3678, 0.2943},
                             {0.2246, 0.3872, 0.4015, 0.1129},
                             {0.3645, 0.1920, 0.3781, 0.0643},
                             {0.1784, 0.4002, 0.2786, 0.3927}};
    double b[N] = {1.2951, 1.1262, 0.9989, 1.2499};
    double x[N] = {0, 0, 0};
    double r, s, e;
    int k, i, j, p, flag = 1;

    for (k = 0; k < N - 1; k++) {
        p = k;
        e = a[k][k];
        for (i = k; i < N; i++)
            if (fabs(a[i][k]) > e) {
                e = fabs(a[i][k]);
                p = i;
            }
        for (j = k; j < N; j++) {
            s = a[k][j];
            a[k][j] = a[p][j];
            a[p][j] = s;
        }
        s = b[k];
        b[k] = b[p];
        b[p] = s;
        if (a[k][k] == 0) {
            printf("Gauss-Method does not run!");
            flag = 0;
            break;
        } else {
            for (i = k + 1; i < N; i++) {
                r = a[i][k] / a[k][k];
                if (a[k][k] != 0) {
                    for (j = k; j < N; j++) a[i][j] = a[i][j] - r * a[k][j];
                }
                b[i] -= r * b[k];
            }
        }
    }

    if (flag) {
        x[N - 1] = b[N - 1] / a[N - 1][N - 1];
        for (i = N - 2; i >= 0; i--) {
            s = b[i];
            for (j = i + 1; j < N; j++) s -= a[i][j] * x[j];
            x[i] = s / a[i][i];
        }
        for (i = 0; i < N; i++) printf("%lf, ", x[i]);
    }
    return 0;
}