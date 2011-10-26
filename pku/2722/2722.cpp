#include <stdio.h>
#include <math.h>
#include <complex>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const double EPS=1e-8;
typedef complex<double> P;
double cross(const P& a, const P& b) { return imag(conj(a)*b); }
double dot(const P& a, const P& b) { return real(conj(a)*b); }
P crosspoint(const P& l0, const P& l1, const P& m0, const P& m1) {
    const double a = cross(l1-l0, m1-m0);
    const double b = cross(l1-l0, l1-m0);
    if(abs(a)<EPS && abs(b)<EPS) return m0; // same line
//    if(abs(a)<EPS) throw 0; // not crossing
    return m0 + b/a*(m1-m0);
}

const double sqrt2 = sqrt(2.0);
P pa, pb;

double f(double h) {
    const P base(h/sqrt2, h/sqrt2);
    const P ca(crosspoint(base, base+P(1, -1), P(0, 0), pa));
    const P cb(crosspoint(base, base+P(1, -1), P(0, 0), pb));
    return abs(ca-cb);
}

int main() {
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        double xa, ya, xb, yb;
        scanf("%lf%lf%lf%lf", &xa, &ya, &xb, &yb);
        pa = P(xa, ya);
        pb = P(xb, yb);
        double L = 0, dec = 0;
        rep(i, n) {
            double a;
            scanf("%lf", &a);
            L += a*sqrt2;
            dec += a*a/2;
        }
        double l=0, r=1000;
        while(f(r)<L) r*=2;
        rep(_, 100) {
            const double mid = (l+r)/2;
            if(f(mid)<L) l = mid;
            else r = mid;
        }
        printf("%.3f\n", L*r/2-dec);
    }
}
