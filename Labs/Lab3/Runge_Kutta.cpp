#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int n;
double a, b, fa;

double f(double x, double y) { return -y * y; }
double f_(double x) { return 1.0 / (x + 1.0); }

int main() {
    scanf("%lf%lf%lf%d", &a, &b, &fa, &n);
    double x = a, y = fa, h = (b - a) / n;
    for (int i = 1; i <= n; i++) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h / 2, y + k2 / 2);
        double k4 = h * f(x + h, y + k3);
        x += h;
        y += 1.0 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
        printf("%.2lf\t%lf\t%.2lf\n", x, y, fabs(f_(x) - y));
    }
    return 0;
}