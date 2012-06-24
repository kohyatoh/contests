#include <stdio.h>
#include <complex>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef complex<double> P;

int f(P p1, double r1, P p2, double r2) {
    const double d = abs(p1-p2);
    if (r1+r2 < d) return 0;
    if (r2+d < r1) return 2;
    if (r1+d < r2) return -2;
    return 1;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        double x1, y1, r1, x2, y2, r2;
        scanf("%lf%lf%lf", &x1, &y1, &r1);
        scanf("%lf%lf%lf", &x2, &y2, &r2);
        P p1(x1, y1), p2(x2, y2);
        printf("%d\n", f(p1, r1, p2, r2));
    }
    return 0;
}
