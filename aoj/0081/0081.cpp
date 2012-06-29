#include <stdio.h>
#include <math.h>
#include <complex>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef complex<double> P;

inline double dot(const P& a, const P& b) { return real(conj(a)*b); }
P projection(const P& l0, const P& l1, const P& p) {
    return l0 + dot(p-l0, l1-l0) / norm(l1-l0) * (l1-l0);
}

int main() {
    double x1, y1, x2, y2, xq, yq;
    while (scanf("%lf,%lf,%lf,%lf,%lf,%lf",
                &x1, &y1, &x2, &y2, &xq, &yq) != EOF) {
        const P q = P(xq, yq);
        const P m = projection(P(x1, y1), P(x2, y2), q);
        P r = q+2.0*(m-q);
        printf("%.6f %.6f\n", r.real(), r.imag());
    }
    return 0;
}
