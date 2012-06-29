#include <stdio.h>
#include <math.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    for (;;) {
        double q;
        scanf("%lf", &q);
        if (q == -1) return 0;
        double x = q/2;
        while (fabs(x*x*x-q) >= 0.00001*q) {
            x = x-(x*x*x-q)/(3*x*x);
        }
        printf("%.6f\n", x);
    }
}
