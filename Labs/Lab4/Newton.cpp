#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

double x, e1, e2;
int n;

double f(double x) { return cos(x) - x; }
double df(double x) { return -sin(x) - 1; }

int main() {
    scanf("%lf%lf%lf%d", &x, &e1, &e2, &n);
    for (int i = 1; i <= n; i++) {
        double F = f(x), DF = df(x);
        if (fabs(F) < e1) {
            printf("%lf", x);
            return 0;
        }
        if (fabs(DF) < e2) {
            printf("Failed");
            return 0;
        }
        double x1 = x - F / DF;
        double tol = fabs(x - x1);
        if (tol < e1) {
            printf("%lf", x1);
            return 0;
        }
        x = x1;
        printf("%lf, ", x1);
    }
    printf("Failed");
    return 0;
}