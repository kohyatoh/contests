#include <stdio.h>
#include <complex>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef complex<double> P;

double cross(const P& a, const P& b) { return imag(conj(a)*b); }
P rot90(const P& p) { return p*P(0, 1); }
P crosspoint(const P& l0, const P& l1, const P& m0, const P& m1) {
    const double A = cross(l1-l0, m1-m0);
    const double B = cross(l1-l0, l1-m0);
    return m0 + B/A * (m1-m0);
}

P center(P a, P b, P c) {
    const P m1 = 0.5*(a+b), m2 = 0.5*(b+c);
    return crosspoint(m1, m1+rot90(b-a), m2, m2+rot90(c-b));
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        double x1, y1, x2, y2, x3, y3;
        scanf("%lf%lf", &x1, &y1);
        scanf("%lf%lf", &x2, &y2);
        scanf("%lf%lf", &x3, &y3);
        const P p = center(P(x1, y1), P(x2, y2), P(x3, y3));
        printf("%.3f %.3f %.3f\n", p.real(), p.imag(), abs(p-P(x1, y1)));
    }
    return 0;
}
