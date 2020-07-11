#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
#define N 20

int n;
long double a, b, e, T[N][N] = {{0.0}};

long double f(long double x) { return 1.0 / (1.0 + x); }
long double x(int i, long double h) { return a + h * i; }

int main() {
    scanf("%llf%llf%llf%d", &a, &b, &e, &n);
    int k = 0;
    for (; k < n; k++) {
        long double h = (b - a) / pow(2, k), sum = 0.0;
        for (int i = 1; i <= pow(2, k) - 1; i++) sum += f(x(i, h));
        T[k][0] = 0.5 * h * (f(a) + 2 * sum + f(b));
        for (int m = 1; m <= k; m++)
            T[k][m] =
                (pow(4, m) * T[k][m - 1] - T[k - 1][m - 1]) / (pow(4, m) - 1);
        for (int m = 0; m <= k; m++) printf("%.7Lf\t", T[k][m]);
        cout << endl;
        if (k > 0 && fabs(T[k][0] - T[k][k]) <= e) break;
    }
    return 0;
}
