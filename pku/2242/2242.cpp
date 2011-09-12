#include <stdio.h>
#include <complex>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

#define EPS (1e-9)
typedef complex<double> P;
double cross(const P& a, const P& b) { return imag(conj(a)*b); }
P crosspoint(const P& l0, const P& l1, const P& m0, const P& m1) {
    double A=cross(l1-l0, m1-m0), B=cross(l1-l0, l1-m0);
    if(fabs(A)<EPS && fabs(B)<EPS) return m0;
    //assert(fabs(A)>EPS);
    return m0+B/A*(m1-m0);
}
P rot90(const P& p) { return P(imag(p), -real(p)); }

const double PI=3.141592653589793;
double x[3], y[3];

int main() {
    while(scanf("%lf%lf%lf%lf%lf%lf", x, y, x+1, y+1, x+2, y+2)!=EOF) {
        P p0(x[0], y[0]), p1(x[1], y[1]), p2(x[2], y[2]);
        P m0(0.5*(p0+p1)), m1(0.5*(p1+p2));
        P c(crosspoint(m0, m0+rot90(p1-p0), m1, m1+rot90(p2-p1)));
        printf("%.2f\n", 2*PI*abs(c-p0));
    }
    return 0;
}

