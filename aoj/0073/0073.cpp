#include <stdio.h>
#include <math.h>

int main() {
    for (;;) {
        double x, h;
        scanf("%lf%lf", &x, &h);
        if (x == 0 && h == 0) return 0;
        const double y = sqrt(x*x/4+h*h);
        printf("%.6f\n", x*x+2*x*y);
    }
}
