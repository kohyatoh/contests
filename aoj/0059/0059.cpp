#include <stdio.h>

int main() {
    double xA, yA, xB, yB, xC, yC, xD, yD;
    while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf",
                &xA, &yA, &xB, &yB, &xC, &yC, &xD, &yD) != EOF) {
        bool f = true;
        if (xD < xA || xB < xC) f = false;
        if (yD < yA || yB < yC) f = false;
        puts(f ? "YES" : "NO");
    }
    return 0;
}
