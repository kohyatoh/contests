#include <stdio.h>
#include <math.h>

const double pi = atan2(0.0, -1.0);

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        double D, d, s;
        scanf("%lf%lf%lf", &D, &d, &s);
        const double a = (D-d)/2, b = s+d;
        const double t = acos(1.0-b*b/(a*a)/2);
        printf("%d\n", (int)(2*pi/t));
    }
    return 0;
}
