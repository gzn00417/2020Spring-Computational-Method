#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
#define N 10

int n;
double a[N][N], b[N], x[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) scanf("%lf", &a[i][j]);
    for (int i = 1; i <= n; i++) scanf("%lf", &b[i]);
    for (int k = 1; k < n; k++) {
        int p = k;
        double maxabs = fabs(a[k][k]);
        for (int j = k + 1; j <= n; j++)
            if (fabs(a[j][k]) - maxabs > 0) {
                p = j;
                maxabs = fabs(a[j][k]);
            }
        if (a[p][k] == 0) {
            printf("Singular");
            return 0;
        }
        if (p != k) {
            double tmp;
            for (int j = 1; j <= n; j++) {
                tmp = a[p][j];
                a[p][j] = a[k][j];
                a[k][j] = tmp;
            }
            tmp = b[p];
            b[p] = b[k];
            b[k] = tmp;
        }
        for (int i = k + 1; i <= n; i++) {
            double m_ik = a[i][k] / a[k][k];
            for (int j = k + 1; j <= n; j++) a[i][j] -= a[k][j] * m_ik;
            b[i] -= b[k] * m_ik;
        }
    }
    if (a[n][n] == 0) {
        printf("Singular");
        return 0;
    }
    x[n] = b[n] / a[n][n];
    for (int k = n - 1; k >= 1; k--) {
        double sigma = 0.0;
        for (int j = k + 1; j <= n; j++) sigma += a[k][j] * x[j];
        x[k] = (b[k] - sigma) / a[k][k];
    }
    for (int i = 1; i <= n; i++) printf("%lf\t", x[i]);
    return 0;
}