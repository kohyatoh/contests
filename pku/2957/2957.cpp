#include <stdio.h>
#include <math.h>
#include <iostream>
#include <complex>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef complex<double> P;
#define EPS (1e-12)

const double pi = atan2(0.0, -1.0);

inline double cross(const P& a, const P& b) { return imag(conj(a)*b); }

P crosspoint(const P& l0, const P& l1, const P& m0, const P& m1) {
    const double A = cross(l1-l0, m1-m0);
    const double B = cross(l1-l0, l1-m0);
    if(abs(A)<EPS && abs(B)<EPS) return m0;
    if(abs(A)<EPS) throw 0;
    return m0+B/A*(m1-m0);
}
inline P unit(double t) { return P(cos(t), sin(t)); }

double xs[3], ys[3];
P ps[3];

int main() {
    for(;;) {
        int T, k1, k2;
        scanf("%d%d%d", &T, &k1, &k2);
        if(T==0) return 0;
        rep(i, 3) scanf("%lf%lf", xs+i, ys+i);
        rep(i, 3) ps[i] = P(xs[i], ys[i]);
        ps[1] *= unit(-2*pi*k1/T);
        ps[2] *= unit(-2*pi*(k1+k2)/T);
        const P a(0.5*(ps[0]+ps[1])), b(0.5*(ps[1]+ps[2]));
        const P cp(crosspoint(a, a+(ps[0]-a)*P(0, 1), b, b+(ps[1]-b)*P(0, 1)));
        printf("%.0f\n", abs(cp));
    }
}
