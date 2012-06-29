#include <stdio.h>
#include <math.h>
#define EPS (1e-12)

int main() {
    double xA, yA, xB, yB, xC, yC, xD, yD;
    while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf",
                &xA, &yA, &xB, &yB, &xC, &yC, &xD, &yD) != EOF) {
        const double x1 = xB-xA, y1 = yB-yA;
        const double x2 = xD-xC, y2 = yD-yC;
        puts(fabs(x1*x2+y1*y2) < EPS ? "YES" : "NO");
    }
    return 0;
}

