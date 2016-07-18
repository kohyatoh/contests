#include <stdio.h>
#include <complex>
using namespace std;
typedef complex<double> P;

double cross(const P& a, const P& b) { return imag(conj(a)*b); }

int main() {
    int xa, ya, xb, yb, xc, yc;
    scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);
    P a(xa, ya), b(xb, yb), c(xc, yc);
    printf("%.9f\n", abs(cross(b - a, c - a)) / 2);
    return 0;
}
