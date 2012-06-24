#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void print(double x, double y) {
    if (x == -0.0) x = 0;
    if (y == -0.0) y = 0;
    printf("%.3f %.3f\n", x, y);
}

int main() {
    double a, b, c, d, e, f;
    while (scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f) != EOF) {
        if (d == 0) {
            const double y = f / e;
            const double x = (c-b*y) / a;
            print(x, y);
        }
        else {
            const double y = (c-a*f/d) / (b-a*e/d);
            const double x = (f-e*y)/d;
            print(x, y);
        }
    }
    return 0;
}
